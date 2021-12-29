/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_LOGGING_APPENDER_FILEAPPENDER
#define ELYSIUM_LOGGING_APPENDER_FILEAPPENDER

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
	class ELYSIUM_LOGGING_API FileAppender : public IAppender
	{
	public:
		FileAppender(const Elysium::Core::Utf8String& FullFilePath);
		virtual ~FileAppender();

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

		const Elysium::Core::Text::Encoding& _Encoding;
		Elysium::Core::IO::FileStream _FileStream;
	};
}
#endif
