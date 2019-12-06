#include "HttpMethod.hpp"

#ifndef _TYPE_TRAITS_
#include <type_traits>
#endif

const Elysium::Core::String Elysium::Communication::Service::Http::HttpMethod::_Connect = u"CONNECT";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMethod::_Delete = u"DELETE";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMethod::_Get = u"GET";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMethod::_Head = u"HEAD";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMethod::_Options = u"OPTIONS";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMethod::_Patch = u"PATCH";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMethod::_Post = u"POST";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMethod::_Put = u"PUT";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMethod::_Trace = u"TRACE";

Elysium::Communication::Service::Http::HttpMethod::HttpMethod(const Elysium::Core::String & Method)
	: _Method(Elysium::Core::String(Method))
{
}
Elysium::Communication::Service::Http::HttpMethod::HttpMethod(const HttpMethod & Source)
	: _Method(Elysium::Core::String(Source._Method))
{
}
Elysium::Communication::Service::Http::HttpMethod::HttpMethod(HttpMethod && Right) noexcept
{
	*this = std::move(Right);
}
Elysium::Communication::Service::Http::HttpMethod::~HttpMethod()
{
}

Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::operator=(const HttpMethod & Source)
{
	if (this != &Source)
	{
		_Method = Elysium::Core::String(Source._Method);
	}
	return *this;
}
Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::operator=(HttpMethod && Right) noexcept
{
	if (this != &Right)
	{
		_Method = std::move(Right._Method);
	}
	return *this;
}

const Elysium::Core::String & Elysium::Communication::Service::Http::HttpMethod::GetMethod() const
{
	return _Method;
}

const Elysium::Core::String & Elysium::Communication::Service::Http::HttpMethod::Connect()
{
	return _Connect;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::HttpMethod::Delete()
{
	return _Delete;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::HttpMethod::Get()
{
	return _Get;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::HttpMethod::Head()
{
	return _Head;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::HttpMethod::Options()
{
	return _Options;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::HttpMethod::Patch()
{
	return _Patch;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::HttpMethod::Post()
{
	return _Post;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::HttpMethod::Put()
{
	return _Put;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::HttpMethod::Trace()
{
	return _Trace;
}
