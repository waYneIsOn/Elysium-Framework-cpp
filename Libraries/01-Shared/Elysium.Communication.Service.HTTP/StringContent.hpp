/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_STRINGCONTENT
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_STRINGCONTENT

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_BYTEARRAYCONTENT
#include "ByteArrayContent.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				class ELYSIUM_COMMUNICATION_API StringContent final : public ByteArrayContent
				{
				public:
					StringContent(const Elysium::Core::byte* Content, const size_t Length);
					StringContent(const Elysium::Core::byte* Content, const size_t Length, const Elysium::Core::Text::Encoding& Encoding);
					StringContent(const Elysium::Core::String& Content);
					StringContent(const Elysium::Core::String& Content, const Elysium::Core::Text::Encoding& Encoding);
					virtual ~StringContent();
				private:
					//const Elysium::Core::Text::Encoding _Encoding;
				};
			}
		}
	}
}
#endif