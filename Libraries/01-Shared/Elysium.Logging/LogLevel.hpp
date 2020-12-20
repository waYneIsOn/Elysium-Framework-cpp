/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_LOGGING_EVENTS_LOGLEVEL
#define ELYSIUM_LOGGING_EVENTS_LOGLEVEL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Logging::Events
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class LogLevel : Elysium::Core::uint32_t
#elif defined(__ANDROID__)
	enum class LogLevel
#else
#error "undefined os"
#endif
	{
		Trace = 1,
		Debug = 2,
		Information = 3,
		Warning = 4,
		Error = 5,
		Critical = 6,
	};
}
#endif
