#include "HttpClient.hpp"

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPMESSAGEPARSER
#include "HttpMessageParser.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_STRINGCONTENT
#include "StringContent.hpp"
#endif

#ifndef ELYSIUM_CORE_ARGUMENTNULLEXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/ArgumentNullException.hpp"
#endif

#ifndef ELYSIUM_CORE_NOTIMPLEMENTEDEXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/NotImplementedException.hpp"
#endif

using namespace Elysium::Communication::Protocol;
using namespace Elysium::Communication::Transport;
using namespace Elysium::Core;
using namespace Elysium::Core::Net;
using namespace Elysium::Core::Net::Sockets;

Elysium::Communication::Service::Http::HttpClient::HttpClient()
	: _OwnedSocket(Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp)),
	_OwnedClient(TcpClient(&_OwnedSocket)), _OwnedProtocol(HyperTextTransferProtocol(&_OwnedClient)),
	_Socket(&_OwnedSocket), _Client(&_OwnedClient),
	_PreviousCompletionOption(HttpCompletionOption::ResponseContentRead)
{
}
Elysium::Communication::Service::Http::HttpClient::~HttpClient()
{
}

void Elysium::Communication::Service::Http::HttpClient::Connect(const Elysium::Core::Uri & Uri)
{	// ToDo: Uri.GetPort();
	_Socket->Connect(Uri.GetHost(), 80);
}
void Elysium::Communication::Service::Http::HttpClient::Disconnect()
{
	_Socket->Shutdown(SocketShutdown::Both);
	_Socket->Disconnect(true);
}

void Elysium::Communication::Service::Http::HttpClient::SendRequest(const HttpRequestMessage & Request)
{
	// prepare the message-string
	String RequestMessage;
	HttpMessageParser::ParseRequestMessage(this, Request, &RequestMessage);

	// send the message-string
	_OwnedProtocol.WriteString(&RequestMessage);
	_Client->Flush();
}
void Elysium::Communication::Service::Http::HttpClient::ReceiveResponse(HttpResponseMessage & Output)
{
	ReceiveResponse(HttpCompletionOption::ResponseContentRead, Output);
}
void Elysium::Communication::Service::Http::HttpClient::ReceiveResponse(const HttpCompletionOption CompletionOption, HttpResponseMessage & Output)
{
	// if we've only read the header before, we need to read the previous response's content
	if (_PreviousCompletionOption == HttpCompletionOption::ResponseHeadersRead)
	{
		ReceiveResponseContent(_PreviousResponse);
	}

	// read and parse the header
	String ResponseMessageHeader;
	_OwnedProtocol.ReadResponseHeader(&ResponseMessageHeader);
	HttpMessageParser::ParseResponseMessageHeader(this, &ResponseMessageHeader, &Output);

	// read and parse the content right away if so desired
	if (CompletionOption == HttpCompletionOption::ResponseContentRead)
	{
		ReceiveResponseContent(&Output);
	}
	
	_PreviousResponse = &Output;
	_PreviousCompletionOption = CompletionOption;
}

void Elysium::Communication::Service::Http::HttpClient::ReceiveResponseContent(HttpResponseMessage * Response)
{
	// Content-Type
	// application/...
	// audio/...
	// image/...
	// message/...
	// multipart/...
	// text/...
	// video/...
	// x-token/...	(x-abc/... x-xyz/...) = non standard status

	// ap, au, im, me, mu, te, vi, x-

	if (Response->GetHeaders().Contains(L"Transfer-Encoding"))
	{
		if (Response->GetHeaders().GetValues(L"Transfer-Encoding")[0] == L"chunked")
		{
			bool HasReceivedBytes = false;
			Elysium::Core::Collections::Generic::List<Elysium::Core::byte> Content;
			do
			{
				HasReceivedBytes = _OwnedProtocol.ReadResponseContentChunk(&Content);
			} while (HasReceivedBytes);

			// delete previous content if required
			if (Response->_Content != nullptr)
			{
				delete Response->_Content;
			}

			// add current content
			if (Response->GetHeaders().Contains(L"Content-Encoding"))
			{
				Response->_Content = new ByteArrayContent(&Content[0], Content.GetCount());
			}
			else
			{	// how to handle this case? html -> string, jpg -> bytearray etc.???
				throw NotImplementedException(L"ReceiveResponseContent without Content-Encoding");
			}
		}
		else
		{
			throw NotImplementedException(L"ReceiveResponseContent with unknown Transfer-Encoding");
		}
	}
	else if (Response->GetHeaders().Contains(L"Content-Length"))
	{
		// get the content's length
		const Elysium::Core::Collections::Generic::List<Elysium::Core::String> ContentLengthValues = Response->GetHeaders().GetValues(L"Content-Length");
		size_t ContentLength = wcstoul(&ContentLengthValues[0][0], nullptr, 10);

		// get the content
		// ToDo: depending on Content-Type (text/html, application/json etc.) we might need to handle this differently, for now it's ok
		Elysium::Core::Collections::Generic::List<Elysium::Core::byte> Content;
		_OwnedProtocol.ReadResponseContent(ContentLength, &Content);
		if (Response->_Content != nullptr)
		{
			delete Response->_Content;
		}
		Response->_Content = new StringContent(&Content[0], Content.GetCount());
	}
	else
	{
		throw NotImplementedException(L"Header includes neither Content-Length nor Transfer-Encoding");
	}
}
