/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCONTENT
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCONTENT

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
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

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				class ELYSIUM_COMMUNICATION_API HttpContent
				{
				public:
					virtual ~HttpContent() = 0;

					//virtual void ReadAsByteArray(Elysium::Core::byte* Bytes, size_t* Length) const = 0;
					virtual void ReadAsStream(Elysium::Core::IO::Stream& TargetStream) const = 0;
					//virtual void ReadAsString(Elysium::Core::String& TargetString) const = 0;
				protected:
					HttpContent();
				};
			}
		}
	}
}
#endif
