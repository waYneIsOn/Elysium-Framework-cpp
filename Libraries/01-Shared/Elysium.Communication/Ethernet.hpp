/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_DATALINKLAYER_ETHERNETFRAME
#define ELYSIUM_COMMUNICATION_PROTOCOL_DATALINKLAYER_ETHERNETFRAME

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_BINARYPROTOCOL
#include "BinaryProtocol.hpp"
#endif

namespace Elysium::Communication::Protocol::DataLinkLayer
{
	/*
	class ELYSIUM_COMMUNICATION_API Ethernet final : public BinaryProtocol
	{
	public:
		Ethernet(Transport::TransportBase& Transport);
		Ethernet(const Ethernet& Source) = delete;
		Ethernet(Ethernet&& Right) noexcept = delete;
		virtual ~Ethernet();

		Ethernet& operator=(const Ethernet& Source) = delete;
		Ethernet& operator=(Ethernet&& Right) noexcept = delete;
	private:
	};
	*/
}
#endif
