/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE
#include "ProtocolBase.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_STRINGBUILDER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/StringBuilder.hpp"
#endif

#ifndef ELYSIUM_CORE_COLLECTIONS_TEMPLATE_LISTOFBYTE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/ListOfByte.hpp"
#endif

namespace Elysium::Communication::Protocol
{
	class ELYSIUM_COMMUNICATION_API TextProtocol : public ProtocolBase
	{
	public:
		TextProtocol(Transport::TransportBase& Transport, const Elysium::Core::Text::Encoding& Encoding);
		TextProtocol(const TextProtocol& Source) = delete;
		TextProtocol(TextProtocol&& Right) noexcept = delete;
		virtual ~TextProtocol();

		TextProtocol& operator=(const TextProtocol& Source) = delete;
		TextProtocol& operator=(TextProtocol&& Right) noexcept = delete;

		virtual void WriteString(const Elysium::Core::Utf8String& Value);

		const Elysium::Core::Utf8String ReadLine();
	protected:
		const Elysium::Core::Text::Encoding& _Encoding;
		const static size_t _ReadBufferSize = 1024;
		Elysium::Core::byte _ReadBuffer[1024];
		Elysium::Core::Collections::Template::List<Elysium::Core::byte> _TotalReadBuffer = Elysium::Core::Collections::Template::List<Elysium::Core::byte>(_ReadBufferSize);
		size_t _IndexOfMessageEnd = -1;

		virtual void WriteBinary(const Elysium::Core::byte * Buffer, const size_t Length) override;

		virtual const size_t ReadBinary(Elysium::Core::byte * Buffer, const size_t Length) override;
	};
}
#endif
