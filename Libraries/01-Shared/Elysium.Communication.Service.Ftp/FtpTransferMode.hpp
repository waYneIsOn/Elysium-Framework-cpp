/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPTRANSFERMODE
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPTRANSFERMODE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Service::Ftp
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class FtpTransferMode : Elysium::Core::uint32_t
#elif defined(__ANDROID__)
	enum class FtpTransferMode
#else
#error "undefined os"
#endif
	{
		ASCII = 0,
		ImageBinary = 1
	};
}
#endif
