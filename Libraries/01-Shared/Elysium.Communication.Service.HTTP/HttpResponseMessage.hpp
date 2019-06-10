/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPRESPONSEMESSAGE
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPRESPONSEMESSAGE

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPREQUESTMESSAGE
#include "HttpRequestMessage.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				class ELYSIUM_COMMUNICATION_API HttpResponseMessage final
				{
				public:
					HttpResponseMessage(const HttpRequestMessage* Request);
					~HttpResponseMessage();
				private:
					const HttpRequestMessage* _Request;

					//Headers::HttpResponseHeaders _Headers;
				};
			}
		}
	}
}
#endif
