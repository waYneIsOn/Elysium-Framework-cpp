/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCLIENT
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCLIENT

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_URI
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Uri.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT
#include "../Elysium.Communication/TcpClient.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL
#include "../Elysium.Communication/TextProtocol.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPREQUESTMESSAGE
#include "HttpRequestMessage.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPRESPONSEMESSAGE
#include "HttpResponseMessage.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCOMPLETIONOPTION
#include "HttpCompletionOption.hpp"
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
					HttpClient(const Elysium::Core::Uri& Uri);
					~HttpClient();

					void SendRequest(const HttpRequestMessage& Request);
					//HttpResponseMessage ReceiveResponse(const HttpRequestMessage& RequestMessage, const HttpCompletionOption CompletionOption);
				private:
					/*
					Core::Net::Sockets::Socket _Socket;
					Transport::TcpClient _Client;
					Protocol::TextProtocol _Protocol;
					*/
				};
			}
		}
	}
}
#endif
