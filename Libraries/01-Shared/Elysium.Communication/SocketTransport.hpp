/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_SOCKETTRANSPORT
#define ELYSIUM_COMMUNICATION_TRANSPORT_SOCKETTRANSPORT

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
			class ELYSIUM_COMMUNICATION_API SocketTransport final : public StreamTransport
			{
			public:
				SocketTransport(Elysium::Core::Net::Sockets::Socket* Socket);
				~SocketTransport();

				const Elysium::Core::Net::Sockets::Socket* GetSocket() const;
			private:
				const Elysium::Core::Net::Sockets::Socket* _Socket;

				Elysium::Core::Net::Sockets::NetworkStream _InputNetworkStream;
				Elysium::Core::Net::Sockets::NetworkStream _OutputNetworkStream;
			};
		}
	}
}
#endif
