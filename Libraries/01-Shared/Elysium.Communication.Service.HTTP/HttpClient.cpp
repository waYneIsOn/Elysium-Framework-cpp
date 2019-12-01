#include "HttpClient.hpp"

#ifndef ELYSIUM_CORE_CONVERT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#endif

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
	_OwnedClient(TcpClient(_OwnedSocket)), _OwnedProtocol(HyperTextTransferProtocol(_OwnedClient)),
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

Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Get(HttpRequestMessage & Request)
{
	SendRequest(Request);
	return ReceiveResponse(Request);
}

void Elysium::Communication::Service::Http::HttpClient::SendRequest(HttpRequestMessage & Request)
{
	_OwnedProtocol.WriteString(HttpMessageParser::ParseRequestMessage(Request));
	_Client->Flush();
}
Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::ReceiveResponse(HttpRequestMessage& Request)
{
	return ReceiveResponse(Request, HttpCompletionOption::ResponseContentRead);
}
Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::ReceiveResponse(HttpRequestMessage& Request, const HttpCompletionOption CompletionOption)
{
	// if we've only read the header before, we need to read the previous response's content
	if (_PreviousCompletionOption == HttpCompletionOption::ResponseHeadersRead)
	{
		ReceiveResponseContent(*_PreviousResponse);
	}

	// read and parse the header
	HttpResponseMessage Response = HttpMessageParser::ParseResponseMessageHeader(Request, _OwnedProtocol.ReadResponseHeader());

	// read and parse the content right away if so desired
	if (CompletionOption == HttpCompletionOption::ResponseContentRead)
	{
		ReceiveResponseContent(Response);
	}

	_PreviousResponse = &Response;
	_PreviousCompletionOption = CompletionOption;

	return Response;
}

void Elysium::Communication::Service::Http::HttpClient::ReceiveResponseContent(HttpResponseMessage & Response)
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

	if (Response.GetHeaders().Contains(u"Transfer-Encoding"))
	{
		if (Response.GetHeaders().GetValues(u"Transfer-Encoding")[0] == u"chunked")
		{
			bool HasReceivedBytes = false;
			Elysium::Core::Collections::Template::List<Elysium::Core::byte> Content;
			do
			{
				HasReceivedBytes = _OwnedProtocol.ReadResponseContentChunk(&Content);
			} while (HasReceivedBytes);

			// delete previous content if required
			if (Response._Content != nullptr)
			{
				delete Response._Content;
			}

			// add current content
			if (Response.GetHeaders().Contains(u"Content-Encoding"))
			{
				Response._Content = new ByteArrayContent(&Content[0], Content.GetCount());
			}
			else
			{	// ToDo: how to handle this case accordingly? html -> string, jpg -> bytearray etc.???
				Response._Content = new StringContent(&Content[0], Content.GetCount());
			}
		}
		else
		{
			String Test = String(Response.GetHeaders().GetValues(u"Transfer-Encoding")[0]);

			throw NotImplementedException(u"ReceiveResponseContent with unknown Transfer-Encoding");
		}
	}
	else if (Response.GetHeaders().Contains(u"Content-Length"))
	{
		// get the content's length
		const Elysium::Core::Collections::Template::List<Elysium::Core::String> ContentLengthValues = Response.GetHeaders().GetValues(u"Content-Length");
		size_t ContentLength = Elysium::Core::Convert::ToInt32(&ContentLengthValues[0][0], 10);

		if (ContentLength > 0)
		{
			// get the content
			// ToDo: depending on Content-Type (text/html, application/json etc.) we might need to handle this differently, for now it's ok
			Elysium::Core::Collections::Template::List<Elysium::Core::byte> Content;
			_OwnedProtocol.ReadResponseContent(ContentLength, &Content);
			if (Response._Content != nullptr)
			{
				delete Response._Content;
			}
			Response._Content = new StringContent(&Content[0], Content.GetCount());
		}
	}
	else
	{
		throw NotImplementedException(u"Header includes neither Content-Length nor Transfer-Encoding");
	}
}
