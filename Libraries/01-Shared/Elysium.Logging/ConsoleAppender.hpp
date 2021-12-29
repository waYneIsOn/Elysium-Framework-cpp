/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_LOGGING_APPENDER_CONSOLEAPPENDER
#define ELYSIUM_LOGGING_APPENDER_CONSOLEAPPENDER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_LOGGING_IAPPENDER
#include "IAppender.hpp"
#endif

#ifndef _MAP_
#include <map>
#endif

namespace Elysium::Logging::Appender
{
	class ELYSIUM_LOGGING_API ConsoleAppender : public IAppender
	{
	public:
		ConsoleAppender();
		virtual ~ConsoleAppender();

		virtual const Elysium::Core::Utf8String& GetTraceFormat() const override;
		virtual const Elysium::Core::Utf8String& GetDebugFormat() const override;
		virtual const Elysium::Core::Utf8String& GetInformationFormat() const override;
		virtual const Elysium::Core::Utf8String& GetWarningFormat() const override;
		virtual const Elysium::Core::Utf8String& GetErrorFormat() const override;
		virtual const Elysium::Core::Utf8String& GetCriticalFormat() const override;

		virtual void SetTraceFormat(const Elysium::Core::Utf8String& Format) override;
		virtual void SetDebugFormat(const Elysium::Core::Utf8String& Format) override;
		virtual void SetInformationFormat(const Elysium::Core::Utf8String& Format) override;
		virtual void SetWarningFormat(const Elysium::Core::Utf8String& Format) override;
		virtual void SetErrorFormat(const Elysium::Core::Utf8String& Format) override;
		virtual void SetCriticalFormat(const Elysium::Core::Utf8String& Format) override;

		virtual void Process(const Events::LogEvent& Event) override;
	private:
		std::map<Events::LogLevel, Elysium::Core::Utf8String> _Formats;
	};
}
#endif
