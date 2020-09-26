/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPEXCEPTION
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPEXCEPTION

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_EXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Exception.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPRESPONSEMESSAGE
#include "FtpResponseMessage.hpp"
#endif

namespace Elysium::Communication::Service::Ftp
{
	class ELYSIUM_COMMUNICATION_API FtpException final : public Elysium::Core::Exception
	{
	public:
		FtpException(const FtpResponseMessage& Response);
		FtpException(const FtpException& Source) = delete;
		FtpException(FtpException&& Right) noexcept = delete;
		virtual ~FtpException();

		FtpException& operator=(const FtpException& Source) = delete;
		FtpException& operator=(FtpException&& Right) noexcept = delete;
	private:
		//FtpResponseMessage _Response;
	};
}
#endif
