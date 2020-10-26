/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_UDPCLIENT
#define ELYSIUM_COMMUNICATION_TRANSPORT_UDPCLIENT

#ifdef _MSC_VER
#pragma once
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

#ifndef ELYSIUM_CORE_NET_ENDPOINT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/EndPoint.hpp"
#endif

namespace Elysium::Communication::Transport
{
	class ELYSIUM_COMMUNICATION_API UdpClient : public TransportBase
	{
	public:
		UdpClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion);
		UdpClient(const UdpClient& Source) = delete;
		UdpClient(UdpClient&& Right) noexcept = delete;
		virtual ~UdpClient();

		UdpClient& operator=(const UdpClient& Source) = delete;
		UdpClient& operator=(UdpClient&& Right) noexcept = delete;

		virtual const bool GetIsOpen() const override;

		void Connect(const Elysium::Core::Net::EndPoint& RemoteEndPoint);

		void Close();

		virtual void Write(const Elysium::Core::byte* Buffer, const size_t Length) override;

		virtual void Flush() override;

		virtual const size_t Read(Elysium::Core::byte* Buffer, const size_t Length) override;
	private:
		Elysium::Core::Net::Sockets::Socket _Socket;
	};
}
#endif
