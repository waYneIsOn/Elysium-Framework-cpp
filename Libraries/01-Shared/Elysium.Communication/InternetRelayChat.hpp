/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_INTERNETRELAYCHAT
#define ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_INTERNETRELAYCHAT

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
	class ELYSIUM_COMMUNICATION_API InternetRelayChat final : public TextProtocol
	{
	public:
		InternetRelayChat(Transport::TransportBase& Transport);
		InternetRelayChat(const InternetRelayChat& Source) = delete;
		InternetRelayChat(InternetRelayChat&& Right) noexcept = delete;
		virtual ~InternetRelayChat();

		InternetRelayChat& operator=(const InternetRelayChat& Source) = delete;
		InternetRelayChat& operator=(InternetRelayChat&& Right) noexcept = delete;

		// Requests the server to display the help file. This command is not formally defined in an RFC, but is in use by most major IRC daemons.
		const Elysium::Core::Utf8String WriteHelp();

		// Tell the server that we're about to disconnect
		void WriteQuit(const Elysium::Core::Utf8String& Message);
	private:
		static const Elysium::Core::Utf8String NEWLINE;
	};
}
#endif
