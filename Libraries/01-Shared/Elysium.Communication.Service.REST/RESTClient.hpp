/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_REST_RESTCLIENT
#define ELYSIUM_COMMUNICATION_SERVICE_REST_RESTCLIENT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCLIENT
#include "../Elysium.Communication.Service.HTTP/HttpClient.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_JSONPROTOCOL
#include "../Elysium.Communication/JSONProtocol.hpp"
#endif

namespace Elysium::Communication::Service::Rest
{
	class ELYSIUM_COMMUNICATION_API RESTClient final
	{
	public:
		RESTClient();
		~RESTClient();

		void Connect(const Elysium::Core::Uri& Uri);
		void Disconnect();

		template <class T>
		T Get(const Elysium::Core::String& Path);

		void TestGET(const Elysium::Core::String& Path);
	private:
		Elysium::Communication::Service::Http::HttpClient _HttpClient;
	};

	template<class T>
	inline T RESTClient::Get(const Elysium::Core::String & Path)
	{
		return T();
	}
}
#endif
