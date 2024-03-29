/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPCLIENT
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPCLIENT

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

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT
#include "../Elysium.Communication/TcpClient.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_FILETRANSFERPROTOCOL
#include "../Elysium.Communication/FileTransferProtocol.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPRESPONSEMESSAGE
#include "FtpResponseMessage.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPTRANSFERMODE
#include "FtpTransferMode.hpp"
#endif

namespace Elysium::Communication::Service::Ftp
{
	class ELYSIUM_COMMUNICATION_API FtpClient final
	{
	public:
		FtpClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion);
		FtpClient(const FtpClient& Source) = delete;
		FtpClient(FtpClient&& Right) noexcept = delete;
		~FtpClient();

		FtpClient& operator=(const FtpClient& Source) = delete;
		FtpClient& operator=(FtpClient&& Right) noexcept = delete;

		static constexpr Elysium::Core::uint16_t DefaultFtpControlPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::FtpControl);
		static constexpr Elysium::Core::uint16_t DefaultFtpDataPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::FtpData);

		static constexpr Elysium::Core::uint16_t DefaultImplicitFtpsControlPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::FtpsControl);
		static constexpr Elysium::Core::uint16_t DefaultImplicitFtpsDataPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::FtpsData);

		void Connect(const FtpEncryption DesiredEncryption, const Elysium::Core::Net::EndPoint& RemoteEndPoint);
		void Disconnect();

		void Login(const Elysium::Core::Utf8String& Username, const Elysium::Core::Utf8String& Password);

		const FtpResponseMessage GetHostInformation();
		const FtpResponseMessage GetAccountInformation();
		const FtpResponseMessage GetAvailableSpace();
		const FtpResponseMessage GetSystemType();
		const FtpResponseMessage GetSystemFeatures();
		const FtpResponseMessage GetHelp(const Elysium::Core::Utf8String& Command);

		const FtpResponseMessage SetTransferMode(const FtpTransferMode TransferMode);

		void EnterPassiveMode();

		const FtpResponseMessage PrintWorkingDirectory();
		const FtpResponseMessage ChangeWorkingDirectory(const Elysium::Core::Utf8String& Value);
		const FtpResponseMessage ChangeToParentDirectory();
		const FtpResponseMessage MakeDirectory(const Elysium::Core::Utf8String& Value);
		const FtpResponseMessage DeleteDirectory(const Elysium::Core::Utf8String& Value);

		const FtpResponseMessage ListResourceInformation(const Elysium::Core::Utf8String& Value);
		const FtpResponseMessage ListNamedDirectoryInformation(const Elysium::Core::Utf8String& Value);
		const FtpResponseMessage ListNamedFileInformation(const Elysium::Core::Utf8String& Value);
		const FtpResponseMessage ListResourceNames(const Elysium::Core::Utf8String& Value);

		void DownloadFile(const Elysium::Core::Utf8String& Value, Elysium::Core::IO::Stream& TargetStream);
		void UploadFile(const Elysium::Core::Utf8String& Value, Elysium::Core::IO::Stream& SourceStream);
	private:
		Transport::TcpClient _ControlTransport;
		Protocol::ApplicationLayer::FileTransferProtocol _ControlProtocol;

		Transport::TcpClient _DataTransport;
		Protocol::ApplicationLayer::FileTransferProtocol _DataProtocol;

		void OpenDataConnection(const FtpResponseMessage& ResponseMessage);
	};
}
#endif
