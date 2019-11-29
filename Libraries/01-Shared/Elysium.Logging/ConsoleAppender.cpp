#include "ConsoleAppender.hpp"

#ifndef _IOSTREAM_
#include <iostream>
#endif

Elysium::Logging::Appender::ConsoleAppender::ConsoleAppender()
	: Elysium::Logging::IAppender(),
	_Formats(std::map<Events::LogLevel, Elysium::Core::String>())
{
	_Formats[Events::LogLevel::Trace] = u"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
	_Formats[Events::LogLevel::Debug] = u"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
	_Formats[Events::LogLevel::Information] = u"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
	_Formats[Events::LogLevel::Warning] = u"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
	_Formats[Events::LogLevel::Error] = u"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
	_Formats[Events::LogLevel::Critical] = u"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
}
Elysium::Logging::Appender::ConsoleAppender::~ConsoleAppender()
{
}

const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetTraceFormat() const
{
	return _Formats.at(Events::LogLevel::Trace);
}
const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetDebugFormat() const
{
	return _Formats.at(Events::LogLevel::Debug);
}
const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetInformationFormat() const
{
	return _Formats.at(Events::LogLevel::Information);
}
const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetWarningFormat() const
{
	return _Formats.at(Events::LogLevel::Warning);
}
const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetErrorFormat() const
{
	return _Formats.at(Events::LogLevel::Error);
}
const Elysium::Core::String & Elysium::Logging::Appender::ConsoleAppender::GetCriticalFormat() const
{
	return _Formats.at(Events::LogLevel::Critical);
}

void Elysium::Logging::Appender::ConsoleAppender::SetTraceFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Trace] = Format;
}
void Elysium::Logging::Appender::ConsoleAppender::SetDebugFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Debug] = Format;
}
void Elysium::Logging::Appender::ConsoleAppender::SetInformationFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Information] = Format;
}
void Elysium::Logging::Appender::ConsoleAppender::SetWarningFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Warning] = Format;
}
void Elysium::Logging::Appender::ConsoleAppender::SetErrorFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Error] = Format;
}
void Elysium::Logging::Appender::ConsoleAppender::SetCriticalFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Critical] = Format;
}

void Elysium::Logging::Appender::ConsoleAppender::Process(const Events::LogEvent & Event)
{
	// ToDo: use formatted message
#ifdef UNICODE
	std::wcout << Event.GetMessage().GetCharArray();
#else
	std::cout << Event.GetMessage().GetCharArray();
#endif
}
