/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_LOGGING_APPENDER_ROLLINGFILEAPPENDER
#define ELYSIUM_LOGGING_APPENDER_ROLLINGFILEAPPENDER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_LOGGING_IAPPENDER
#include "IAppender.hpp"
#endif

#ifndef _MAP_
#include <map>
#endif

#ifndef ELYSIUM_CORE_IO_FILESTREAM
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/FileStream.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

namespace Elysium::Logging::Appender
{
	class ELYSIUM_LOGGING_API RollingFileAppender : public IAppender
	{
	public:
		RollingFileAppender(const Elysium::Core::String& FullFilePath);
		virtual ~RollingFileAppender();

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

		virtual void Process(const Events::LogEvent& Event) override;
	private:
		std::map<Events::LogLevel, Elysium::Core::String> _Formats;

		const Elysium::Core::Text::Encoding& _Encoding;
		Elysium::Core::IO::FileStream _FileStream;
	};
}
#endif
