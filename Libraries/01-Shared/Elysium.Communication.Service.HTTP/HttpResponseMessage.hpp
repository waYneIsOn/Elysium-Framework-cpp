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

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPRESPONSEHEADERS
#include "HttpResponseHeaders.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPSTATUSCODE
#include "HttpStatusCode.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCONTENT
#include "HttpContent.hpp"
#endif

namespace Elysium::Communication::Service::Http
{
	class ELYSIUM_COMMUNICATION_API HttpResponseMessage final
	{
		friend class HttpClient;
		friend class HttpMessageParser;
	public:
		HttpResponseMessage(HttpRequestMessage& Request);
		HttpResponseMessage(const HttpResponseMessage& Source);
		HttpResponseMessage(HttpResponseMessage&& Right) noexcept;
		~HttpResponseMessage();

		HttpResponseMessage& operator=(const HttpResponseMessage& Source);
		HttpResponseMessage& operator=(HttpResponseMessage&& Right) noexcept;

		const HttpRequestMessage& GetRequest() const;
		const Elysium::Core::Version& GetVersion() const;
		const HttpStatusCode GetStatusCode() const;
		const Elysium::Core::String& GetReasonPhase() const;
		const Headers::HttpResponseHeaders& GetHeaders() const;
		const bool GetIsSuccessStatusCode() const;
		const HttpContent* GetContent() const;

		/*
		const AuthenticationHeaderValue& GetAuthorization() const;

		void SetAuthorization(const AuthenticationHeaderValue& Value);
		/*
		AcceptRanges
		Age
		CacheControl
		Connection
		ConnectionClose
		Date
		ETag
		Location
		Pargma
		ProxyAuthenticate
		RetryAfter
		Server
		Trailer
		TransferEncoding
		TransferEncodingChunked
		Upgrade
		Vary
		Via
		Warning
		WwwAuthenticate
		*/
	private:
		HttpRequestMessage _Request;

		Elysium::Core::Version _Version;
		HttpStatusCode _StatusCode;
		Elysium::Core::String _ReasonPhrase;
		Headers::HttpResponseHeaders _Headers;
		HttpContent* _Content;
	};
}
#endif
