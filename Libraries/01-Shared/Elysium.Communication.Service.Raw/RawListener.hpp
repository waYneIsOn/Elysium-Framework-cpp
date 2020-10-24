/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_RAW_RAWLISTENER
#define ELYSIUM_COMMUNICATION_SERVICE_RAW_RAWLISTENER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_ENDPOINT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/EndPoint.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_SOCKETS_SOCKET
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/Socket.hpp"
#endif

namespace Elysium::Communication::Service::Raw
{
	class ELYSIUM_COMMUNICATION_API RawListener final
	{
	public:
		RawListener(const Elysium::Core::Net::Sockets::AddressFamily AddressFamily);
		RawListener(const RawListener& Source) = delete;
		RawListener(RawListener&& Right) noexcept = delete;
		~RawListener();

		RawListener& operator=(const RawListener& Source) = delete;
		RawListener& operator=(RawListener&& Right) noexcept = delete;

		void Bind(const Elysium::Core::Net::EndPoint & LocalEndPoint);

		const size_t Read(Elysium::Core::byte* Buffer, const size_t Count);
	private:
		Elysium::Core::Net::Sockets::Socket _Socket;
	};
}
#endif
