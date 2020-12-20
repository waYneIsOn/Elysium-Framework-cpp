/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_INTERNETPROTOCOLVERSION
#define ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_INTERNETPROTOCOLVERSION

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Protocol::InternetLayer
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class InternetProtocolVersion : Elysium::Core::uint8_t
#elif defined(__ANDROID__)
	enum class InternetProtocolVersion
#else
#error "undefined os"
#endif
	{
		V4 = 4,

		V6 = 6,
	};
}
#endif
