/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT
#define ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_STREAMTRANSPORT
#include "StreamTransport.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_SOCKETS_SOCKET
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/Socket.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_SOCKETS_NETWORKSTREAM
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/NetworkStream.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Transport
		{
			class ELYSIUM_COMMUNICATION_API TcpClient final : public StreamTransport
			{
			public:
				TcpClient(Elysium::Core::Net::Sockets::Socket* Socket);
				virtual ~TcpClient();

				const Elysium::Core::Net::Sockets::Socket* GetSocket() const;

				void Connect(const Elysium::Core::String& Host, int Port);
				void Close();
			private:
				Elysium::Core::Net::Sockets::Socket* _Socket;

				Elysium::Core::Net::Sockets::NetworkStream _InputNetworkStream;
				Elysium::Core::Net::Sockets::NetworkStream _OutputNetworkStream;
			};
		}
	}
}
#endif
