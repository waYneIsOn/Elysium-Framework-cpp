/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPMESSAGE
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPMESSAGE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

namespace Elysium::Communication::Service::Ftp
{
	class ELYSIUM_COMMUNICATION_API FtpMessage
	{
	public:
		FtpMessage(const FtpMessage& Source) = delete;
		FtpMessage(FtpMessage&& Right) noexcept = delete;
		virtual ~FtpMessage();

		FtpMessage& operator=(const FtpMessage& Source) = delete;
		FtpMessage& operator=(FtpMessage&& Right) noexcept = delete;

		const Elysium::Core::Utf8String& GetContent() const;
	protected:
		FtpMessage(const Elysium::Core::Utf8String& Content);
		FtpMessage(Elysium::Core::Utf8String&& Content);

		const Elysium::Core::Utf8String _Content;
	};
}
#endif
