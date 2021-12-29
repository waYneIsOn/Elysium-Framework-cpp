#include "AuthenticationHeaderValue.hpp"

Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::AuthenticationHeaderValue(const Elysium::Core::Utf8String& Scheme)
	: _Scheme(Scheme), _Parameter()
{ }
Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::AuthenticationHeaderValue(const Elysium::Core::Utf8String & Scheme, const Elysium::Core::Utf8String & Parameter)
	: _Scheme(Scheme), _Parameter(Parameter)
{ }
Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::~AuthenticationHeaderValue()
{ }

bool Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::operator==(const AuthenticationHeaderValue & Other)
{
	if (_Scheme == Other._Scheme && _Parameter == Other._Parameter)
	{
		return true;
	}
	return false;
}
bool Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::operator!=(const AuthenticationHeaderValue & Other)
{
	if (_Scheme != Other._Scheme || _Parameter != Other._Parameter)
	{
		return false;
	}
	return true;
}

const Elysium::Core::Utf8String & Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::GetScheme() const
{
	return _Scheme;
}
const Elysium::Core::Utf8String & Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::GetParameter() const
{
	return _Parameter;
}

void Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::SetScheme(const Elysium::Core::Utf8String & Value)
{
	_Scheme = Value;
}
void Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::SetParameter(const Elysium::Core::Utf8String & Value)
{
	_Parameter = Value;
}
