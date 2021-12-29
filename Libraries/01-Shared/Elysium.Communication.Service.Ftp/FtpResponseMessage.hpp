/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPRESPONSEMESSAGE
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPRESPONSEMESSAGE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPMESSAGE
#include "FtpMessage.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPRESPONSESTATUSCODE
#include "FtpResponseStatusCode.hpp"
#endif

#ifndef ELYSIUM_CORE_STRINGVIEW
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/StringView.hpp"
#endif

namespace Elysium::Communication::Service::Ftp
{
	class ELYSIUM_COMMUNICATION_API FtpResponseMessage final : public FtpMessage
	{
	public:
		FtpResponseMessage(const Elysium::Core::Utf8String& Content);
		FtpResponseMessage(Elysium::Core::Utf8String&& Content);
		FtpResponseMessage(const FtpResponseMessage& Source) = delete;
		FtpResponseMessage(FtpResponseMessage&& Right) noexcept = delete;
		virtual ~FtpResponseMessage();

		FtpResponseMessage& operator=(const FtpResponseMessage& Source) = delete;
		FtpResponseMessage& operator=(FtpResponseMessage&& Right) noexcept = delete;

		const FtpResponseStatusCode GetCode() const;
		const bool GetIsSuccesful() const;

		const Elysium::Core::Utf8StringView GetFirstLine() const;
		const Elysium::Core::Utf8StringView GetLastLine() const;
	};
}
#endif
