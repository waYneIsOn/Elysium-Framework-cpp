/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPREQUESTMESSAGE
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPREQUESTMESSAGE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPMESSAGE
#include "FtpMessage.hpp"
#endif

#ifndef ELYSIUM_CORE_STRINGVIEW
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/StringView.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPREQUESTTYPE
#include "FtpRequestType.hpp"
#endif

namespace Elysium::Communication::Service::Ftp
{
	class ELYSIUM_COMMUNICATION_API FtpRequestMessage final : public FtpMessage
	{
	public:
		FtpRequestMessage(const Elysium::Core::Utf8String& Content);
		FtpRequestMessage(Elysium::Core::Utf8String&& Content);

		FtpRequestMessage(const FtpRequestMessage& Source) = delete;

		FtpRequestMessage(FtpRequestMessage&& Right) noexcept = delete;

		virtual ~FtpRequestMessage();
	public:
		FtpRequestMessage& operator=(const FtpRequestMessage& Source) = delete;

		FtpRequestMessage& operator=(FtpRequestMessage&& Right) noexcept = delete;
	public:
		const Elysium::Core::Utf8StringView GetCommandText() const;

		const FtpRequestType GetCommandType() const;
	};
}
#endif
