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

					static void ParseRequestMessage(const HttpClient* Client, const HttpRequestMessage* Request, Elysium::Core::String* Output);
					static void ParseResponseMessageHeader(const HttpClient* Client, const Elysium::Core::String* CompleteResponseHeader, HttpResponseMessage* Response);
				private:
					HttpMessageParser();

					static const Elysium::Core::String ENDOFMESSAGEHEADER;
					static const Elysium::Core::String ENDOFCHUNKEDCONTENTBEFOREFOOTER;

					static const Elysium::Core::String MIMETYPE_APPLICATION;
					static const Elysium::Core::String MIMETYPE_AUDIO;
					static const Elysium::Core::String MIMETYPE_CHEMICAL;
					static const Elysium::Core::String MIMETYPE_DRAWING;
					static const Elysium::Core::String MIMETYPE_IMAGE;
					static const Elysium::Core::String MIMETYPE_MESSAGE;
					static const Elysium::Core::String MIMETYPE_MODEL;
					static const Elysium::Core::String MIMETYPE_MULTIPART;
					static const Elysium::Core::String MIMETYPE_TEXT;
					static const Elysium::Core::String MIMETYPE_VIDEO;
					static const Elysium::Core::String MIMETYPE_WORKBOOK;
					static const Elysium::Core::String MIMETYPE_XCONFERENCE;
					static const Elysium::Core::String MIMETYPE_XWORLD;
				};
			}
		}
	}
}
#endif
