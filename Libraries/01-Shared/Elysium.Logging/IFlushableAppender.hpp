/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_IFLUSHABLEAPPENDER
#define ELYSIUM_LOGGING_IFLUSHABLEAPPENDER

#ifndef ELYSIUM_LOGGING_IAPPENDER
#include "IAppender.hpp"
#endif

namespace Elysium
{
	namespace Logging
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
#endif
