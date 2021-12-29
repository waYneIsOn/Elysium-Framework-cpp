/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPLISTENER
#define ELYSIUM_COMMUNICATION_TRANSPORT_TCPLISTENER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_TEMPLATE_CONTAINER_DELEGATE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Template/Delegate.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_STREAMTRANSPORT
#include "StreamTransport.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_INTERNETPROTOCOLVERSION
#include "InternetProtocolVersion.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_ENDPOINT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/EndPoint.hpp"
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

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT
#include "TcpClient.hpp"
#endif

namespace Elysium::Communication::Transport
{
	class ELYSIUM_COMMUNICATION_API TcpListener final : public StreamTransport
	{
	public:
		TcpListener(const Protocol::InternetLayer::InternetProtocolVersion IPVersion);
		TcpListener(const TcpListener& Source) = delete;
		TcpListener(TcpListener&& Right) noexcept = delete;
		virtual ~TcpListener();

		TcpListener& operator=(const TcpListener& Source) = delete;
		TcpListener& operator=(TcpListener&& Right) noexcept = delete;

		virtual const bool GetIsOpen() const override;

		void Start(const Elysium::Core::Net::EndPoint& LocalEndPoint, const Elysium::Core::int32_t Backlog);
		void Stop();

		Elysium::Core::Net::Sockets::Socket AcceptSocket();
		const TcpClient AcceptTcpClient();

		const Elysium::Core::IAsyncResult* BeginAcceptSocket(const Elysium::Core::Template::Container::Delegate<void, const Elysium::Core::IAsyncResult*>& Callback, void* State);
		Elysium::Core::Net::Sockets::Socket EndAcceptSocket(const Elysium::Core::IAsyncResult* Result);

		const Elysium::Core::IAsyncResult* BeginAcceptTcpClient(const Elysium::Core::Template::Container::Delegate<void, const Elysium::Core::IAsyncResult*>& Callback, void* State);
		const TcpClient EndAcceptTcpClient(const Elysium::Core::IAsyncResult* Result);
	private:
		Elysium::Core::Net::Sockets::Socket _Socket;

		Elysium::Core::Net::Sockets::NetworkStream _InputNetworkStream;
		Elysium::Core::Net::Sockets::NetworkStream _OutputNetworkStream;
	};
}
#endif
