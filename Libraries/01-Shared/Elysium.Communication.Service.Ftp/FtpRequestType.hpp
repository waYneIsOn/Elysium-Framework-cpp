/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPREQUESTTYPE
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPREQUESTTYPE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Service::Ftp
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class FtpRequestType : Elysium::Core::uint32_t
#elif defined(__ANDROID__)
	enum class FtpRequestType
#else
#error "undefined os"
#endif
	{
		Clnt = 221,

		Pass = 228,

		Pwd = 235,

		User = 237,

		Opts = 243,

		Type = 253,

		Feat = 288,

		Mlsd = 304,

		Pasv = 314,

		Quit = 323,

		Syst = 339,
	};
}
#endif
