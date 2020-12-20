/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_KNOWNUDPPORT
#define ELYSIUM_COMMUNICATION_KNOWNUDPPORT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class KnownUdpPort : Elysium::Core::uint16_t
#elif defined(__ANDROID__)
	enum class KnownUdpPort
#else
#error "undefined os"
#endif
	{


		DynamicPortFirst = 49152,
		DynamicPortLast = 65535,
	};
}
#endif
