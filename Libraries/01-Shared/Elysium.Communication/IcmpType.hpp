/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_ICMPTYPE
#define ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_ICMPTYPE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Protocol::InternetLayer
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class IcmpType : Elysium::Core::uint8_t
#elif defined(__ANDROID__)
	enum class IcmpType
#else
#error "undefined os"
#endif
	{
		EchoReply = 0,

		DestinationUnreachable = 3,

		SourceQuench = 4,

		RedirectMessage = 5,

		EchoRequest = 8,

		RouterAdvertisement = 9,

		RouterSolicitation = 10,

		TimeExceeded = 11,

		ParameterProblemBadIPHeader = 12,

		Timestamp = 13,

		TimestampReply = 14,

		InformationRequest = 15,

		InformationReply = 16,

		AddressMaskRequest = 17,

		AddressMaskReply = 18,

		Traceroute = 30,

		ExtendedEchoRequest = 42,

		ExtendedEchoReply = 43,
	};
}
#endif
