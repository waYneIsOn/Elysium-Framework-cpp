/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL

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
			class ELYSIUM_COMMUNICATION_API TextProtocol final : public ProtocolBase
			{
			public:
				TextProtocol(Transport::TransportBase* Transport);
				TextProtocol(Transport::TransportBase* Transport, const Elysium::Core::Text::Encoding* Encoding);
				~TextProtocol();

				virtual void WriteString(const Elysium::Core::String* Value) override;

				virtual void ReadString(Elysium::Core::String* Value) override;
			private:
				Elysium::Core::Text::Encoding _Encoding;
			};
		}
	}
}
#endif
