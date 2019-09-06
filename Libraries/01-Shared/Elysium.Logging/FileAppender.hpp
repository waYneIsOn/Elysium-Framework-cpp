/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_APPENDER_FILEAPPENDER
#define ELYSIUM_LOGGING_APPENDER_FILEAPPENDER

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
			/*
			class ELYSIUM_LOGGING_API FileAppender : public IAppender
			{
			public:
				FileAppender();
				virtual ~FileAppender();

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

				virtual void Write(const LogEvent& Event) override;
			private:
				std::map<LogLevel, Elysium::Core::String> _Formats;
			};
			*/
		}
	}
}
#endif