/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_TCP_TCPCLIENT
#define ELYSIUM_COMMUNICATION_SERVICE_TCP_TCPCLIENT

#ifndef ELYSIUM_COMMUNICATION_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_SOCKETTRANSPORT
#include "SocketTransport.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL
#include "TextProtocol.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Tcp
			{
				class ELYSIUM_COMMUNICATION_API TcpClient final
				{
				public:
					TcpClient();
					virtual ~TcpClient();

					void Connect(Elysium::Core::String& Host, int Port);
					void Close();
				private:
					Elysium::Core::Net::Sockets::Socket _Socket;
					Elysium::Communication::Transport::SocketTransport _Transport;
					Elysium::Communication::Protocol::TextProtocol _Protocol;
				};
			}
		}
	}
}
#endif
