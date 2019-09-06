/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_LOGGING_LOGGER
#define ELYSIUM_LOGGING_LOGGER

#ifndef ELYSIUM_LOGGER_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

namespace Elysium
{
	namespace Logging
	{
		class ELYSIUM_LOGGING_API Logger final
		{
			friend class LogManager;
		public:
			~Logger();
			
			void Trace(const Elysium::Core::String& Message) const;
			void Debug(const Elysium::Core::String& Message) const;
			void Information(const Elysium::Core::String& Message) const;
			void Warning(const Elysium::Core::String& Message) const;
			void Error(const Elysium::Core::String& Message) const;
			void Critical(const Elysium::Core::String& Message) const;
		private:
			Logger(const Elysium::Core::String& Scope);

			Elysium::Core::String _Scope;
		};
	}
}
#endif
