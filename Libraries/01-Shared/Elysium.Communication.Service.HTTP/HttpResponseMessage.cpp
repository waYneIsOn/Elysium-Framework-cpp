#include "HttpResponseMessage.hpp"

using namespace Elysium::Core;

Elysium::Communication::Service::Http::HttpResponseMessage::HttpResponseMessage(HttpRequestMessage& Request)
	: _Request(Request), _Content(nullptr), _Version(1, 1), _Headers()
{
}
Elysium::Communication::Service::Http::HttpResponseMessage::HttpResponseMessage(const HttpResponseMessage & Source)
	: _Request(HttpRequestMessage(Source._Request)), 
	_Version(Version(Source._Version)),
	_StatusCode(HttpStatusCode(Source._StatusCode)),
	_ReasonPhrase(Source._ReasonPhrase), _Headers(Headers::HttpResponseHeaders(Source._Headers)), _Content(nullptr)
{
}
Elysium::Communication::Service::Http::HttpResponseMessage::HttpResponseMessage(HttpResponseMessage && Right) noexcept
	: _Request(Right._Request), _Content(nullptr), _Version(1, 1), _Headers()
{
	*this = std::move(Right);
}
Elysium::Communication::Service::Http::HttpResponseMessage::~HttpResponseMessage()
{
	if (_Content != nullptr)
	{
		delete _Content;
	}
}

Elysium::Communication::Service::Http::HttpResponseMessage & Elysium::Communication::Service::Http::HttpResponseMessage::operator=(const HttpResponseMessage & Source)
{
	if (this != &Source)
	{
		/*
		// release currently held objects
		if (_Content != nullptr)
		{
			delete _Content;
		}

		// grab Right's objects
		// ToDo: _Request, _Headers
		//_Request = std::move(Right._Request);
		_Version = std::move(Right._Version);
		_StatusCode = std::move(Right._StatusCode);
		_ReasonPhrase = std::move(Right._ReasonPhrase);
		_Headers = std::move(Right._Headers);
		_Content = std::move(Right._Content);

		// release Right's objects
		Right._Content = nullptr;
		*/
	}
	return *this;
}
Elysium::Communication::Service::Http::HttpResponseMessage & Elysium::Communication::Service::Http::HttpResponseMessage::operator=(HttpResponseMessage && Right) noexcept
{
	if (this != &Right)
	{
		// release currently held objects
		if (_Content != nullptr)
		{
			delete _Content;
		}

		// grab Right's objects
		_Request = std::move(Right._Request);
		_Version = std::move(Right._Version);
		_StatusCode = std::move(Right._StatusCode);
		_ReasonPhrase = std::move(Right._ReasonPhrase);
		_Headers = std::move(Right._Headers);
		_Content = std::move(Right._Content);

		// release Right's objects
		Right._Content = nullptr;
	}
	return *this;
}

const Elysium::Communication::Service::Http::HttpRequestMessage & Elysium::Communication::Service::Http::HttpResponseMessage::GetRequest() const
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
const Elysium::Core::Utf8String & Elysium::Communication::Service::Http::HttpResponseMessage::GetReasonPhase() const
{
	return _ReasonPhrase;
}
const Elysium::Communication::Service::Http::Headers::HttpResponseHeaders & Elysium::Communication::Service::Http::HttpResponseMessage::GetHeaders()const
{
	return _Headers;
}
const bool Elysium::Communication::Service::Http::HttpResponseMessage::GetIsSuccessStatusCode() const
{
	return _StatusCode == HttpStatusCode::OK || _StatusCode == HttpStatusCode::Created || _StatusCode == HttpStatusCode::Accepted ||
		_StatusCode == HttpStatusCode::NonAuthoritativeInformation || _StatusCode == HttpStatusCode::NoContent ||
		_StatusCode == HttpStatusCode::ResetContent || _StatusCode == HttpStatusCode::PartialContent;
}
const Elysium::Communication::Service::Http::HttpContent * Elysium::Communication::Service::Http::HttpResponseMessage::GetContent() const
{
	return _Content;
}
