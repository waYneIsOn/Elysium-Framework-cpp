/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPCONTENTHEADERS
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPCONTENTHEADERS

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPHEADERS
#include "HttpHeaders.hpp"
#endif

#ifndef _STDINT
#include <stdint.h>
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
					class ELYSIUM_COMMUNICATION_API HttpContentHeaders final : public HttpHeaders
					{
					public:
						HttpContentHeaders();
						HttpContentHeaders(const HttpContentHeaders& Source) = delete;
						HttpContentHeaders(HttpContentHeaders&& Right) noexcept = delete;
						virtual ~HttpContentHeaders();

						HttpContentHeaders& operator=(const HttpContentHeaders& Source) = delete;
						HttpContentHeaders& operator=(HttpContentHeaders&& Right) noexcept = delete;

						const int64_t GetContentLength() const;

						void SetContentLength(const int64_t Value);


						// Allow
						// ContentDisposition
						// ContentEncoding
						// ContentLanguage
						// ContentLength
						// ContentLocation
						// ContentMD5
						// ContentRange
						// ContentType
						// Expires
						// LastModified
					};
				}
			}
		}
	}
}
#endif
