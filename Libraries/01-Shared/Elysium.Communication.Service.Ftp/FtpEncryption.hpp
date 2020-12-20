/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPENCRYPTION
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPENCRYPTION

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Service::Ftp
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class FtpEncryption : Elysium::Core::uint8_t
#elif defined(__ANDROID__)
	enum class FtpEncryption
#else
#error "undefined os"
#endif
	{
		// Use unencrypted ftp - UNSAFE
		None = 0,

		// Run ssl/tls encrypted ftp immediately
		ImplicitTls = 1,

		// Use unencrypted ftp and then update to ssl/tls
		ExplicitTls = 2,

		// Use unencrypted ftp and then update to ssl/tls if possible. Might therefore fallback to unencrypted ftp - UNSAFE
		ExplicitTlsIfAvailable = 3
	};
}
#endif
