#include "LogEvent.hpp"

Elysium::Logging::LogEvent::LogEvent(const LogLevel & Level, const Elysium::Core::String & Scope, const Elysium::Core::String & Message)
	: _Level(LogLevel(Level)), _Scope(Elysium::Core::String(Scope)), _Message(Elysium::Core::String(Message))
{
}

Elysium::Logging::LogEvent::~LogEvent()
{
}

const Elysium::Logging::LogLevel & Elysium::Logging::LogEvent::GetLevel() const
{
	return _Level;
}
const Elysium::Core::String & Elysium::Logging::LogEvent::GetScope() const
{
	return _Scope;
}
const Elysium::Core::String & Elysium::Logging::LogEvent::GetMessage() const
{
	return _Message;
}
