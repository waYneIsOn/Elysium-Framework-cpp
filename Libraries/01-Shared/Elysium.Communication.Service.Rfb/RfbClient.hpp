/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_RFB_RFBCLIENT
#define ELYSIUM_COMMUNICATION_SERVICE_RFB_RFBCLIENT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_KNOWNTCPPORT
#include "../Elysium.Communication/KnownTcpPort.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_REMOTEFRAMEBUFFERPROTOCOL
#include "../Elysium.Communication/RemoteFrameBufferProtocol.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_INTERNETPROTOCOLVERSION
#include "../Elysium.Communication/InternetProtocolVersion.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT
#include "../Elysium.Communication/TcpClient.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_ENDPOINT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/EndPoint.hpp"
#endif

namespace Elysium::Communication::Service::Rfb
{
	class ELYSIUM_COMMUNICATION_API RfbClient final
	{
	public:
		RfbClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion);
		RfbClient(const RfbClient& Source) = delete;
		RfbClient(RfbClient&& Right) noexcept = delete;
		~RfbClient();
	public:
		RfbClient& operator=(const RfbClient& Source) = delete;
		RfbClient& operator=(RfbClient&& Right) noexcept = delete;
	public:
		static constexpr Elysium::Core::uint16_t DefaultRfbPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::Rfb);
	public:
		void Connect(const Elysium::Core::Net::EndPoint& RemoteEndPoint);

		void Disconnect();
	private:
		Transport::TcpClient _Transport;
		Protocol::ApplicationLayer::RemoteFrameBufferProtocol _Protocol;
	};
}
#endif
