/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_USERDATAGRAMPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_USERDATAGRAMPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE
#include "ProtocolBase.hpp"
#endif

namespace Elysium::Communication::Protocol
{
	class ELYSIUM_COMMUNICATION_API UserDatagramProtocol final : public ProtocolBase
	{
	public:
		UserDatagramProtocol(Transport::TransportBase& Transport);
		UserDatagramProtocol(const UserDatagramProtocol& Source) = delete;
		UserDatagramProtocol(UserDatagramProtocol&& Right) noexcept = delete;
		virtual ~UserDatagramProtocol();

		UserDatagramProtocol& operator=(const UserDatagramProtocol& Source) = delete;
		UserDatagramProtocol& operator=(UserDatagramProtocol&& Right) noexcept = delete;
	};
}
#endif
