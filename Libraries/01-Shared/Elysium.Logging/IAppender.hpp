/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_IAPPENDER
#define ELYSIUM_LOGGING_IAPPENDER

#ifndef ELYSIUM_LOGGER_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_LOGGING_EVENTS_LOGEVENT
#include "LogEvent.hpp"
#endif

namespace Elysium
{
	namespace Logging
	{
		class ELYSIUM_LOGGING_API IAppender
		{
		public:
			virtual ~IAppender() { }

			virtual const Elysium::Core::String& GetTraceFormat() const = 0;
			virtual const Elysium::Core::String& GetDebugFormat() const = 0;
			virtual const Elysium::Core::String& GetInformationFormat() const = 0;
			virtual const Elysium::Core::String& GetWarningFormat() const = 0;
			virtual const Elysium::Core::String& GetErrorFormat() const = 0;
			virtual const Elysium::Core::String& GetCriticalFormat() const = 0;

			virtual void SetTraceFormat(const Elysium::Core::String& Format) = 0;
			virtual void SetDebugFormat(const Elysium::Core::String& Format) = 0;
			virtual void SetInformationFormat(const Elysium::Core::String& Format) = 0;
			virtual void SetWarningFormat(const Elysium::Core::String& Format) = 0;
			virtual void SetErrorFormat(const Elysium::Core::String& Format) = 0;
			virtual void SetCriticalFormat(const Elysium::Core::String& Format) = 0;

			virtual void Write(const Events::LogEvent& Event) = 0;
		protected:
			IAppender() { }
		};
	}
}
#endif
