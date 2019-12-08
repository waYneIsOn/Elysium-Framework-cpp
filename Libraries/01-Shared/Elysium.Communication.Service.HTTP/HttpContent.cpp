#include "HttpContent.hpp"

Elysium::Communication::Service::Http::HttpContent::~HttpContent()
{
}

const Elysium::Communication::Service::Http::Headers::HttpContentHeaders & Elysium::Communication::Service::Http::HttpContent::GetHeaders() const
{
	return _Headers;
}

Elysium::Communication::Service::Http::HttpContent::HttpContent()
{
}
