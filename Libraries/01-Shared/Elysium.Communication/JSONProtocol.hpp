/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
/*
#pragma once

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_JSONPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_JSONPROTOCOL

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL
#include "TextProtocol.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_STRINGBUILDER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/StringBuilder.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Protocol
		{
			class ELYSIUM_COMMUNICATION_API JSONProtocol final : public TextProtocol
			{
			public:
				JSONProtocol(Transport::TransportBase& Transport);
				~JSONProtocol();

				virtual void WriteBinary(const Elysium::Core::byte * Buffer, const size_t Length) override;

				virtual size_t ReadBinary(Elysium::Core::byte * Buffer, const size_t Length) override;
			};
		}
	}
}
#endif
*/