/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_RAW_PORTSCANNER
#define ELYSIUM_COMMUNICATION_SERVICE_RAW_PORTSCANNER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

namespace Elysium::Communication::Service::Raw
{
	class ELYSIUM_COMMUNICATION_API PortScanner final
	{
	public:
		PortScanner();
		PortScanner(const PortScanner& Source) = delete;
		PortScanner(PortScanner&& Right) noexcept = delete;
		~PortScanner();

		PortScanner& operator=(const PortScanner& Source) = delete;
		PortScanner& operator=(PortScanner&& Right) noexcept = delete;
		/*
		// 3-way-handshake
		void TcpConnectScan();

		// syn
		void TcpHalfOpenScan();

		// ack
		void TcpAckScan();

		// fin
		void TcpFinScan();

		// ...
		void UdpScan();
		*/
	private:
		//const RawClient _RawClient;
	};
}
#endif
