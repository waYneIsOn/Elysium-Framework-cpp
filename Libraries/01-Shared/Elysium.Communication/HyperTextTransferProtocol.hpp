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

namespace Elysium::Communication::Protocol
{
	class ELYSIUM_COMMUNICATION_API HyperTextTransferProtocol final : public TextProtocol
	{
	public:
		HyperTextTransferProtocol(Transport::TransportBase& Transport);
		HyperTextTransferProtocol(Transport::TransportBase& Transport, const Elysium::Core::Text::Encoding& Encoding);
		~HyperTextTransferProtocol();

		Elysium::Core::String ReadResponseHeader();
		void ReadResponseContent(const size_t ContentLength, Elysium::Core::Collections::Template::List<Elysium::Core::Byte>* Value);
		bool ReadResponseContentChunk(Elysium::Core::Collections::Template::List<Elysium::Core::Byte>* Value);
	};
}
#endif
