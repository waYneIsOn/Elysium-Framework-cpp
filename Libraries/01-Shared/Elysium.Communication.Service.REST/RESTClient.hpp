/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_REST_RESTCLIENT
#define ELYSIUM_COMMUNICATION_SERVICE_REST_RESTCLIENT

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCLIENT
#include "../Elysium.Communication.Service.HTTP/HttpClient.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_JSONPROTOCOL
#include "../Elysium.Communication/JSONProtocol.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace REST
			{
				class ELYSIUM_COMMUNICATION_API RESTClient final
				{
				public:
					RESTClient();
					~RESTClient();

					void Connect(const Elysium::Core::Uri& Uri);
					void Disconnect();

					void TestGET(const Elysium::Core::Uri& Uri);
				private:
					Elysium::Communication::Service::Http::HttpClient _HttpClient;
				};
			}
		}
	}
}
#endif
