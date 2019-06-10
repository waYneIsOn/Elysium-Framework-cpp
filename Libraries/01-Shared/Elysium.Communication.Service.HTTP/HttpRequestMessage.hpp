/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPREQUESTMESSAGE
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPREQUESTMESSAGE

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPREQUESTHEADERS
#include "HttpRequestHeaders.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPMETHOD
#include "HttpMethod.hpp"
#endif

#ifndef _MAP_
#include <map>
#endif

#ifndef ELYSIUM_CORE_URI
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Uri.hpp"
#endif

#ifndef ELYSIUM_CORE_VERSION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Version.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				class ELYSIUM_COMMUNICATION_API HttpRequestMessage final
				{
				public:
					HttpRequestMessage(const HttpMethod& Method, const Elysium::Core::Uri& RequestUri);
					~HttpRequestMessage();

					const HttpMethod& GetMethod() const;
					const Elysium::Core::Uri& GetRequestUri() const;
					const Elysium::Core::Version& GetVersion() const;
				private:
					//HttpContent _Content;
					Headers::HttpRequestHeaders _Headers;
					HttpMethod _Method;
					std::map<Elysium::Core::String, Elysium::Core::String> _Properties;
					Elysium::Core::Uri _RequestUri;
					Elysium::Core::Version _Version;
				};
			}
		}
	}
}
#endif
