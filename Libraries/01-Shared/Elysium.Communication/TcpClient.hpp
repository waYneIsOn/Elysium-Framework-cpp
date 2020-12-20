/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT
#define ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_STREAMTRANSPORT
#include "StreamTransport.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_INTERNETPROTOCOLVERSION
#include "InternetProtocolVersion.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_SOCKETS_SOCKET
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/Socket.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_SOCKETS_NETWORKSTREAM
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/NetworkStream.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_ENDPOINT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/EndPoint.hpp"
#endif

namespace Elysium::Communication::Transport
{
	class ELYSIUM_COMMUNICATION_API TcpClient final : public StreamTransport
	{
	public:
		TcpClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion);
		TcpClient(Elysium::Core::Net::Sockets::Socket&& ClientSocket);
		TcpClient(const TcpClient& Source) = delete;
		TcpClient(TcpClient&& Right) noexcept = delete;
		virtual ~TcpClient();

		TcpClient& operator=(const TcpClient& Source) = delete;
		TcpClient& operator=(TcpClient&& Right) noexcept = delete;

		virtual const bool GetIsOpen() const override;

		void Connect(const Elysium::Core::String& Host, int Port);
		void Connect(const Elysium::Core::Net::EndPoint& RemoteEndPoint);
		void Close();
	private:
		Elysium::Core::Net::Sockets::Socket _Socket;

		Elysium::Core::Net::Sockets::NetworkStream _InputNetworkStream;
		Elysium::Core::Net::Sockets::NetworkStream _OutputNetworkStream;
	};
}
#endif
