#include "HttpContentHeaders.hpp"

#ifndef ELYSIUM_CORE_CONVERT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#endif

Elysium::Communication::Service::Http::Headers::HttpContentHeaders::HttpContentHeaders()
{ }
Elysium::Communication::Service::Http::Headers::HttpContentHeaders::~HttpContentHeaders()
{ }

const int64_t Elysium::Communication::Service::Http::Headers::HttpContentHeaders::GetContentLength() const
{
	std::map<Elysium::Core::String, Elysium::Core::Collections::Template::List<Elysium::Core::String>>::const_iterator Iterator = _Headers.find(u8"Content-Length");
	if (Iterator == _Headers.end())
	{	
		return -1;
	}
	else
	{
		//return Iterator->second;
		return int64_t();
	}
}

void Elysium::Communication::Service::Http::Headers::HttpContentHeaders::SetContentLength(const int64_t Value)
{
	Elysium::Core::Collections::Template::List<Elysium::Core::String> Values(1);
	Values[0] = Elysium::Core::Convert::ToString(Value, 10);
	_Headers[u8"Content-Length"] = Values;
}
