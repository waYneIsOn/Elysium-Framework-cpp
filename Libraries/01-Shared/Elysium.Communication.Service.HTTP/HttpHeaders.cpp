#include "HttpHeaders.hpp"

#ifndef ELYSIUM_CORE_EXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Exception.hpp"
#endif

Elysium::Communication::Service::Http::Headers::HttpHeaders::~HttpHeaders()
{ }

const std::map<Elysium::Core::Utf8String, Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>> & Elysium::Communication::Service::Http::Headers::HttpHeaders::GetInternalHeaders() const
{
	return _Headers;
}

void Elysium::Communication::Service::Http::Headers::HttpHeaders::Add(const Elysium::Core::Utf8String & Name, const Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>& Values)
{
	_Headers[Name] = Values;
}
void Elysium::Communication::Service::Http::Headers::HttpHeaders::Add(const Elysium::Core::Utf8String & Name, const Elysium::Core::Utf8String & Value)
{
	Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String> Values(1);
	Values[0] = Value;
	Add(Name, Values);
}
void Elysium::Communication::Service::Http::Headers::HttpHeaders::Clear()
{
	_Headers.clear();
}
bool Elysium::Communication::Service::Http::Headers::HttpHeaders::Contains(const char8_t* Name) const
{
	std::map<Elysium::Core::Utf8String, Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>>::const_iterator Iterator = _Headers.find(Name);
	if (Iterator == _Headers.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Elysium::Communication::Service::Http::Headers::HttpHeaders::Contains(const Elysium::Core::Utf8String & Name) const
{
	std::map<Elysium::Core::Utf8String, Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>>::const_iterator Iterator = _Headers.find(Name);
	if (Iterator == _Headers.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}
const Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>& Elysium::Communication::Service::Http::Headers::HttpHeaders::GetValues(const char8_t * Name) const
{
	std::map<Elysium::Core::Utf8String, Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>>::const_iterator Iterator = _Headers.find(Name);
	if (Iterator == _Headers.end())
	{	// ToDo: throw specific exception
		throw Elysium::Core::Exception(u8"header not found");
	}
	else
	{
		return Iterator->second;
	}
}
const Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>& Elysium::Communication::Service::Http::Headers::HttpHeaders::GetValues(const Elysium::Core::Utf8String & Name) const
{
	std::map<Elysium::Core::Utf8String, Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>>::const_iterator Iterator = _Headers.find(Name);
	if (Iterator == _Headers.end())
	{	// ToDo: throw specific exception
		throw Elysium::Core::Exception(u8"header not found");
	}
	else
	{
		return Iterator->second;
	}
}
bool Elysium::Communication::Service::Http::Headers::HttpHeaders::Remove(const Elysium::Core::Utf8String & Name)
{
	std::map<Elysium::Core::Utf8String, Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>>::iterator Iterator = _Headers.find(Name);
	if (Iterator == _Headers.end())
	{	
		return false;
	}
	else
	{
		_Headers.erase(Iterator);
		return true;
	}
}

Elysium::Communication::Service::Http::Headers::HttpHeaders::HttpHeaders()
	: _Headers()
{
}
Elysium::Communication::Service::Http::Headers::HttpHeaders::HttpHeaders(const HttpHeaders & Source)
	: _Headers()
{
	for (auto& Header : Source._Headers)
	{
		_Headers.insert(std::move(Header));
	}
}
Elysium::Communication::Service::Http::Headers::HttpHeaders::HttpHeaders(HttpHeaders && Right) noexcept
	: _Headers()
{
	*this = std::move(Right);
}

Elysium::Communication::Service::Http::Headers::HttpHeaders & Elysium::Communication::Service::Http::Headers::HttpHeaders::operator=(const HttpHeaders & Source)
{
	if (this != &Source)
	{
		for (auto& Header : Source._Headers)
		{
			_Headers.insert(std::move(Header));
		}
	}
	return *this;
}
Elysium::Communication::Service::Http::Headers::HttpHeaders & Elysium::Communication::Service::Http::Headers::HttpHeaders::operator=(HttpHeaders && Right) noexcept
{
	if (this != &Right)
	{
		// grab Right's objects
		/*
		for (auto& Header : Right._Headers)
		{
			_Headers.insert(std::move(Header));
		}
		*/
		_Headers = std::move(Right._Headers);
		//_Headers.merge(Right._Headers);
		//_Headers = std::map<Elysium::Core::Utf8String, Elysium::Core::Collections::Generic::List<Elysium::Core::Utf8String>>(Right._Headers);

		// release Right's objects
		//Right._Headers.clear();
	}
	return *this;
}
