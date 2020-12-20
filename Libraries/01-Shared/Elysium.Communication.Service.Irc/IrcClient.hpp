/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_IRC_IRCCLIENT
#define ELYSIUM_COMMUNICATION_SERVICE_IRC_IRCCLIENT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT
#include "../Elysium.Communication/TcpClient.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_INTERNETRELAYCHAT
#include "../Elysium.Communication/InternetRelayChat.hpp"
#endif

namespace Elysium::Communication::Service::Irc
{
	class ELYSIUM_COMMUNICATION_API IrcClient final
	{
	public:
		IrcClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion);
		IrcClient(const IrcClient& Source) = delete;
		IrcClient(IrcClient&& Right) noexcept = delete;
		~IrcClient();

		IrcClient& operator=(const IrcClient& Source) = delete;
		IrcClient& operator=(IrcClient&& Right) noexcept = delete;

		static const Elysium::Core::uint16_t DefaultIrcPort;

		void Connect(const Elysium::Core::Net::EndPoint& RemoteEndPoint);
		void Disconnect();

		void Test();
	private:
		Transport::TcpClient _Transport;
		Protocol::ApplicationLayer::InternetRelayChat _Protocol;
	};
}
#endif
