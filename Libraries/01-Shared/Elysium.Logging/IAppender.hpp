/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_APPENDER_IAPPENDER
#define ELYSIUM_LOGGING_APPENDER_IAPPENDER

#ifndef ELYSIUM_LOGGER_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_LOGGING_LOGEVENT
#include "LogEvent.hpp"
#endif

namespace Elysium
{
	namespace Logging
	{
		namespace Appender
		{
			class ELYSIUM_LOGGING_API IAppender
			{
			public:
				virtual ~IAppender() { }

				virtual void Write(const LogEvent& Event) = 0;
			protected:
				IAppender() { }
			};
		}
	}
}
#endif
