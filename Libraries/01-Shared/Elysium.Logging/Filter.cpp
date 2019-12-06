#include "Filter.hpp"

#ifndef _TYPE_TRAITS_
#include <type_traits>
#endif

Elysium::Logging::Filter::Filter()
	: _Scope(), _MinimumLogLevel(Events::LogLevel::Trace), _MaximumLogLevel(Events::LogLevel::Critical)
{
}
Elysium::Logging::Filter::Filter(const Elysium::Core::String & Scope, const Events::LogLevel & MinimumLogLevel, const Events::LogLevel & MaximumLogLevel)
	: _Scope(Scope), _MinimumLogLevel(MinimumLogLevel), _MaximumLogLevel(MaximumLogLevel)
{
}
Elysium::Logging::Filter::Filter(const Filter & Source)
	: _Scope(Elysium::Core::String(Source._Scope)), _MinimumLogLevel(Source._MinimumLogLevel), _MaximumLogLevel(Source._MaximumLogLevel)
{
}
Elysium::Logging::Filter::Filter(Filter && Right) noexcept
	: _Scope(), _MinimumLogLevel(Events::LogLevel::Trace), _MaximumLogLevel(Events::LogLevel::Critical)
{
	*this = std::move(Right);
}
Elysium::Logging::Filter::~Filter()
{
}

Elysium::Logging::Filter & Elysium::Logging::Filter::operator=(const Filter & Source)
{
	if (this != &Source)
	{

	}
	return *this;
}
Elysium::Logging::Filter & Elysium::Logging::Filter::operator=(Filter && Right) noexcept
{
	if (this != &Right)
	{
		_Scope = Right._Scope;
		_MinimumLogLevel = Right._MinimumLogLevel;
		_MaximumLogLevel = Right._MaximumLogLevel;
	}
	return *this;
}

bool Elysium::Logging::Filter::IsInterested(const Events::LogEvent & Event)
{
	return Event.GetScope().StartsWith(_Scope.GetCharArray()) && Event.GetLevel() >= _MinimumLogLevel && Event.GetLevel() <= _MaximumLogLevel;
}
