/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_LOGGING_IFLUSHABLEAPPENDER
#define ELYSIUM_LOGGING_IFLUSHABLEAPPENDER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_LOGGING_IAPPENDER
#include "IAppender.hpp"
#endif

namespace Elysium::Logging
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
#endif
