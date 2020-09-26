/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

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

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPENCRYPTION
#include "FtpEncryption.hpp"
#endif

#ifndef ELYSIUM_CORE_URI
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Uri.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TCPCLIENT
#include "../Elysium.Communication/TcpClient.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_FILETRANSFERPROTOCOL
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
		FtpClient();
		FtpClient(const FtpClient& Source) = delete;
		FtpClient(FtpClient&& Right) noexcept = delete;
		~FtpClient();

		FtpClient& operator=(const FtpClient& Source) = delete;
		FtpClient& operator=(FtpClient&& Right) noexcept = delete;

		static const Elysium::Core::uint16_t DefaultFtpControlPort;
		static const Elysium::Core::uint16_t DefaultFtpDataPort;

		static const Elysium::Core::uint16_t DefaultImplicitFtpsControlPort;
		static const Elysium::Core::uint16_t DefaultImplicitFtpsDataPort;

		void Connect(const FtpEncryption DesiredEncryption, const Elysium::Core::Net::EndPoint& RemoteEndPoint);
		void Disconnect();

		void Login(const Elysium::Core::String& Username, const Elysium::Core::String& Password);

		const FtpResponseMessage GetSystemInformation();
		const FtpResponseMessage GetSystemFeatures();

		const FtpResponseMessage SetTransferMode(const FtpTransferMode TransferMode);

		void EnterPassiveMode();

		const FtpResponseMessage PrintWorkingDirectory();
		const FtpResponseMessage ChangeWorkingDirectory(const Elysium::Core::String& Value);
		const FtpResponseMessage ChangeToParentDirectory();
		//const FtpResponseMessage MakeDirectory(const Elysium::Core::String& Value);
		//const FtpResponseMessage DeleteDirectory(const Elysium::Core::String& Value);

		const FtpResponseMessage ListResourceInformation(const Elysium::Core::String& Value);
	private:
		Core::Net::Sockets::Socket _ControlSocket;
		Transport::TcpClient _ControlTransport;
		Protocol::FileTransferProtocol _ControlProtocol;

		Core::Net::Sockets::Socket _DataSocket;
		Transport::TcpClient _DataTransport;
		Protocol::FileTransferProtocol _DataProtocol;

		void OpenDataConnection(const FtpResponseMessage& ResponseMessage);
	};
}
#endif
