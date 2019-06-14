#include "HttpResponseMessage.hpp"

Elysium::Communication::Service::Http::HttpResponseMessage::HttpResponseMessage(const HttpRequestMessage* Request)
	: _Request(Request)
{
}
Elysium::Communication::Service::Http::HttpResponseMessage::~HttpResponseMessage()
{
}

const Elysium::Communication::Service::Http::HttpRequestMessage * Elysium::Communication::Service::Http::HttpResponseMessage::GetRequest() const
{
	return _Request;
}
const Elysium::Core::Version & Elysium::Communication::Service::Http::HttpResponseMessage::GetVersion() const
{
	return _Version;
}
const Elysium::Communication::Service::Http::HttpStatusCode Elysium::Communication::Service::Http::HttpResponseMessage::GetStatusCode() const
{
	return _StatusCode;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::HttpResponseMessage::GetReasonPhase() const
{
	return _ReasonPhrase;
}
const Elysium::Communication::Service::Http::Headers::HttpResponseHeaders & Elysium::Communication::Service::Http::HttpResponseMessage::GetHeaders()const
{
	return _Headers;
}
