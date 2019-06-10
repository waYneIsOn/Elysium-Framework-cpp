#include "HttpResponseMessage.hpp"

Elysium::Communication::Service::Http::HttpResponseMessage::HttpResponseMessage(const HttpRequestMessage* Request)
	: _Request(Request)
{
}
Elysium::Communication::Service::Http::HttpResponseMessage::~HttpResponseMessage()
{
}
