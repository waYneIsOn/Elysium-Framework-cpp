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

			template<typename T, typename = typename std::enable_if_t<std::is_base_of_v<IAppender, T>>>
			static void RegisterAppender(T& Appender);
			template<typename T, typename = typename std::enable_if_t<std::is_base_of_v<IAppender, T>>>
			static void UnregisterAppender(T& Appender);

			static void Stop();
		private:
			LogManager();

			static std::map<Elysium::Core::String, Logger*> _Logger;

			static Elysium::Core::Collections::Generic::List<IAppender*> _Appender;
			static Elysium::Core::Collections::Generic::List<IFlushableAppender*> _FlushableAppender;

			static void Forward(const LogEvent& Event);
		};

		template<typename T, typename>
		inline void LogManager::RegisterAppender(T & Appender)
		{
			_Appender.Add(&Appender);
			if (std::is_base_of_v<IFlushableAppender, T>)
			{
				_FlushableAppender.Add(dynamic_cast<IFlushableAppender*>(&Appender));
			}
		}
		template<typename T, typename>
		inline void LogManager::UnregisterAppender(T & Appender)
		{
			if (std::is_base_of_v<IFlushableAppender, T>)
			{
				_FlushableAppender.Remove(dynamic_cast<IFlushableAppender*>(&Appender));
			}
			_Appender.Remove(&Appender);
		}
	}
}
#endif
