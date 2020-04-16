/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCOMPLETIONOPTION
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCOMPLETIONOPTION

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Service::Http
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class HttpCompletionOption : Elysium::Core::uint32_t
#elif defined(__ANDROID__)
	enum class HttpCompletionOption
#else
#error "undefined os"
#endif
	{
		// The operation should complete after reading the entire response including the content.
		ResponseContentRead,

		// The operation should complete as soon as a response is available and headers are read. The content is not read yet. 
		ResponseHeadersRead,
	};
}
#endif
