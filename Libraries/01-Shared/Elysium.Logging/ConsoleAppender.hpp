/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_APPENDER_CONSOLEAPPENDER
#define ELYSIUM_LOGGING_APPENDER_CONSOLEAPPENDER

#ifndef ELYSIUM_LOGGING_APPENDER_IAPPENDER
#include "IAppender.hpp"
#endif

namespace Elysium
{
	namespace Logging
	{
		namespace Appender
		{
			class ELYSIUM_LOGGING_API ConsoleAppender : public IAppender
			{
			public:
				ConsoleAppender();
				virtual ~ConsoleAppender();

				virtual void Write(const LogEvent& Event) override;
			};
		}
	}
}
#endif
