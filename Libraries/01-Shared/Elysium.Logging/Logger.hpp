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

#ifndef ELYSIUM_CORE_REFLECTION_TYPE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Reflection/Type.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_CORE_EXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Exception.hpp"
#endif

namespace Elysium
{
	namespace Logging
	{
		class ELYSIUM_LOGGING_API Logger final
		{
		public:
			Logger(const Elysium::Core::Reflection::Type& Type);
			Logger(const Elysium::Core::String& Scope);
			~Logger();

			void Trace(const Elysium::Core::String& Message) const;
			void Trace(const Elysium::Core::String& Message, const Elysium::Core::Exception& Exception) const;

			void Debug(const Elysium::Core::String& Message) const;
			void Debug(const Elysium::Core::String& Message, const Elysium::Core::Exception& Exception) const;

			void Information(const Elysium::Core::String& Message) const;
			void Information(const Elysium::Core::String& Message, const Elysium::Core::Exception& Exception) const;

			void Warning(const Elysium::Core::String& Message) const;
			void Warning(const Elysium::Core::String& Message, const Elysium::Core::Exception& Exception) const;

			void Error(const Elysium::Core::String& Message) const;
			void Error(const Elysium::Core::String& Message, const Elysium::Core::Exception& Exception) const;

			void Critical(const Elysium::Core::String& Message) const;
			void Critical(const Elysium::Core::String& Message, const Elysium::Core::Exception& Exception) const;
		private:
			Elysium::Core::String _Scope;
		};
	}
}
#endif
