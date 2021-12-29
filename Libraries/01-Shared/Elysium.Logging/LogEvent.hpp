/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_LOGGING_EVENTS_LOGEVENT
#define ELYSIUM_LOGGING_EVENTS_LOGEVENT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_LOGGER_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_LOGGING_LOGGER
#include "Logger.hpp"
#endif

#ifndef ELYSIUM_CORE_DATETIME
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/DateTime.hpp"
#endif

#ifndef ELYSIUM_LOGGING_EVENTS_LOGLEVEL
#include "LogLevel.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_CORE_EXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Exception.hpp"
#endif

namespace Elysium::Logging::Events
{
	class ELYSIUM_LOGGING_API LogEvent final
	{
		friend class Elysium::Logging::Logger;
	public:
		LogEvent(const LogEvent& Source) = delete;
		LogEvent(LogEvent&& Right) = delete;
		~LogEvent();

		const Elysium::Core::DateTime& GetTimestamp() const;
		const LogLevel& GetLevel() const;
		const Elysium::Core::Utf8String& GetScope() const;
		const Elysium::Core::Utf8String& GetMessage() const;
		const Elysium::Core::Exception* GetException() const;
	private:
		LogEvent(const Elysium::Core::DateTime& Timestamp, const LogLevel& Level, const Elysium::Core::Utf8String& Scope, const Elysium::Core::Utf8String& Message);
		LogEvent(const Elysium::Core::DateTime& Timestamp, const LogLevel& Level, const Elysium::Core::Utf8String& Scope, const Elysium::Core::Utf8String& Message, const Elysium::Core::Exception& Exception);

		const Elysium::Core::DateTime _Timestamp;
		const LogLevel _Level;
		const Elysium::Core::Utf8String _Scope;
		const Elysium::Core::Utf8String _Message;
		const Elysium::Core::Exception* _Exception;
	};
}
#endif
