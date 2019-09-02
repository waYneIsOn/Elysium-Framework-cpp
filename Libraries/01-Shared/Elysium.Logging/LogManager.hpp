/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_LOGMANAGER
#define ELYSIUM_LOGGING_LOGMANAGER

#ifndef ELYSIUM_LOGGER_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_LOGGING_LOGEVENT
#include "LogEvent.hpp"
#endif

#ifndef _MAP_
#include <map>
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_CORE_COLLECTIONS_GENERIC_LIST
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/List.hpp"
#endif

#ifndef ELYSIUM_LOGGING_APPENDER_IAPPENDER
#include "IAppender.hpp"
#endif

#ifndef ELYSIUM_LOGGING_APPENDER_IFLUSHABLEAPPENDER
#include "IFlushableAppender.hpp"
#endif

#include "ConsoleAppender.hpp"

#pragma warning(disable : 4251)	// the map etc. aren't accessible so we can just disable the warning - ToDo: will this affect other files?

namespace Elysium
{
	namespace Logging
	{
		class ELYSIUM_LOGGING_API LogManager final
		{
			friend class Logger;
		public:
			~LogManager();

			template<typename T, typename = typename std::enable_if_t<std::is_base_of_v<Appender::IAppender, T>>>
			static T* GetAppender(const Elysium::Core::String& Scope)
			{
				return nullptr;
			}

			static void Test()
			{
				bool bla = std::is_base_of_v<Appender::IAppender, Appender::ConsoleAppender>;
				bool bladfg = std::is_base_of_v<Appender::IAppender, Elysium::Core::String>;

				Appender::ConsoleAppender* Bla = GetAppender<Appender::ConsoleAppender>(L"");
				//Elysium::Core::String* sdf = GetAppender<Elysium::Core::String>(L"");
			}

			static void Stop();
		private:
			LogManager();

			static std::map<Elysium::Core::String, Appender::IAppender*> _Appender;
			static Elysium::Core::Collections::Generic::List<Appender::IFlushableAppender*> _FlushableAppender;

			static void Write(const LogEvent& Event);
		};
	}
}
#endif
