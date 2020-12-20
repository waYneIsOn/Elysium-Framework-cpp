/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_KNOWNTCPPORT
#define ELYSIUM_COMMUNICATION_KNOWNTCPPORT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class KnownTcpPort : Elysium::Core::uint16_t
#elif defined(__ANDROID__)
	enum class KnownTcpPort
#else
#error "undefined os"
#endif
	{
		// well known ports
		SystemAllocatedDynamicPort = 0,
		TcpMux = 1,
		RemoteJobEntry = 5,
		EchoProtocol = 7,
		DiscardProtocol = 9,
		WakeOnLan = 9,
		SystatService = 11,
		DaytimeProtocol = 13,
		PreviouslyNetstat = 15,
		QuoteOfTheDay = 17,
		MessageSendProtocol = 18,
		CharacterGeneratorProtocol = 19,
		FtpData = 20,
		FtpControl = 21,
		SSH = 22,
		TelnetProtocol = 23,
		Smtp = 25,
		TimeProtocol = 37,
		HostNameServerProtocol = 42,
		WhoIsProtocol = 43,
		Unnamed47 = 47,
		TacacsLoginHostProtocol = 49,
		HistoricalImp = 51,
		XeroxNetworkSystemsTimeProtocol = 52,
		Dns = 53,
		XeroxNetworkSystemsClearinghouse = 54,
		XeroxNetworkSystemsAuthenticationProtocol = 56,
		XeroxNetworkSystemsMail = 58,
		HistoricalNiftp = 61,
		BoostrapProtocolServer = 67,
		BoostrapProtocolClient = 68,
		TrivialFtp = 69,
		Gopher = 70,

		Http = 80,

		Kerberos = 88,

		Irc = 194,

		Https = 443,

		Ldap = 389,

		Ldaps = 636,

		FtpsData = 990,
		FtpsControl = 990,

		Ircs = 994,
		Pop3s = 995,
		
		// registered ports

		MssqlServer = 1433,
		MssqlMonitor = 1434,

		// dynamic ports

		DynamicPortFirst = 49152,
		DynamicPortLast = 65535,
	};
}
#endif
