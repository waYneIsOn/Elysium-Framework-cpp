/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCLIENT
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCLIENT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_URI
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Uri.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT
#include "../Elysium.Communication/TcpClient.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_HYPERTEXTTRANSFERPROTOCOL
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

namespace Elysium::Communication::Service::Http
{
	class ELYSIUM_COMMUNICATION_API HttpClient final
	{
	public:
		HttpClient();
		HttpClient(const HttpClient& Source) = delete;
		HttpClient(HttpClient&& Right) noexcept = delete;
		~HttpClient();

		HttpClient& operator=(const HttpClient& Source) = delete;
		HttpClient& operator=(HttpClient&& Right) noexcept = delete;

		Headers::HttpRequestHeaders& GetDefaultRequestHeaders();

		void SetBaseAddress(const Elysium::Core::Uri& BaseAddress);

		void Connect();
		void Disconnect();

		HttpResponseMessage Delete(const Elysium::Core::String& Path, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);
		HttpResponseMessage Delete(const Elysium::Core::String& Path, HttpResponseMessage& PreviousResponse, const HttpCompletionOption CompletionOption);

		HttpResponseMessage Get(const Elysium::Core::String& Path, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);
		HttpResponseMessage Get(const Elysium::Core::String& Path, HttpResponseMessage& PreviousResponse, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);

		HttpResponseMessage Options(const Elysium::Core::String& Path, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);
		HttpResponseMessage Options(const Elysium::Core::String& Path, HttpResponseMessage& PreviousResponse, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);

		HttpResponseMessage Patch(const Elysium::Core::String& Path, const HttpContent& Content, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);
		HttpResponseMessage Patch(const Elysium::Core::String& Path, const HttpContent& Content, HttpResponseMessage& PreviousResponse, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);

		HttpResponseMessage Post(const Elysium::Core::String& Path, const HttpContent& Content, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);
		HttpResponseMessage Post(const Elysium::Core::String& Path, const HttpContent& Content, HttpResponseMessage& PreviousResponse, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);

		HttpResponseMessage Put(const Elysium::Core::String& Path, const HttpContent& Content, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);
		HttpResponseMessage Put(const Elysium::Core::String& Path, const HttpContent& Content, HttpResponseMessage& PreviousResponse, const HttpCompletionOption CompletionOption = HttpCompletionOption::ResponseContentRead);
	private:
		Core::Net::Sockets::Socket _OwnedSocket;
		Transport::TcpClient _OwnedClient;
		Protocol::ApplicationLayer::HyperTextTransferProtocol _OwnedProtocol;

		Headers::HttpRequestHeaders _DefaultRequestHeaders;

		Elysium::Core::Uri _BaseAddress;

		HttpCompletionOption _PreviousCompletionOption;

		void SendRequest(HttpRequestMessage& Request);
		HttpResponseMessage ReceiveResponse(HttpRequestMessage& Request, const HttpCompletionOption CompletionOption);
		HttpResponseMessage ReceiveResponse(HttpRequestMessage& Request, const HttpCompletionOption CompletionOption, HttpResponseMessage& PreviousResponse);
		void ReceiveResponseContent(HttpResponseMessage& Response);
	};
}
#endif
