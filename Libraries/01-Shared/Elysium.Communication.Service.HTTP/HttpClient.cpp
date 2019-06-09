#include "HttpClient.hpp"

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPMESSAGEPARSER
#include "HttpMessageParser.hpp"
#endif

Elysium::Communication::Service::Http::HttpClient::HttpClient(const Elysium::Core::Uri& Uri)
{
}
Elysium::Communication::Service::Http::HttpClient::~HttpClient()
{
}

void Elysium::Communication::Service::Http::HttpClient::SendRequest(const HttpRequestMessage & Request)
{
	Elysium::Core::String RequestMessage;
	HttpMessageParser::ParseRequestMessage(*this, Request, &RequestMessage);
}
