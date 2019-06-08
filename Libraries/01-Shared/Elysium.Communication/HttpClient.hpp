/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCLIENT
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCLIENT

#ifndef ELYSIUM_COMMUNICATION_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_TCP_TCPCLIENT
#include "TcpClient.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				class ELYSIUM_COMMUNICATION_API HttpClient final
				{
				public:
					HttpClient();
					~HttpClient();
				private:
					Service::Tcp::TcpClient _Client;
				};
			}
		}
	}
}
#endif
