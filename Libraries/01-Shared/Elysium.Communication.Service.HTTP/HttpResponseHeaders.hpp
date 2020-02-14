/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPRESPONSEHEADERS
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPRESPONSEHEADERS

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPHEADERS
#include "HttpHeaders.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_AUTHENTICATIONHEADERVALUE
#include "AuthenticationHeaderValue.hpp"
#endif

namespace Elysium::Communication::Service::Http::Headers
{
	class ELYSIUM_COMMUNICATION_API HttpResponseHeaders final : public HttpHeaders
	{
	public:
		HttpResponseHeaders();
		HttpResponseHeaders(const HttpResponseHeaders& Source);
		HttpResponseHeaders(HttpResponseHeaders&& Right) noexcept;
		virtual ~HttpResponseHeaders();

		HttpResponseHeaders& operator=(const HttpResponseHeaders& Source);
		HttpResponseHeaders& operator=(HttpResponseHeaders&& Right) noexcept;
	};
}
#endif
