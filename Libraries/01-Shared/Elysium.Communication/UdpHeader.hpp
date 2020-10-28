/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TRANSPORTLAYER_UDPHEADER
#define ELYSIUM_COMMUNICATION_PROTOCOL_TRANSPORTLAYER_UDPHEADER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

#ifndef ELYSIUM_CORE_BYTE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Byte.hpp"
#endif

namespace Elysium::Communication::Protocol::TransportLayer
{
	class ELYSIUM_COMMUNICATION_API UdpHeader final
	{
	public:
		UdpHeader();
		UdpHeader(const UdpHeader& Source) = delete;
		UdpHeader(UdpHeader&& Right) noexcept = delete;
		~UdpHeader();

		UdpHeader& operator=(const UdpHeader& Source) = delete;
		UdpHeader& operator=(UdpHeader&& Right) noexcept = delete;

		static constexpr Elysium::Core::uint8_t HEADERSIZE = 8;

		const Elysium::Core::uint16_t GetSourcePort() const;

		const Elysium::Core::uint16_t GetDestinationPort() const;

		const Elysium::Core::uint32_t GetTotalLength() const;

		const Elysium::Core::uint16_t GetChecksum() const;
	private:
		Elysium::Core::byte _Data[HEADERSIZE];
	};
}
#endif
