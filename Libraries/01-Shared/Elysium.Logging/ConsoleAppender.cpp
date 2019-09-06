#include "ConsoleAppender.hpp"

#ifndef _IOSTREAM_
#include <iostream>
#endif

Elysium::Logging::Appender::ConsoleAppender::ConsoleAppender()
	: Elysium::Logging::IAppender(),
	_Formats(std::map<LogLevel, Elysium::Core::String>())
{
	_Formats[LogLevel::Trace] = L"{Timestamp} [{Level}] {Message} [{Exception}]{NewLine}";
	_Formats[LogLevel::Debug] = L"{Timestamp} [{Level}] {Message} [{Exception}]{NewLine}";
	_Formats[LogLevel::Information] = L"{Timestamp} [{Level}] {Message} [{Exception}]{NewLine}";
	_Formats[LogLevel::Warning] = L"{Timestamp} [{Level}] {Message} [{Exception}]{NewLine}";
	_Formats[LogLevel::Error] = L"{Timestamp} [{Level}] {Message} [{Exception}]{NewLine}";
	_Formats[LogLevel::Critical] = L"{Timestamp} [{Level}] {Message} [{Exception}]{NewLine}";
}
Elysium::Logging::Appender::ConsoleAppender::~ConsoleAppender()
{
}

const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetTraceFormat() const
{
	return _Formats.at(LogLevel::Trace);
}
const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetDebugFormat() const
{
	return _Formats.at(LogLevel::Debug);
}
const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetInformationFormat() const
{
	return _Formats.at(LogLevel::Information);
}
const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetWarningFormat() const
{
	return _Formats.at(LogLevel::Warning);
}
const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetErrorFormat() const
{
	return _Formats.at(LogLevel::Error);
}
const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetCriticalFormat() const
{
	return _Formats.at(LogLevel::Critical);
}

void Elysium::Logging::Appender::ConsoleAppender::SetTraceFormat(const Elysium::Core::String & Format)
{
	_Formats[LogLevel::Trace] = Format;
}
void Elysium::Logging::Appender::ConsoleAppender::SetDebugFormat(const Elysium::Core::String & Format)
{
	_Formats[LogLevel::Debug] = Format;
}
void Elysium::Logging::Appender::ConsoleAppender::SetInformationFormat(const Elysium::Core::String & Format)
{
	_Formats[LogLevel::Information] = Format;
}
void Elysium::Logging::Appender::ConsoleAppender::SetWarningFormat(const Elysium::Core::String & Format)
{
	_Formats[LogLevel::Warning] = Format;
}
void Elysium::Logging::Appender::ConsoleAppender::SetErrorFormat(const Elysium::Core::String & Format)
{
	_Formats[LogLevel::Error] = Format;
}
void Elysium::Logging::Appender::ConsoleAppender::SetCriticalFormat(const Elysium::Core::String & Format)
{
	_Formats[LogLevel::Critical] = Format;
}

void Elysium::Logging::Appender::ConsoleAppender::Write(const LogEvent & Event)
{
#ifdef UNICODE
	std::wcout << Event.GetMessage().GetCharArray();
#else
	std::cout << Event.GetMessage().GetCharArray();
#endif
}
