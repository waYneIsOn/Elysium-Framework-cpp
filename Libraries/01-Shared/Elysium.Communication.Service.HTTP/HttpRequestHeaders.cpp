#include "HttpRequestHeaders.hpp"

Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::HttpRequestHeaders()
	: HttpHeaders()
{
}
Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::~HttpRequestHeaders()
{
}

const Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue & Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::GetAuthorization() const
{
	return _Authorization;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::GetFrom() const
{
	return _From;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::GetHost() const
{
	return _Host;
}

void Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::SetAuthorization(const AuthenticationHeaderValue & Value)
{
	_Authorization = Value;
}
void Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::SetFrom(const Elysium::Core::String & Value)
{
	_From = Value;
}
void Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::SetHost(const Elysium::Core::String & Value)
{
	_Host = Value;
}
