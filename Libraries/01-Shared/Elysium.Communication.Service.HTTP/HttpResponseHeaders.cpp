#include "HttpResponseHeaders.hpp"

Elysium::Communication::Service::Http::Headers::HttpResponseHeaders::HttpResponseHeaders()
	: HttpHeaders()
{
}
Elysium::Communication::Service::Http::Headers::HttpResponseHeaders::HttpResponseHeaders(const HttpResponseHeaders & Source)
	: HttpHeaders(Source)
{
}
Elysium::Communication::Service::Http::Headers::HttpResponseHeaders::HttpResponseHeaders(HttpResponseHeaders && Right) noexcept
	: HttpHeaders(Right)
{
	*this = std::move(Right);
}
Elysium::Communication::Service::Http::Headers::HttpResponseHeaders::~HttpResponseHeaders()
{
}

Elysium::Communication::Service::Http::Headers::HttpResponseHeaders & Elysium::Communication::Service::Http::Headers::HttpResponseHeaders::operator=(const HttpResponseHeaders & Source)
{
	HttpHeaders::operator=(Source);
	return *this;
}
Elysium::Communication::Service::Http::Headers::HttpResponseHeaders & Elysium::Communication::Service::Http::Headers::HttpResponseHeaders::operator=(HttpResponseHeaders && Right) noexcept
{
	HttpHeaders::operator=(std::move(Right));
	return *this;
}
