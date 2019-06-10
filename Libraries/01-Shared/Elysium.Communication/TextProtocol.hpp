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

#ifndef ELYSIUM_CORE_TEXT_STRINGBUILDER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/StringBuilder.hpp"
#endif

#ifndef _STRING_
#include <string>
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

				virtual size_t ReadString(Elysium::Core::String* Value) override;
			private:
				Elysium::Core::Text::Encoding _Encoding;
				Elysium::Core::Text::StringBuilder _MessageBuilder = Elysium::Core::Text::StringBuilder(1024);
				Elysium::Core::byte _ReadBuffer[1024];
				size_t _ReadBufferSize = 1024;
				size_t _IndexOfMessageEnd = std::wstring::npos;
			};
		}
	}
}
#endif
