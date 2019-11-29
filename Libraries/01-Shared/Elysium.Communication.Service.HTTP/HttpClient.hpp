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

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_HYPERTEXTTRANSFERPROTOCOL
#include "../Elysium.Communication/HyperTextTransferProtocol.hpp"
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

#ifndef ELYSIUM_CORE_DECIMAL
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Decimal.hpp"
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

					void Connect(const Elysium::Core::Uri& Uri);
					void Disconnect();

					HttpResponseMessage Get(HttpRequestMessage& Request);

					void SendRequest(HttpRequestMessage& Request);
					HttpResponseMessage ReceiveResponse(HttpRequestMessage& Request);
					HttpResponseMessage ReceiveResponse(HttpRequestMessage& Request, const HttpCompletionOption CompletionOption);
				private:
					Core::Net::Sockets::Socket _OwnedSocket;
					Transport::TcpClient _OwnedClient;
					Protocol::HyperTextTransferProtocol _OwnedProtocol;

					Core::Net::Sockets::Socket* _Socket;
					Transport::TransportBase* _Client;

					HttpResponseMessage* _PreviousResponse;
					HttpCompletionOption _PreviousCompletionOption;

					void ReceiveResponseContent(HttpResponseMessage* Response);
				};
			}
		}
	}
}
#endif
