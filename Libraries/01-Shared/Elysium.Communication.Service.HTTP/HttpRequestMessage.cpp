#include "HttpRequestMessage.hpp"

Elysium::Communication::Service::Http::HttpRequestMessage::HttpRequestMessage(const HttpMethod& Method, const Elysium::Core::Uri & RequestUri)
	: _Method(Method), _RequestUri(RequestUri), _Version(1, 1), _Content(nullptr)
{
}
Elysium::Communication::Service::Http::HttpRequestMessage::HttpRequestMessage(const HttpRequestMessage & Source)
	: _Method(Source._Method), _RequestUri(Source._RequestUri), _Version(Elysium::Core::Version(Source._Version)), _Content(nullptr)
{
}
Elysium::Communication::Service::Http::HttpRequestMessage::HttpRequestMessage(HttpRequestMessage && Right)
	: _Method(Right._Method), _RequestUri(Right._RequestUri), _Content(nullptr)
{
	*this = std::move(Right);
}
Elysium::Communication::Service::Http::HttpRequestMessage::~HttpRequestMessage()
{
}

Elysium::Communication::Service::Http::HttpRequestMessage & Elysium::Communication::Service::Http::HttpRequestMessage::operator=(const HttpRequestMessage & Source)
{
	// ToDo: copy values
	return *this;
}
Elysium::Communication::Service::Http::HttpRequestMessage & Elysium::Communication::Service::Http::HttpRequestMessage::operator=(HttpRequestMessage && Right)
{
	if (this != &Right)
	{
		// release currently held objects
		if (_Content != nullptr)
		{
			delete _Content;
		}
		
		// grab Right's objects
		_Headers = std::move(Right._Headers);
		_Method = std::move(Right._Method);
		_Properties = std::move(Right._Properties);
		_RequestUri = std::move(Right._RequestUri);
		_Version = std::move(Right._Version);
		_Content = std::move(Right._Content);
		
		// release Right's objects
		Right._Content = nullptr;
	}
	return *this;
}

Elysium::Communication::Service::Http::Headers::HttpRequestHeaders & Elysium::Communication::Service::Http::HttpRequestMessage::GetHeaders()
{
	return _Headers;
}

const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpRequestMessage::GetMethod() const
{
	return _Method;
}
const Elysium::Core::Uri & Elysium::Communication::Service::Http::HttpRequestMessage::GetRequestUri() const
{
	return _RequestUri;
}
const Elysium::Core::Version & Elysium::Communication::Service::Http::HttpRequestMessage::GetVersion() const
{
	return _Version;
}
