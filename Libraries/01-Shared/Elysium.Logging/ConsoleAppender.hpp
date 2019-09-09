/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_APPENDER_CONSOLEAPPENDER
#define ELYSIUM_LOGGING_APPENDER_CONSOLEAPPENDER

#ifndef ELYSIUM_LOGGING_IAPPENDER
#include "IAppender.hpp"
#endif

#ifndef _MAP_
#include <map>
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

				virtual const Elysium::Core::String& GetTraceFormat() const override;
				virtual const Elysium::Core::String& GetDebugFormat() const override;
				virtual const Elysium::Core::String& GetInformationFormat() const override;
				virtual const Elysium::Core::String& GetWarningFormat() const override;
				virtual const Elysium::Core::String& GetErrorFormat() const override;
				virtual const Elysium::Core::String& GetCriticalFormat() const override;

				virtual void SetTraceFormat(const Elysium::Core::String& Format) override;
				virtual void SetDebugFormat(const Elysium::Core::String& Format) override;
				virtual void SetInformationFormat(const Elysium::Core::String& Format) override;
				virtual void SetWarningFormat(const Elysium::Core::String& Format) override;
				virtual void SetErrorFormat(const Elysium::Core::String& Format) override;
				virtual void SetCriticalFormat(const Elysium::Core::String& Format) override;

				virtual void Write(const Events::LogEvent& Event) override;
			private:
				std::map<Events::LogLevel, Elysium::Core::String> _Formats;
			};
		}
	}
}
#endif
