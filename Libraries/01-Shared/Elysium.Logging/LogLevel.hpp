/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_LOGLEVEL
#define ELYSIUM_LOGGING_LOGLEVEL

namespace Elysium
{
	namespace Logging
	{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
		enum class LogLevel : long
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
#endif
