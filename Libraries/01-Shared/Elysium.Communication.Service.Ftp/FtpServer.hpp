/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPSERVER
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPSERVER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_KNOWNTCPPORT
#include "../Elysium.Communication/KnownTcpPort.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPENCRYPTION
#include "FtpEncryption.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPLISTENER
#include "../Elysium.Communication/TcpListener.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_FILETRANSFERPROTOCOL
#include "../Elysium.Communication/FileTransferProtocol.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPTRANSFERMODE
#include "FtpTransferMode.hpp"
#endif

#ifndef ELYSIUM_CORE_THREADING_MANUALRESETEVENT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Threading/ManualResetEvent.hpp"
#endif

#ifndef _ATOMIC_
#include <atomic>
#endif

namespace Elysium::Communication::Service::Ftp
{
	class ELYSIUM_COMMUNICATION_API FtpServer final
	{
	public:
		FtpServer(const Protocol::InternetLayer::InternetProtocolVersion IPVersion);
		FtpServer(const FtpServer& Source) = delete;
		FtpServer(FtpServer&& Right) noexcept = delete;
		~FtpServer();

		FtpServer& operator=(const FtpServer& Source) = delete;
		FtpServer& operator=(FtpServer&& Right) noexcept = delete;

		static constexpr Elysium::Core::uint16_t DefaultFtpControlPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::FtpControl);
		static constexpr Elysium::Core::uint16_t DefaultFtpDataPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::FtpData);

		static constexpr Elysium::Core::uint16_t DefaultImplicitFtpsControlPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::FtpsControl);
		static constexpr Elysium::Core::uint16_t DefaultImplicitFtpsDataPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::FtpsData);

		void Start(const Elysium::Core::Net::EndPoint& LocalEndPoint, const Elysium::Core::int32_t Backlog);
		void Stop();
	private:
		Transport::TcpListener _ControlTransport;
		Protocol::ApplicationLayer::FileTransferProtocol _ControlProtocol;

		std::atomic<bool> _ShouldStop;
		Elysium::Core::Threading::ManualResetEvent _AcceptResetEvent;

		void TcpClientAcceptCallback(const Elysium::Core::IAsyncResult* Result);

		void ParseRequestMessage(const Elysium::Communication::Transport::TcpClient& Client, Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol& Protocol);
	};
}
#endif
