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

#ifndef ELYSIUM_CORE_COLLECTIONS_TEMPLATE_LIST
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/List.hpp"
#endif

#ifndef ELYSIUM_LOGGING_LOGGER
#include "Logger.hpp"
#endif

#ifndef ELYSIUM_LOGGING_IAPPENDER
#include "IAppender.hpp"
#endif

#ifndef ELYSIUM_LOGGING_FILTER
#include "Filter.hpp"
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

			static void RegisterAppender(IAppender& Appender, Filter& Filter);
			static void UnregisterAppender(IAppender& Appender);

			static void Stop();
		private:
			LogManager();

			static std::mutex _AppenderMutex;

			static std::map<IAppender*, Filter> _AppenderFilterMap;
			static Elysium::Core::Collections::Template::List<IFlushableAppender*> _FlushableAppender;

			static void Forward(const Events::LogEvent& Event);
		};
	}
}
#endif
