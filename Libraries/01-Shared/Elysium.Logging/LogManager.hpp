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

#ifndef ELYSIUM_LOGGING_EVENTS_LOGEVENT
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

#ifndef ELYSIUM_CORE_REFLECTION_TYPE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Reflection/Type.hpp"
#endif

#ifndef ELYSIUM_LOGGING_LOGGER
#include "Logger.hpp"
#endif

#ifndef ELYSIUM_LOGGING_IAPPENDER
#include "IAppender.hpp"
#endif

#ifndef ELYSIUM_LOGGING_IFLUSHABLEAPPENDER
#include "IFlushableAppender.hpp"
#endif

#ifndef _MUTEX_
#include <mutex>
#endif

#pragma warning(disable : 4251)	// the map etc. aren't accessible so we can just disable the warning - ToDo: will this affect other files if we don't enable the warning again?

namespace Elysium
{
	namespace Logging
	{
		class ELYSIUM_LOGGING_API LogManager final
		{
			friend class Logger;
		public:
			~LogManager();

			static const Logger* GetLogger(const Elysium::Core::Reflection::Type& Type);
			static const Logger* GetLogger(const Elysium::Core::String& Scope);

			static void RegisterAppender(IAppender& Appender);
			static void UnregisterAppender(IAppender& Appender);

			static void Stop();
		private:
			LogManager();

			static std::mutex _AppenderMutex;
			static std::mutex _FlushableAppenderMutex;

			static std::map<Elysium::Core::String, Logger*> _Logger;

			static Elysium::Core::Collections::Generic::List<IAppender*> _Appender;
			static Elysium::Core::Collections::Generic::List<IFlushableAppender*> _FlushableAppender;

			static void Forward(const Events::LogEvent& Event);
		};
	}
}
#endif
