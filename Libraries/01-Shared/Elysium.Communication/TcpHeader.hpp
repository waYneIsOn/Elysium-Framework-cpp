/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TRANSPORTLAYER_TCPHEADER
#define ELYSIUM_COMMUNICATION_PROTOCOL_TRANSPORTLAYER_TCPHEADER

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
	class ELYSIUM_COMMUNICATION_API TcpHeader final
	{
	public:
		TcpHeader();
		TcpHeader(const TcpHeader& Source) = delete;
		TcpHeader(TcpHeader&& Right) noexcept = delete;
		~TcpHeader();

		TcpHeader& operator=(const TcpHeader& Source) = delete;
		TcpHeader& operator=(TcpHeader&& Right) noexcept = delete;

		static constexpr Elysium::Core::uint8_t MINIMUMHEADERSIZE = 20;

		const Elysium::Core::uint16_t GetSourcePort() const;

		const Elysium::Core::uint16_t GetDestinationPort() const;

		const Elysium::Core::uint32_t GetSequenceNumber() const;

		const Elysium::Core::uint32_t GetAcknowledgmentNumber() const;

		const Elysium::Core::uint8_t GetHeaderLength() const;

		const Elysium::Core::uint8_t GetReserved() const;

		const bool GetNonceFlag() const;

		const bool GetCongestionWindowReducedFlag() const;

		// ToDo: flags

		const Elysium::Core::uint16_t GetWindowSize() const;

		const Elysium::Core::uint16_t GetChecksum() const;

		const Elysium::Core::uint16_t GetUrgentPointer() const;
	private:
		Elysium::Core::byte _Data[MINIMUMHEADERSIZE];
	};
}
#endif
