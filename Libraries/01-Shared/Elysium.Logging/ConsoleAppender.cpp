#include "ConsoleAppender.hpp"

#ifndef _IOSTREAM_
#include <iostream>
#endif

Elysium::Logging::Appender::ConsoleAppender::ConsoleAppender()
	: Elysium::Logging::Appender::IAppender()
{
}
Elysium::Logging::Appender::ConsoleAppender::~ConsoleAppender()
{
}

void Elysium::Logging::Appender::ConsoleAppender::Write(const LogEvent & Event)
{
#ifdef UNICODE
	std::wcout << Event.GetMessage().GetCharArray();
#else
	std::cout << Event.GetMessage().GetCharArray();
#endif
}
