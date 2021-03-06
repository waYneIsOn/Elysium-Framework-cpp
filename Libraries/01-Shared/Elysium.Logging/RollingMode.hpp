/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_LOGGING_APPENDER_ROLLINGMODE
#define ELYSIUM_LOGGING_APPENDER_ROLLINGMODE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Logging::Appender
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class RollingMode : Elysium::Core::uint32_t
#elif defined(__ANDROID__)
	enum class RollingMode
#else
#error "undefined os"
#endif
	{
		Once = 0,
		Size = 1,
		Date = 2,
		Composite = 3,
	};
}
#endif
