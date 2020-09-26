/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPRESPONSEMESSAGE
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPRESPONSEMESSAGE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPSTATUSCODE
#include "FtpStatusCode.hpp"
#endif

#ifndef ELYSIUM_CORE_STRINGVIEW
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/StringView.hpp"
#endif

namespace Elysium::Communication::Service::Ftp
{
	class ELYSIUM_COMMUNICATION_API FtpResponseMessage final
	{
	public:
		FtpResponseMessage(const Elysium::Core::String& Content);
		FtpResponseMessage(const FtpResponseMessage& Source) = delete;
		FtpResponseMessage(FtpResponseMessage&& Right) noexcept = delete;
		~FtpResponseMessage();

		FtpResponseMessage& operator=(const FtpResponseMessage& Source) = delete;
		FtpResponseMessage& operator=(FtpResponseMessage&& Right) noexcept = delete;

		const Elysium::Core::String& GetContent() const;
		const FtpStatusCode GetCode() const;
		const bool GetIsSuccesful() const;

		const Elysium::Core::StringView GetHeader() const;
	private:
		const Elysium::Core::String _Content;
	};
}
#endif
