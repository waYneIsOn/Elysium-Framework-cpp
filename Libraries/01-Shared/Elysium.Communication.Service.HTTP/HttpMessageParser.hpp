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

namespace Elysium::Communication::Service::Http
{
	class HttpMessageParser final
	{
	public:
		~HttpMessageParser();

		static Elysium::Core::String ParseRequestMessage(HttpRequestMessage& Request);

		static HttpResponseMessage ParseResponseMessageHeader(HttpRequestMessage& Request, const Elysium::Core::String& CompleteResponseHeader);
	private:
		HttpMessageParser();
	};
}
#endif
