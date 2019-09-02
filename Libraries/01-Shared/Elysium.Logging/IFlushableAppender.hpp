/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_APPENDER_IFLUSHABLEAPPENDER
#define ELYSIUM_LOGGING_APPENDER_IFLUSHABLEAPPENDER

#ifndef ELYSIUM_LOGGING_APPENDER_IAPPENDER
#include "IAppender.hpp"
#endif

namespace Elysium
{
	namespace Logging
	{
		namespace Appender
		{
			class ELYSIUM_LOGGING_API IFlushableAppender : public IAppender
			{
			public:
				virtual ~IFlushableAppender() { }

				virtual void Flush() = 0;
			protected:
				IFlushableAppender() { }
			};
		}
	}
}
#endif
