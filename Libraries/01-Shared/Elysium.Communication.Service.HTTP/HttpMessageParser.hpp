/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPMESSAGEPARSER
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPMESSAGEPARSER

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCLIENT
#include "HttpClient.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPREQUESTMESSAGE
#include "HttpRequestMessage.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPRESPONSEMESSAGE
#include "HttpResponseMessage.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				class HttpMessageParser final
				{
				public:
					~HttpMessageParser();

					static void ParseRequestMessage(const HttpClient* Client, const HttpRequestMessage& Request, Elysium::Core::String* Output);

					static void ParseResponseMessageHeader(const HttpClient* Client, const Elysium::Core::String* CompleteResponseHeader, HttpResponseMessage* Response);
				private:
					HttpMessageParser();
				};
			}
		}
	}
}
#endif
