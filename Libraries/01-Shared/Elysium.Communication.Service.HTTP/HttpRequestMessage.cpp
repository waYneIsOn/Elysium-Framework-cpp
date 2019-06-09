#include "HttpRequestMessage.hpp"

Elysium::Communication::Service::Http::HttpRequestMessage::HttpRequestMessage(const HttpMethod& Method, const Elysium::Core::Uri& RequestUri)
	:
	_Method (Method),
	_RequestUri(RequestUri),
	_Version(1, 1)
{
}
Elysium::Communication::Service::Http::HttpRequestMessage::~HttpRequestMessage()
{
}

const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpRequestMessage::GetMethod() const
{
	return _Method;
}
const Elysium::Core::Version & Elysium::Communication::Service::Http::HttpRequestMessage::GetVersion() const
{
	return _Version;
}
