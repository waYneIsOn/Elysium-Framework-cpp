/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_LOGGING_LOGGER
#define ELYSIUM_LOGGING_LOGGER

#ifdef _MSC_VER
#pragma once
#endif

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

namespace Elysium::Logging
{
	class ELYSIUM_LOGGING_API Logger final
	{
	public:
		Logger(const Elysium::Core::Reflection::Type& Type);
		Logger(const Elysium::Core::Utf8String& Scope);
		~Logger();

		void Trace(const Elysium::Core::Utf8String& Message) const;
		void Trace(const Elysium::Core::Utf8String& Message, const Elysium::Core::Exception& Exception) const;

		void Debug(const Elysium::Core::Utf8String& Message) const;
		void Debug(const Elysium::Core::Utf8String& Message, const Elysium::Core::Exception& Exception) const;

		void Information(const Elysium::Core::Utf8String& Message) const;
		void Information(const Elysium::Core::Utf8String& Message, const Elysium::Core::Exception& Exception) const;

		void Warning(const Elysium::Core::Utf8String& Message) const;
		void Warning(const Elysium::Core::Utf8String& Message, const Elysium::Core::Exception& Exception) const;

		void Error(const Elysium::Core::Utf8String& Message) const;
		void Error(const Elysium::Core::Utf8String& Message, const Elysium::Core::Exception& Exception) const;

		void Critical(const Elysium::Core::Utf8String& Message) const;
		void Critical(const Elysium::Core::Utf8String& Message, const Elysium::Core::Exception& Exception) const;
	private:
		Elysium::Core::Utf8String _Scope;
	};
}
#endif
