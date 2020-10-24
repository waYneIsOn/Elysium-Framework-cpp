/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_IPPROTOCOLNUMBER
#define ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_IPPROTOCOLNUMBER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Protocol::InternetLayer
{
	// ToDo: add all other protocol numbers
	// https://en.wikipedia.org/wiki/List_of_IP_protocol_numbers
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class IPProtocolNumber : Elysium::Core::uint8_t
#elif defined(__ANDROID__)
	enum class IPProtocolNumber
#else
#error "undefined os"
#endif
	{
		IPv6HopyByHop = 0,
		Icmp = 1,
		Igmp = 2,
		GGP = 3,
		Tcp = 6,
		CBT = 7,
		Udp = 17,
		ILTransportProtocol = 40,
		SwIPe = 53,
		SatnetMonitoring = 69,
		ENCAP = 98,
		ScheduleTransferProtocol = 118,
		SpectraLinkRatioProtocol = 119,
		UniversalTransportInterfaceProtocol = 120,
		CRUDP = 127,
		SSCOPMCE = 128,

		Unassigned144 = 144,
		Unassigned166 = 166,
		Unassigned167 = 167,
		Unassigned177 = 177,
		Unassigned180 = 180,
		Unassigned189 = 189,
		Unassigned196 = 196,
		Unassigned197 = 197,
		Unassigned223 = 223,

		Experimental253 = 253,
		Experimental254 = 254,

		Reserved = 255
	};
}
#endif
