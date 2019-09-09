#include "LogEvent.hpp"

Elysium::Logging::Events::LogEvent::LogEvent(const Elysium::Core::DateTime & Timestamp, const LogLevel & Level, const Elysium::Core::String & Scope, const Elysium::Core::String & Message)
	: _Timestamp(Elysium::Core::DateTime(Timestamp)), _Level(LogLevel(Level)), _Scope(Elysium::Core::String(Scope)), _Message(Elysium::Core::String(Message)), 
	_Exception(nullptr)
{
}
Elysium::Logging::Events::LogEvent::LogEvent(const Elysium::Core::DateTime & Timestamp, const LogLevel & Level, const Elysium::Core::String & Scope, const Elysium::Core::String & Message, const Elysium::Core::Exception & Exception)
	: _Timestamp(Elysium::Core::DateTime(Timestamp)), _Level(LogLevel(Level)), _Scope(Elysium::Core::String(Scope)), _Message(Elysium::Core::String(Message)),
	_Exception(new Elysium::Core::Exception(Exception))
{
}
Elysium::Logging::Events::LogEvent::~LogEvent()
{
	if (_Exception != nullptr)
	{
		delete _Exception;
		_Exception = nullptr;
	}
}

const Elysium::Core::DateTime & Elysium::Logging::Events::LogEvent::GetTimestamp() const
{
	return _Timestamp;
}
const Elysium::Logging::Events::LogLevel & Elysium::Logging::Events::LogEvent::GetLevel() const
{
	return _Level;
}
const Elysium::Core::String & Elysium::Logging::Events::LogEvent::GetScope() const
{
	return _Scope;
}
const Elysium::Core::String & Elysium::Logging::Events::LogEvent::GetMessage() const
{
	return _Message;
}
const Elysium::Core::Exception * Elysium::Logging::Events::LogEvent::GetException() const
{
	return _Exception;
}
