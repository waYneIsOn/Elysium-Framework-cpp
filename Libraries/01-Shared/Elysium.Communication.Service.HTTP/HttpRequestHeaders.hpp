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
						virtual ~HttpRequestHeaders();

						const AuthenticationHeaderValue& GetAuthorization() const;
						const Elysium::Core::String& GetFrom() const;
						const Elysium::Core::String& GetHost() const;

						void SetAuthorization(const AuthenticationHeaderValue& Value);
						void SetFrom(const Elysium::Core::String& Value);
						void SetHost(const Elysium::Core::String& Value);
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
