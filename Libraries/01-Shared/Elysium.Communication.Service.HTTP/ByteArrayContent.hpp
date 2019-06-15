/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_BYTEARRAYCONTENT
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_BYTEARRAYCONTENT

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCONTENT
#include "HttpContent.hpp"
#endif

#ifndef ELYSIUM_CORE_BYTE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Byte.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				class ELYSIUM_COMMUNICATION_API ByteArrayContent : public HttpContent
				{
				public:
					ByteArrayContent(const Elysium::Core::byte* Content, const size_t Length);
					virtual ~ByteArrayContent();
				private:
					const Elysium::Core::byte* _Content;
					const size_t _Length;
				};
			}
		}
	}
}
#endif
