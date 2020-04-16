/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPFEATURE
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPFEATURE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Service::FTP
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class FtpFeature : Elysium::Core::uint32_t
#elif defined(__ANDROID__)
	enum class FtpFeature
#else
#error "undefined os"
#endif
	{
		None = 0,
		MLSD = 1,
		SIZE = 2,
		MDTM = 4,
		REST = 8,
		UTF8 = 16,
		PRET = 32,
		MFMT = 64,
		MFCT = 128,
		MFF = 256,
		STAT = 512,
		HASH = 1024,
		MD5 = 2048,
		XMD5 = 4096,
		XCRC = 8192,
		XSHA1 = 16384,
		XSHA256 = 32768,
		XSHA512 = 65536,
	};
}
#endif
