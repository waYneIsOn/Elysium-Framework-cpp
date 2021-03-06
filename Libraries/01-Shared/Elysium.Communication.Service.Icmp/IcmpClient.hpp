/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_ICMP_ICMPCLIENT
#define ELYSIUM_COMMUNICATION_SERVICE_ICMP_ICMPCLIENT

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

namespace Elysium::Communication::Service::Icmp
{
	class ELYSIUM_COMMUNICATION_API IcmpClient final
	{
	public:
		IcmpClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion);
		IcmpClient(const IcmpClient& Source) = delete;
		IcmpClient(IcmpClient&& Right) noexcept = delete;
		~IcmpClient();

		IcmpClient& operator=(const IcmpClient& Source) = delete;
		IcmpClient& operator=(IcmpClient&& Right) noexcept = delete;

		void Initialize();
		void Close();

		void Ping(const Elysium::Core::Net::EndPoint& RemoteEndPoint);

	private:
		Elysium::Core::Net::Sockets::Socket _Socket;
		//Transport::TcpClient _Transport;
		//Protocol::ApplicationLayer::InternetRelayChat _Protocol;
	};
}
#endif
