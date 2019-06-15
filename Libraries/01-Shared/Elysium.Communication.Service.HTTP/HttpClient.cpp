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
{
	_Socket->Connect(Uri.GetHost(), 80);
}
void Elysium::Communication::Service::Http::HttpClient::Disconnect()
{
	_Socket->Shutdown(SocketShutdown::Both);
	_Socket->Disconnect(true);
}

void Elysium::Communication::Service::Http::HttpClient::SendRequest(const HttpRequestMessage * Request)
{
	// prepare the message-string
	String RequestMessage;
	HttpMessageParser::ParseRequestMessage(this, Request, &RequestMessage);

	// send the message-string
	_OwnedProtocol.WriteString(&RequestMessage);
	_Client->Flush();
}
void Elysium::Communication::Service::Http::HttpClient::ReceiveResponse(HttpResponseMessage * Output)
{
	ReceiveResponse(HttpCompletionOption::ResponseContentRead, Output);
}
void Elysium::Communication::Service::Http::HttpClient::ReceiveResponse(const HttpCompletionOption CompletionOption, HttpResponseMessage * Response)
{
	if (Response == nullptr)
	{
		throw ArgumentNullException(L"Response");
	}

	// if we've only read the header before, we need to read the previous response's content
	if (_PreviousCompletionOption == HttpCompletionOption::ResponseHeadersRead)
	{
		ReceiveResponseContent(_PreviousResponse);
	}

	// read and parse the header
	String ResponseMessageHeader;
	_OwnedProtocol.ReadResponseHeader(&ResponseMessageHeader);
	HttpMessageParser::ParseResponseMessageHeader(this, &ResponseMessageHeader, Response);

	// read and parse the content right away if so desired
	if (CompletionOption == HttpCompletionOption::ResponseContentRead)
	{
		ReceiveResponseContent(Response);
	}
	
	_PreviousResponse = Response;
	_PreviousCompletionOption = CompletionOption;
}

void Elysium::Communication::Service::Http::HttpClient::ReceiveResponseContent(HttpResponseMessage * Response)
{
	if (Response->GetHeaders().Contains(L"Transfer-Encoding"))
	{
		throw NotImplementedException(L"ReceiveResponseContent with Transfer-Encoding");
	}
	else if (Response->GetHeaders().Contains(L"Content-Length") && Response->GetHeaders().Contains(L"Content-Type"))
	{
		if (Response->GetHeaders().GetValues(L"Content-Type")[0] == L"text/html")
		{
			int sdf = 45;
		}

		const Elysium::Core::Collections::Generic::List<Elysium::Core::String> ContentLengthValues = Response->GetHeaders().GetValues(L"Content-Length");
		size_t ContentLength = wcstoul(&ContentLengthValues[0][0], nullptr, 10);

		String ResponseMessageContent;
		_OwnedProtocol.ReadResponseContent(ContentLength, &ResponseMessageContent);
		StringContent Content = StringContent(ResponseMessageContent);

		int x = 435;
	}
	else
	{
		throw NotImplementedException(L"Header includes neither Content-Length nor Transfer-Encoding");
	}

	//HttpMessageParser::Parse

	// options:
	//  - Content-Length
	//	- Transfer-Encoding: Chunked -> ToDo
	//String ResponseMessageContent;
	//_Protocol->ReadString(&ResponseMessageContent);
}
