/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_FILTER
#define ELYSIUM_LOGGING_FILTER

#ifndef ELYSIUM_LOGGER_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_LOGGING_EVENTS_LOGEVENT
#include "LogEvent.hpp"
#endif

#ifndef ELYSIUM_LOGGING_EVENTS_LOGLEVEL
#include "LogLevel.hpp"
#endif

namespace Elysium
{
	namespace Logging
	{
		class ELYSIUM_LOGGING_API Filter final
		{
		public:
			Filter();
			Filter(const Elysium::Core::String& Scope, const Events::LogLevel& MinimumLogLevel, const Events::LogLevel& MaximumLogLevel);
			Filter(const Filter& Source);
			Filter(Filter&& Right) noexcept;
			~Filter();

			Filter& operator=(const Filter& Source);
			Filter& operator=(Filter&& Right) noexcept;

			bool IsInterested(const Events::LogEvent& Event);
		private:
			Elysium::Core::String _Scope;
			Events::LogLevel _MinimumLogLevel;
			Events::LogLevel _MaximumLogLevel;
		};
	}
}
#endif
