/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCONTENT
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCONTENT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_HTTPCONTENTHEADERS
#include "HttpContentHeaders.hpp"
#endif

#ifndef ELYSIUM_CORE_BYTE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Byte.hpp"
#endif

#ifndef ELYSIUM_CORE_IO_STREAM
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/Stream.hpp"
#endif

#ifndef ELYSIUM_CORE_IO_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

namespace Elysium::Communication::Service::Http
{
	class ELYSIUM_COMMUNICATION_API HttpContent
	{
	public:
		virtual ~HttpContent() = 0;

		const Headers::HttpContentHeaders& GetHeaders() const;

		//virtual void ReadAsByteArray(Elysium::Core::byte* Bytes, size_t* Length) const = 0;
		virtual void ReadAsStream(Elysium::Core::IO::Stream& TargetStream) const = 0;
		virtual Elysium::Core::String ReadAsString() const = 0;
	protected:
		HttpContent();

		Headers::HttpContentHeaders _Headers;
	};
}
#endif
