#pragma once
class InternetProtocol
{
};

/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_INTERNETPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_INTERNETPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_BINARYPROTOCOL
#include "BinaryProtocol.hpp"
#endif

namespace Elysium::Communication::Protocol::InternetLayer
{
	class ELYSIUM_COMMUNICATION_API InternetProtocol final : public BinaryProtocol
	{
	public:
		InternetProtocol(Transport::TransportBase& Transport, const Elysium::Core::uint8_t Version);
		InternetProtocol(const InternetProtocol& Source) = delete;
		InternetProtocol(InternetProtocol&& Right) noexcept = delete;
		virtual ~InternetProtocol();

		InternetProtocol& operator=(const InternetProtocol& Source) = delete;
		InternetProtocol& operator=(InternetProtocol&& Right) noexcept = delete;

		//void WriteData(const Elysium::Core::byte * Buffer, const size_t Length);

		//const size_t ReadData(Elysium::Core::byte * Buffer, const size_t Length);
	private:
		const Elysium::Core::uint8_t _Version;
	};
}
#endif
