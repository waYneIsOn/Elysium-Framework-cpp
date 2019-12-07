#include "HttpMethod.hpp"

#ifndef _TYPE_TRAITS_
#include <type_traits>
#endif

const Elysium::Communication::Service::Http::HttpMethod Elysium::Communication::Service::Http::HttpMethod::_Connect = Elysium::Communication::Service::Http::HttpMethod(u"CONNECT");
const Elysium::Communication::Service::Http::HttpMethod Elysium::Communication::Service::Http::HttpMethod::_Delete = Elysium::Communication::Service::Http::HttpMethod(u"DELETE");
const Elysium::Communication::Service::Http::HttpMethod Elysium::Communication::Service::Http::HttpMethod::_Get = Elysium::Communication::Service::Http::HttpMethod(u"GET");
const Elysium::Communication::Service::Http::HttpMethod Elysium::Communication::Service::Http::HttpMethod::_Head = Elysium::Communication::Service::Http::HttpMethod(u"HEAD");
const Elysium::Communication::Service::Http::HttpMethod Elysium::Communication::Service::Http::HttpMethod::_Options = Elysium::Communication::Service::Http::HttpMethod(u"OPTIONS");
const Elysium::Communication::Service::Http::HttpMethod Elysium::Communication::Service::Http::HttpMethod::_Patch = Elysium::Communication::Service::Http::HttpMethod(u"PATCH");
const Elysium::Communication::Service::Http::HttpMethod Elysium::Communication::Service::Http::HttpMethod::_Post = Elysium::Communication::Service::Http::HttpMethod(u"POST");
const Elysium::Communication::Service::Http::HttpMethod Elysium::Communication::Service::Http::HttpMethod::_Put = Elysium::Communication::Service::Http::HttpMethod(u"PUT");
const Elysium::Communication::Service::Http::HttpMethod Elysium::Communication::Service::Http::HttpMethod::_Trace = Elysium::Communication::Service::Http::HttpMethod(u"TRACE");

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

const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::Connect()
{
	return _Connect;
}
const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::Delete()
{
	return _Delete;
}
const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::Get()
{
	return _Get;
}
const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::Head()
{
	return _Head;
}
const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::Options()
{
	return _Options;
}
const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::Patch()
{
	return _Patch;
}
const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::Post()
{
	return _Post;
}
const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::Put()
{
	return _Put;
}
const Elysium::Communication::Service::Http::HttpMethod & Elysium::Communication::Service::Http::HttpMethod::Trace()
{
	return _Trace;
}
