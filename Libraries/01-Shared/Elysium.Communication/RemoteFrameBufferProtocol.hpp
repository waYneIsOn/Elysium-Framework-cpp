/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_REMOTEFRAMEBUFFERPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_REMOTEFRAMEBUFFERPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL
#include "TextProtocol.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

namespace Elysium::Communication::Protocol::ApplicationLayer
{
	class ELYSIUM_COMMUNICATION_API RemoteFrameBufferProtocol final : public TextProtocol
	{
	public:
		RemoteFrameBufferProtocol() = delete;
		RemoteFrameBufferProtocol(Transport::TransportBase & Transport);
		RemoteFrameBufferProtocol(const RemoteFrameBufferProtocol& Source) = delete;
		RemoteFrameBufferProtocol(RemoteFrameBufferProtocol&& Right) noexcept = delete;
		virtual ~RemoteFrameBufferProtocol();

		const Elysium::Core::String WriteProtocolVersionHandshake(const Elysium::Core::String& Value);
	public:
		RemoteFrameBufferProtocol& operator=(const RemoteFrameBufferProtocol& Source) = delete;
		RemoteFrameBufferProtocol& operator=(RemoteFrameBufferProtocol&& Right) noexcept = delete;
	};
}
#endif
