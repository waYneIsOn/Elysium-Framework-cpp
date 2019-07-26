#include "HttpHeaders.hpp"

#ifndef ELYSIUM_CORE_EXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Exception.hpp"
#endif

Elysium::Communication::Service::Http::Headers::HttpHeaders::~HttpHeaders()
{
}

void Elysium::Communication::Service::Http::Headers::HttpHeaders::Add(const Elysium::Core::String & Name, const Elysium::Core::Collections::Generic::List<Elysium::Core::String>& Values)
{
	_Headers[Name] = Values;
}
void Elysium::Communication::Service::Http::Headers::HttpHeaders::Add(const Elysium::Core::String & Name, const Elysium::Core::String & Value)
{
	Elysium::Core::Collections::Generic::List<Elysium::Core::String> Values(1);
	Values[0] = Value;
	Add(Name, Values);
}
void Elysium::Communication::Service::Http::Headers::HttpHeaders::Clear()
{
	_Headers.clear();
}
bool Elysium::Communication::Service::Http::Headers::HttpHeaders::Contains(const ElysiumChar * Name) const
{
	std::map<Elysium::Core::String, Elysium::Core::Collections::Generic::List<Elysium::Core::String>>::const_iterator Iterator = _Headers.find(Name);
	if (Iterator == _Headers.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Elysium::Communication::Service::Http::Headers::HttpHeaders::Contains(const Elysium::Core::String & Name) const
{
	std::map<Elysium::Core::String, Elysium::Core::Collections::Generic::List<Elysium::Core::String>>::const_iterator Iterator = _Headers.find(Name);
	if (Iterator == _Headers.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}
const Elysium::Core::Collections::Generic::List<Elysium::Core::String>& Elysium::Communication::Service::Http::Headers::HttpHeaders::GetValues(const ElysiumChar * Name) const
{
	std::map<Elysium::Core::String, Elysium::Core::Collections::Generic::List<Elysium::Core::String>>::const_iterator Iterator = _Headers.find(Name);
	if (Iterator == _Headers.end())
	{	// ToDo: throw specific exception
		throw Elysium::Core::Exception(L"header not found");
	}
	else
	{
		return Iterator->second;
	}
}
const Elysium::Core::Collections::Generic::List<Elysium::Core::String>& Elysium::Communication::Service::Http::Headers::HttpHeaders::GetValues(const Elysium::Core::String & Name) const
{
	std::map<Elysium::Core::String, Elysium::Core::Collections::Generic::List<Elysium::Core::String>>::const_iterator Iterator = _Headers.find(Name);
	if (Iterator == _Headers.end())
	{	// ToDo: throw specific exception
		throw Elysium::Core::Exception(L"header not found");
	}
	else
	{
		return Iterator->second;
	}
}
bool Elysium::Communication::Service::Http::Headers::HttpHeaders::Remove(const Elysium::Core::String & Name)
{
	std::map<Elysium::Core::String, Elysium::Core::Collections::Generic::List<Elysium::Core::String>>::iterator Iterator = _Headers.find(Name);
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
{
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
Elysium::Communication::Service::Http::Headers::HttpHeaders & Elysium::Communication::Service::Http::Headers::HttpHeaders::operator=(HttpHeaders && Right)
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
		//_Headers = std::map<Elysium::Core::String, Elysium::Core::Collections::Generic::List<Elysium::Core::String>>(Right._Headers);

		// release Right's objects
		//Right._Headers.clear();
	}
	return *this;
}
