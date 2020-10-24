/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TRANSPORTLAYER_USERDATAGRAMPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_TRANSPORTLAYER_USERDATAGRAMPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_BINARYPROTOCOL
#include "BinaryProtocol.hpp"
#endif

namespace Elysium::Communication::Protocol::TransportLayer
{
	class ELYSIUM_COMMUNICATION_API UserDatagramProtocol final : public BinaryProtocol
	{
	public:
		UserDatagramProtocol(Transport::TransportBase& Transport, const Elysium::Core::uint16_t SourcePort, const Elysium::Core::uint16_t DestinationPort);
		UserDatagramProtocol(const UserDatagramProtocol& Source) = delete;
		UserDatagramProtocol(UserDatagramProtocol&& Right) noexcept = delete;
		virtual ~UserDatagramProtocol();

		UserDatagramProtocol& operator=(const UserDatagramProtocol& Source) = delete;
		UserDatagramProtocol& operator=(UserDatagramProtocol&& Right) noexcept = delete;

		void WriteData(const Elysium::Core::byte * Buffer, const size_t Length);

		const size_t ReadData(Elysium::Core::byte * Buffer, const size_t Length);
	private:
		static const Elysium::Core::uint16_t HEADERLENGTH;
		static const Elysium::Core::uint16_t MAXIMUMDATALENGTH;

		const Elysium::Core::uint16_t _SourcePort;
		const Elysium::Core::uint16_t _DestinationPort;
	};
}
#endif
