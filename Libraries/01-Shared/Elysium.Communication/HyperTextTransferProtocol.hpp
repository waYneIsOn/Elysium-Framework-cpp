/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_HYPERTEXTTRANSFERPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_HYPERTEXTTRANSFERPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL
#include "TextProtocol.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_STRINGBUILDER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/StringBuilder.hpp"
#endif

namespace Elysium::Communication::Protocol::ApplicationLayer
{
	class ELYSIUM_COMMUNICATION_API HyperTextTransferProtocol final : public TextProtocol
	{
	public:
		HyperTextTransferProtocol(Transport::TransportBase& Transport);
		HyperTextTransferProtocol(const HyperTextTransferProtocol& Source) = delete;
		HyperTextTransferProtocol(HyperTextTransferProtocol&& Right) noexcept = delete;
		virtual ~HyperTextTransferProtocol();

		HyperTextTransferProtocol& operator=(const HyperTextTransferProtocol& Source) = delete;
		HyperTextTransferProtocol& operator=(HyperTextTransferProtocol&& Right) noexcept = delete;

		Elysium::Core::Utf8String ReadResponseHeader();
		void ReadResponseContent(const size_t ContentLength, Elysium::Core::Collections::Template::List<Elysium::Core::byte>* Value);
		bool ReadResponseContentChunk(Elysium::Core::Collections::Template::List<Elysium::Core::byte>& Value);
	};
}
#endif
