/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_BINARYPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_BINARYPROTOCOL

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE
#include "ProtocolBase.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Protocol
		{
			class ELYSIUM_COMMUNICATION_API BinaryProtocol final : public ProtocolBase
			{
			public:
				BinaryProtocol(Transport::TransportBase& Transport);
				~BinaryProtocol();

				virtual void WriteBinary(const Elysium::Core::byte * Buffer, const size_t Length) override;

				virtual size_t ReadBinary(Elysium::Core::byte * Buffer, const size_t Length) override;
			};
		}
	}
}
#endif
