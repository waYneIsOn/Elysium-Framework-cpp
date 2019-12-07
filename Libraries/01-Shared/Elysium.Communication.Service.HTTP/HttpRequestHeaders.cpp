#include "HttpRequestHeaders.hpp"

Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::HttpRequestHeaders()
	: HttpHeaders(),
	_Authorization(Elysium::Core::String())
{
}
Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::HttpRequestHeaders(const HttpRequestHeaders & Source)
	: //HttpHeaders(Source),
	_Authorization(Elysium::Core::String())
{
}
Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::HttpRequestHeaders(HttpRequestHeaders && Right) noexcept
	: //HttpHeaders(Right),
	_Authorization(Elysium::Core::String())
{
	*this = std::move(Right);
}
Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::~HttpRequestHeaders()
{
}

Elysium::Communication::Service::Http::Headers::HttpRequestHeaders & Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::operator=(const HttpRequestHeaders & Source)
{
	HttpHeaders::operator=(Source);
	return *this;
}
Elysium::Communication::Service::Http::Headers::HttpRequestHeaders & Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::operator=(HttpRequestHeaders && Right) noexcept
{
	HttpHeaders::operator=(std::move(Right));
	return *this;
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
	_Authorization.SetScheme(Value.GetScheme());
	_Authorization.SetParameter(Value.GetParameter());
}
void Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::SetFrom(const Elysium::Core::String & Value)
{
	_From = Value;
}
void Elysium::Communication::Service::Http::Headers::HttpRequestHeaders::SetHost(const Elysium::Core::String & Value)
{
	_Host = Value;
}
