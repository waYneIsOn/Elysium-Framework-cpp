/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPLISTENER
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPLISTENER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

namespace Elysium::Communication::Service::Http
{
	class ELYSIUM_COMMUNICATION_API HttpListener final
	{
	public:
		HttpListener();
		HttpListener(const HttpListener& Source) = delete;
		HttpListener(HttpListener&& Right) noexcept = delete;
		~HttpListener();

		HttpListener& operator=(const HttpListener& Source) = delete;
		HttpListener& operator=(HttpListener&& Right) noexcept = delete;
	private:

	};
}
#endif
