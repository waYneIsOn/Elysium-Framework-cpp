/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE
#define ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TRANSPORTBASE
#include "TransportBase.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

namespace Elysium::Communication::Protocol
{
	class ELYSIUM_COMMUNICATION_API ProtocolBase
	{
	public:
		ProtocolBase(const ProtocolBase& Source) = delete;
		ProtocolBase(ProtocolBase&& Right) noexcept = delete;
		virtual ~ProtocolBase();

		ProtocolBase& operator=(const ProtocolBase& Source) = delete;
		ProtocolBase& operator=(ProtocolBase&& Right) noexcept = delete;
	protected:
		ProtocolBase(Transport::TransportBase& Transport);
		//ProtocolBase(ProtocolBase& UnderlyingProtocol);

		Transport::TransportBase& _Transport;

		virtual void WriteBinary(const Elysium::Core::byte * Buffer, const size_t Length) = 0;

		virtual const size_t ReadBinary(Elysium::Core::byte * Buffer, const size_t Length) = 0;
	};
}
#endif
