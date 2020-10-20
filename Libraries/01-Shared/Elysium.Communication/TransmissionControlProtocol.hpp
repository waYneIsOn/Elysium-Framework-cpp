/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TRANSMISSIONCONTROLPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_TRANSMISSIONCONTROLPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE
#include "ProtocolBase.hpp"
#endif

namespace Elysium::Communication::Protocol
{
	class ELYSIUM_COMMUNICATION_API TransmissionControlProtocol final : public ProtocolBase
	{
	public:
		TransmissionControlProtocol(Transport::TransportBase& Transport);
		TransmissionControlProtocol(const TransmissionControlProtocol& Source) = delete;
		TransmissionControlProtocol(TransmissionControlProtocol&& Right) noexcept = delete;
		virtual ~TransmissionControlProtocol();

		TransmissionControlProtocol& operator=(const TransmissionControlProtocol& Source) = delete;
		TransmissionControlProtocol& operator=(TransmissionControlProtocol&& Right) noexcept = delete;
	};
}
#endif
