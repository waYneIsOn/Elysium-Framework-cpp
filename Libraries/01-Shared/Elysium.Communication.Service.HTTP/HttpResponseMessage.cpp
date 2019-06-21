#include "HttpResponseMessage.hpp"

Elysium::Communication::Service::Http::HttpResponseMessage::HttpResponseMessage(const HttpRequestMessage* Request)
	: _Request(Request),
	_Content(nullptr)
{
}
Elysium::Communication::Service::Http::HttpResponseMessage::~HttpResponseMessage()
{
	if (_Content != nullptr)
	{
		delete _Content;
	}
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
