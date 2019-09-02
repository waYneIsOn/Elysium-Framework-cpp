#include "Logger.hpp"

#ifndef ELYSIUM_LOGGING_LOGEVENT
#include "LogEvent.hpp"
#endif

#ifndef ELYSIUM_LOGGING_LOGMANAGER
#include "LogManager.hpp"
#endif

Elysium::Logging::Logger::Logger(const Elysium::Core::String & Scope)
	: _Scope(Scope)
{
}
Elysium::Logging::Logger::~Logger()
{
}

void Elysium::Logging::Logger::Trace(const Elysium::Core::String & Message)
{
	LogManager::Write(LogEvent(LogLevel::Trace, _Scope, Message));
}
void Elysium::Logging::Logger::Debug(const Elysium::Core::String & Message)
{
	LogManager::Write(LogEvent(LogLevel::Debug, _Scope, Message));
}
void Elysium::Logging::Logger::Information(const Elysium::Core::String & Message)
{
	LogManager::Write(LogEvent(LogLevel::Information, _Scope, Message));
}
void Elysium::Logging::Logger::Warning(const Elysium::Core::String & Message)
{
	LogManager::Write(LogEvent(LogLevel::Warning, _Scope, Message));
}
void Elysium::Logging::Logger::Error(const Elysium::Core::String & Message)
{
	LogManager::Write(LogEvent(LogLevel::Error, _Scope, Message));
}
void Elysium::Logging::Logger::Critical(const Elysium::Core::String & Message)
{
	LogManager::Write(LogEvent(LogLevel::Critical, _Scope, Message));
}
