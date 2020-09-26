/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_BINARYPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_BINARYPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE
#include "ProtocolBase.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

namespace Elysium::Communication::Protocol
{
	class ELYSIUM_COMMUNICATION_API BinaryProtocol final : public ProtocolBase
	{
	public:
		BinaryProtocol(Transport::TransportBase& Transport);
		BinaryProtocol(const BinaryProtocol& Source) = delete;
		BinaryProtocol(BinaryProtocol&& Right) noexcept = delete;
		virtual ~BinaryProtocol();

		BinaryProtocol& operator=(const BinaryProtocol& Source) = delete;
		BinaryProtocol& operator=(BinaryProtocol&& Right) noexcept = delete;
	protected:
		virtual void WriteBinary(const Elysium::Core::byte * Buffer, const size_t Length) override;

		virtual const size_t ReadBinary(Elysium::Core::byte * Buffer, const size_t Length) override;
	};
}
#endif
