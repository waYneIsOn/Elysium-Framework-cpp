/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_EVENTS_LOGLEVEL
#define ELYSIUM_LOGGING_EVENTS_LOGLEVEL

#ifndef _STDINT
#include <stdint.h>
#endif

namespace Elysium
{
	namespace Logging
	{
		namespace Events
		{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
			enum class LogLevel : uint32_t
#elif defined(__ANDROID__)
			enum class LogLevel
#else
#error "undefined os"
#endif
			{
				Trace = 1,
				Debug = 2,
				Information = 3,
				Warning = 4,
				Error = 5,
				Critical = 6,
			};
		}
	}
}
#endif
