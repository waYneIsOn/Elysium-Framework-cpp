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

#ifndef ELYSIUM_CORE_NET_DNSENDPOINT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/DnsEndPoint.hpp"
#endif

#ifndef ELYSIUM_CORE_ARGUMENTNULLEXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/ArgumentNullException.hpp"
#endif

#ifndef ELYSIUM_CORE_INVALIDOPERATIONEXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/InvalidOperationException.hpp"
#endif

#ifndef ELYSIUM_CORE_NOTIMPLEMENTEDEXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/NotImplementedException.hpp"
#endif

using namespace Elysium::Communication::Protocol::ApplicationLayer;
using namespace Elysium::Communication::Transport;
using namespace Elysium::Core;
using namespace Elysium::Core::Net;
using namespace Elysium::Core::Net::Sockets;

Elysium::Communication::Service::Http::HttpClient::HttpClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion)
	: _OwnedClient(TcpClient(IPVersion)), _OwnedProtocol(HyperTextTransferProtocol(_OwnedClient)),
	_DefaultRequestHeaders(Headers::HttpRequestHeaders()),
	_BaseAddress(Elysium::Core::Uri(String())),
	_PreviousCompletionOption(HttpCompletionOption::ResponseContentRead)
{ }
Elysium::Communication::Service::Http::HttpClient::~HttpClient()
{ }

Elysium::Communication::Service::Http::Headers::HttpRequestHeaders & Elysium::Communication::Service::Http::HttpClient::GetDefaultRequestHeaders()
{
	return _DefaultRequestHeaders;
}

void Elysium::Communication::Service::Http::HttpClient::SetBaseAddress(const Elysium::Core::Uri & BaseAddress)
{
	_BaseAddress = BaseAddress;
}

void Elysium::Communication::Service::Http::HttpClient::Connect()
{
	// ToDo: _BaseAddress.GetPort()
	const Elysium::Core::String Host = _BaseAddress.GetHost();
	const Elysium::Core::Net::DnsEndPoint RemoteEndPoint = Elysium::Core::Net::DnsEndPoint(_BaseAddress.GetHost(), 80,
		Net::Sockets::AddressFamily::InterNetwork);
	_OwnedClient.Connect(RemoteEndPoint);
}
void Elysium::Communication::Service::Http::HttpClient::Disconnect()
{
	_OwnedClient.Close();
}

Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Delete(const Elysium::Core::String & Path, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Delete(), Elysium::Core::Uri(_BaseAddress, Path));
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption);
}
Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Delete(const Elysium::Core::String & Path, HttpResponseMessage & PreviousResponse, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Delete(), Elysium::Core::Uri(_BaseAddress, Path));
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption, PreviousResponse);
}

Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Get(const Elysium::Core::String & Path, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Get(), Elysium::Core::Uri(_BaseAddress, Path));
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption);
}
Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Get(const Elysium::Core::String & Path, HttpResponseMessage & PreviousResponse, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Get(), Elysium::Core::Uri(_BaseAddress, Path));
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption, PreviousResponse);
}

Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Options(const Elysium::Core::String & Path, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Options(), Elysium::Core::Uri(_BaseAddress, Path));
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption);
}
Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Options(const Elysium::Core::String & Path, HttpResponseMessage & PreviousResponse, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Options(), Elysium::Core::Uri(_BaseAddress, Path));
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption, PreviousResponse);
}

Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Patch(const Elysium::Core::String & Path, const HttpContent & Content, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Patch(), Elysium::Core::Uri(_BaseAddress, Path), &Content);
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption);
}
Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Patch(const Elysium::Core::String & Path, const HttpContent & Content, HttpResponseMessage & PreviousResponse, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Patch(), Elysium::Core::Uri(_BaseAddress, Path), &Content);
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption, PreviousResponse);
}

Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Post(const Elysium::Core::String & Path, const HttpContent & Content, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Post(), Elysium::Core::Uri(_BaseAddress, Path), &Content);
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption);
}
Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Post(const Elysium::Core::String & Path, const HttpContent & Content, HttpResponseMessage & PreviousResponse, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Post(), Elysium::Core::Uri(_BaseAddress, Path), &Content);
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption, PreviousResponse);
}

Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Put(const Elysium::Core::String & Path, const HttpContent & Content, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Put(), Elysium::Core::Uri(_BaseAddress, Path), &Content);
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption);
}
Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::Put(const Elysium::Core::String & Path, const HttpContent & Content, HttpResponseMessage & PreviousResponse, const HttpCompletionOption CompletionOption)
{
	HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Put(), Elysium::Core::Uri(_BaseAddress, Path), &Content);
	Request.GetHeaders().SetAuthorization(_DefaultRequestHeaders.GetAuthorization());
	SendRequest(Request);
	return ReceiveResponse(Request, CompletionOption, PreviousResponse);
}

void Elysium::Communication::Service::Http::HttpClient::SendRequest(HttpRequestMessage & Request)
{
	_OwnedProtocol.WriteString(HttpMessageParser::ParseRequestMessage(Request));
	_OwnedClient.Flush();
}
Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::ReceiveResponse(HttpRequestMessage & Request, const HttpCompletionOption CompletionOption)
{
	if (_PreviousCompletionOption == HttpCompletionOption::ResponseHeadersRead)
	{
		throw InvalidOperationException();
	}
	_PreviousCompletionOption = CompletionOption;
	HttpResponseMessage Response = HttpMessageParser::ParseResponseMessageHeader(Request, _OwnedProtocol.ReadResponseHeader());
	if (CompletionOption == HttpCompletionOption::ResponseContentRead)
	{
		ReceiveResponseContent(Response);
	}
	return Response;
}
Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpClient::ReceiveResponse(HttpRequestMessage & Request, const HttpCompletionOption CompletionOption, HttpResponseMessage & PreviousResponse)
{
	if (_PreviousCompletionOption == HttpCompletionOption::ResponseHeadersRead)
	{
		ReceiveResponseContent(PreviousResponse);
	}
	_PreviousCompletionOption = CompletionOption;
	HttpResponseMessage Response = HttpMessageParser::ParseResponseMessageHeader(Request, _OwnedProtocol.ReadResponseHeader());
	if (CompletionOption == HttpCompletionOption::ResponseContentRead)
	{
		ReceiveResponseContent(Response);
	}
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

	const Elysium::Communication::Service::Http::Headers::HttpResponseHeaders& ResponseHeaders = Response.GetHeaders();
	if (ResponseHeaders.Contains("Transfer-Encoding"))
	{
		if (ResponseHeaders.GetValues("Transfer-Encoding")[0] == u8"chunked")
		{
			bool HasReceivedBytes = false;
			Elysium::Core::Collections::Template::List<Elysium::Core::byte> Content;
			do
			{
				HasReceivedBytes = _OwnedProtocol.ReadResponseContentChunk(Content);
			} while (HasReceivedBytes);

			// delete previous content if required
			if (Response._Content != nullptr)
			{
				delete Response._Content;
			}

			// add current content
			if (ResponseHeaders.Contains("Content-Encoding"))
			{
				Response._Content = new ByteArrayContent(Content);
			}
			else
			{	// ToDo: how to handle this case accordingly? html -> string, jpg -> bytearray etc.???
				Response._Content = new StringContent(Elysium::Core::Text::Encoding::Default().GetString(&Content[0], Content.GetCount()));
			}
		}
		else
		{
			String Test = String(ResponseHeaders.GetValues("Transfer-Encoding")[0]);

			throw NotImplementedException("ReceiveResponseContent with unknown Transfer-Encoding");
		}
	}
	else if (ResponseHeaders.Contains("Content-Length"))
	{
		// get the content's length
		const Elysium::Core::Collections::Template::List<Elysium::Core::String> ContentLengthValues = ResponseHeaders.GetValues(u8"Content-Length");
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
			Response._Content = new StringContent(Elysium::Core::Text::Encoding::Default().GetString(&Content[0], Content.GetCount()));
		}
	}
	else
	{
		throw NotImplementedException("Header includes neither Content-Length, Content-Type nor Transfer-Encoding");
	}
}
