/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPREQUESTHEADERS
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPREQUESTHEADERS

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPHEADERS
#include "HttpHeaders.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_AUTHENTICATIONHEADERVALUE
#include "AuthenticationHeaderValue.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				namespace Headers
				{
					class ELYSIUM_COMMUNICATION_API HttpRequestHeaders final : public HttpHeaders
					{
					public:
						HttpRequestHeaders();
						HttpRequestHeaders(const HttpRequestHeaders& Source);
						HttpRequestHeaders(HttpRequestHeaders&& Right) noexcept;
						virtual ~HttpRequestHeaders();

						HttpRequestHeaders& operator=(const HttpRequestHeaders& Source);
						HttpRequestHeaders& operator=(HttpRequestHeaders&& Right) noexcept;

						const AuthenticationHeaderValue& GetAuthorization() const;
						const Elysium::Core::String& GetFrom() const;
						const Elysium::Core::String& GetHost() const;

						void SetAuthorization(const AuthenticationHeaderValue& Value);
						void SetFrom(const Elysium::Core::String& Value);
						void SetHost(const Elysium::Core::String& Value);
						/*
						Accept
						AcceptCharset
						AcceptEncoding
						AcceptLanguage
						Authorization
						CacheControl
						Connection
						ConnectionClose
						Date
						Expect
						ExpectContinue
						From
						Host
						IfMatch
						IfModifiedSince
						IfNoneMatch
						IfRagen
						IfUnmodifiedSince
						MaxForwards
						Pargma
						ProxyAuthorization
						Range
						Referrer
						TE
						Trailer
						TransferEcndoing
						TransferEncodingChunked
						Upgrade
						UserAgent
						Via
						Warning
						*/
					private:
						AuthenticationHeaderValue _Authorization;
						Elysium::Core::String _From;
						Elysium::Core::String _Host;
					};
				}
			}
		}
	}
}
#endif
