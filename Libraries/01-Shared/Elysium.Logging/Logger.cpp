#include "Logger.hpp"

#ifndef ELYSIUM_LOGGING_EVENTS_LOGEVENT
#include "LogEvent.hpp"
#endif

#ifndef ELYSIUM_LOGGING_LOGMANAGER
#include "LogManager.hpp"
#endif

Elysium::Logging::Logger::Logger(const Elysium::Core::Reflection::Type & Type)
	: _Scope(Type.GetFullName())
{
}

Elysium::Logging::Logger::Logger(const Elysium::Core::String & Scope)
	: _Scope(Scope)
{
}
Elysium::Logging::Logger::~Logger()
{
}

void Elysium::Logging::Logger::Trace(const Elysium::Core::String & Message) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Trace, _Scope, Message));
}
void Elysium::Logging::Logger::Trace(const Elysium::Core::String & Message, const Elysium::Core::Exception & Exception) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Trace, _Scope, Message, Exception));
}

void Elysium::Logging::Logger::Debug(const Elysium::Core::String & Message) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Debug, _Scope, Message));
}
void Elysium::Logging::Logger::Debug(const Elysium::Core::String & Message, const Elysium::Core::Exception & Exception) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Debug, _Scope, Message, Exception));
}

void Elysium::Logging::Logger::Information(const Elysium::Core::String & Message) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Information, _Scope, Message));
}
void Elysium::Logging::Logger::Information(const Elysium::Core::String & Message, const Elysium::Core::Exception & Exception) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Information, _Scope, Message, Exception));
}

void Elysium::Logging::Logger::Warning(const Elysium::Core::String & Message) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Warning, _Scope, Message));
}
void Elysium::Logging::Logger::Warning(const Elysium::Core::String & Message, const Elysium::Core::Exception & Exception) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Warning, _Scope, Message, Exception));
}

void Elysium::Logging::Logger::Error(const Elysium::Core::String & Message) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Error, _Scope, Message));
}
void Elysium::Logging::Logger::Error(const Elysium::Core::String & Message, const Elysium::Core::Exception & Exception) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Error, _Scope, Message, Exception));
}

void Elysium::Logging::Logger::Critical(const Elysium::Core::String & Message) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Critical, _Scope, Message));
}
void Elysium::Logging::Logger::Critical(const Elysium::Core::String & Message, const Elysium::Core::Exception & Exception) const
{
	LogManager::Forward(Events::LogEvent(Elysium::Core::DateTime::Now(), Events::LogLevel::Critical, _Scope, Message, Exception));
}
