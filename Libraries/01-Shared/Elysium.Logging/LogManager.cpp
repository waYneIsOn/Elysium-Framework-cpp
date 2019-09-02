#include "LogManager.hpp"

std::map<Elysium::Core::String, Elysium::Logging::Appender::IAppender*> _Appender = std::map<Elysium::Core::String, Elysium::Logging::Appender::IAppender*>();
Elysium::Core::Collections::Generic::List<Elysium::Logging::Appender::IFlushableAppender*> _FlushableAppender = Elysium::Core::Collections::Generic::List<Elysium::Logging::Appender::IFlushableAppender*>();

Elysium::Logging::LogManager::~LogManager()
{
}

void Elysium::Logging::LogManager::Stop()
{
	// Flush IFlushableAppenders
}

Elysium::Logging::LogManager::LogManager()
{
}

void Elysium::Logging::LogManager::Write(const LogEvent & Event)
{
}
