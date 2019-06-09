#include "AuthenticationHeaderValue.hpp"

Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::AuthenticationHeaderValue()
{
}
Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::AuthenticationHeaderValue(const AuthenticationHeaderValue & Value)
	: _Scheme(Value._Scheme), _Parameter(Value._Parameter)
{
}
Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::~AuthenticationHeaderValue()
{
}

const Elysium::Core::String & Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::GetScheme() const
{
	return _Scheme;
}
const Elysium::Core::String & Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::GetParameter() const
{
	return _Parameter;
}

void Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::SetScheme(const Elysium::Core::String & Value)
{
	_Scheme = Value;
}
void Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::SetParameter(const Elysium::Core::String & Value)
{
	_Parameter = Value;
}

Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue & Elysium::Communication::Service::Http::Headers::AuthenticationHeaderValue::operator=(const AuthenticationHeaderValue & Value)
{
	if (*this != Value)
	{
		_Scheme = Value._Scheme;
		_Parameter = Value._Parameter;
	}

	return *this;
}

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