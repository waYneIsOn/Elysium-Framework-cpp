/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TRANSPORTLAYER_TRANSMISSIONCONTROLPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_TRANSPORTLAYER_TRANSMISSIONCONTROLPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_BINARYPROTOCOL
#include "BinaryProtocol.hpp"
#endif

namespace Elysium::Communication::Protocol::TransportLayer
{
	class ELYSIUM_COMMUNICATION_API TransmissionControlProtocol final : public BinaryProtocol
	{
	public:
		TransmissionControlProtocol(Transport::TransportBase& Transport, const Elysium::Core::uint16_t SourcePort, const Elysium::Core::uint16_t DestinationPort);
		TransmissionControlProtocol(const TransmissionControlProtocol& Source) = delete;
		TransmissionControlProtocol(TransmissionControlProtocol&& Right) noexcept = delete;
		virtual ~TransmissionControlProtocol();

		TransmissionControlProtocol& operator=(const TransmissionControlProtocol& Source) = delete;
		TransmissionControlProtocol& operator=(TransmissionControlProtocol&& Right) noexcept = delete;
	private:
		const Elysium::Core::uint16_t _SourcePort;
		const Elysium::Core::uint16_t _DestinationPort;
		/*
		const Elysium::Core::uint32_t _SequenceNumber;
		const Elysium::Core::uint32_t _AcknowledgmentNumber;
		const Elysium::Core::uint32_t _HeaderLength;
		const Elysium::Core::byte _Flags;
		const Elysium::Core::uint16_t _WindowLength;	// number of octets in the tcp header
		const Elysium::Core::uint16_t _CrcChecksum;
		const Elysium::Core::uint16_t _UrgentPointer;
		*/
	};
}
#endif
