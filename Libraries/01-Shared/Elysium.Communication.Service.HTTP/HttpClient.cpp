#include "HttpClient.hpp"

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPMESSAGEPARSER
#include "HttpMessageParser.hpp"
#endif

#ifndef ELYSIUM_CORE_ARGUMENTNULLEXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/ArgumentNullException.hpp"
#endif

using namespace Elysium::Communication::Protocol;
using namespace Elysium::Communication::Transport;
using namespace Elysium::Core;
using namespace Elysium::Core::Net;
using namespace Elysium::Core::Net::Sockets;

Elysium::Communication::Service::Http::HttpClient::HttpClient()
	: _OwnedSocket(Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp)),
	_OwnedClient(TcpClient(&_OwnedSocket)), _OwnedProtocol(TextProtocol(&_OwnedClient)),
	_Socket(&_OwnedSocket), _Client(&_OwnedClient), _Protocol(&_OwnedProtocol)
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
	_Protocol->WriteString(&RequestMessage);
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

	// read and parse the header
	String ResponseMessageHeader;
	_Protocol->ReadString(&ResponseMessageHeader);
	HttpMessageParser::ParseResponseMessageHeader(this, &ResponseMessageHeader, Response);

	// read and parse the content
	// options:
	//  - Content-Length
	//	- Transfer-Encoding: Chunked -> ToDo
	//String ResponseMessageContent;
	//_Protocol->ReadString(&ResponseMessageContent);
	
	int x = 34;
}
