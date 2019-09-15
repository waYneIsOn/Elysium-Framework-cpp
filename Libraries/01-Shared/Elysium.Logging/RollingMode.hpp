/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_APPENDER_ROLLINGMODE
#define ELYSIUM_LOGGING_APPENDER_ROLLINGMODE

namespace Elysium
{
	namespace Logging
	{
		namespace Appender
		{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
			enum class RollingMode : long
#elif defined(__ANDROID__)
			enum class RollingMode
#else
#error "undefined os"
#endif
			{
				Once = 0,
				Size = 1,
				Date = 2,
				Composite = 3,
			};
		}
	}
}
#endif
