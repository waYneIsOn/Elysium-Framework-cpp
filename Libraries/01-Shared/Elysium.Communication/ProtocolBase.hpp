/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE
#define ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE

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
		virtual ~ProtocolBase();

		virtual void WriteBinary(const Elysium::Core::byte * Buffer, const size_t Length) = 0;

		virtual size_t ReadBinary(Elysium::Core::byte * Buffer, const size_t Length) = 0;
	protected:
		ProtocolBase(Transport::TransportBase& Transport);

		Transport::TransportBase& _Transport;
	};
}
#endif
