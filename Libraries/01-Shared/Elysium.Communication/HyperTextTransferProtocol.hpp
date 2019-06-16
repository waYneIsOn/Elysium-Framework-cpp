/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_HYPERTEXTTRANSFERPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_HYPERTEXTTRANSFERPROTOCOL

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL
#include "TextProtocol.hpp"
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
			class ELYSIUM_COMMUNICATION_API HyperTextTransferProtocol final : public TextProtocol
			{
			public:
				HyperTextTransferProtocol(Transport::TransportBase* Transport);
				HyperTextTransferProtocol(Transport::TransportBase* Transport, const Elysium::Core::Text::Encoding* Encoding);
				~HyperTextTransferProtocol();

				void ReadResponseHeader(Elysium::Core::String* Value);
				void ReadResponseContent(const size_t ContentLength, Elysium::Core::Collections::Generic::List<Elysium::Core::Byte>* Value);
				void ReadResponseContent(const size_t ContentLength, Elysium::Core::String * Value);
			};
		}
	}
}
#endif
