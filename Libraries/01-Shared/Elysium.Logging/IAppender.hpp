/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_LOGGING_IAPPENDER
#define ELYSIUM_LOGGING_IAPPENDER

#ifdef _MSC_VER
#pragma once
#endif

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

			virtual const Elysium::Core::Utf8String& GetTraceFormat() const = 0;
			virtual const Elysium::Core::Utf8String& GetDebugFormat() const = 0;
			virtual const Elysium::Core::Utf8String& GetInformationFormat() const = 0;
			virtual const Elysium::Core::Utf8String& GetWarningFormat() const = 0;
			virtual const Elysium::Core::Utf8String& GetErrorFormat() const = 0;
			virtual const Elysium::Core::Utf8String& GetCriticalFormat() const = 0;

			virtual void SetTraceFormat(const Elysium::Core::Utf8String& Format) = 0;
			virtual void SetDebugFormat(const Elysium::Core::Utf8String& Format) = 0;
			virtual void SetInformationFormat(const Elysium::Core::Utf8String& Format) = 0;
			virtual void SetWarningFormat(const Elysium::Core::Utf8String& Format) = 0;
			virtual void SetErrorFormat(const Elysium::Core::Utf8String& Format) = 0;
			virtual void SetCriticalFormat(const Elysium::Core::Utf8String& Format) = 0;

			virtual void Process(const Events::LogEvent& Event) = 0;
		protected:
			IAppender() { }
		};
	}
}
#endif
