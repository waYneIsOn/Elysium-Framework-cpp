/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_LOGEVENT
#define ELYSIUM_LOGGING_LOGEVENT

#ifndef ELYSIUM_LOGGER_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_LOGGING_LOGLEVEL
#include "LogLevel.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

namespace Elysium
{
	namespace Logging
	{
		class ELYSIUM_LOGGING_API LogEvent final
		{
		public:
			LogEvent(const LogLevel& Level, const Elysium::Core::String& Scope, const Elysium::Core::String& Message);
			LogEvent(const LogEvent& Source) = delete;
			LogEvent(LogEvent&& Right) = delete;
			~LogEvent();

			const LogLevel& GetLevel() const;
			const Elysium::Core::String& GetScope() const;
			const Elysium::Core::String& GetMessage() const;
		private:
			LogLevel _Level;
			Elysium::Core::String _Scope;
			Elysium::Core::String _Message;
		};
	}
}
#endif
