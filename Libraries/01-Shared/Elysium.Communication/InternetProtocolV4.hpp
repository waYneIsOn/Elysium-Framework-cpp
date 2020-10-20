/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE
#include "ProtocolBase.hpp"
#endif

namespace Elysium::Communication::Protocol
{
	class ELYSIUM_COMMUNICATION_API InternetProtocolV4 final : public ProtocolBase
	{
	public:
		InternetProtocolV4(Transport::TransportBase& Transport);
		InternetProtocolV4(const InternetProtocolV4& Source) = delete;
		InternetProtocolV4(InternetProtocolV4&& Right) noexcept = delete;
		virtual ~InternetProtocolV4();

		InternetProtocolV4& operator=(const InternetProtocolV4& Source) = delete;
		InternetProtocolV4& operator=(InternetProtocolV4&& Right) noexcept = delete;
	private:
		static const Elysium::Core::int32_t VERSION;
	};
}
#endif
