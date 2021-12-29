/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_STRINGCONTENT
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_STRINGCONTENT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_BYTEARRAYCONTENT
#include "ByteArrayContent.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

namespace Elysium::Communication::Service::Http
{
	class ELYSIUM_COMMUNICATION_API StringContent final : public ByteArrayContent
	{
	public:
		StringContent(const Elysium::Core::Utf8String& Content);
		StringContent(const Elysium::Core::Utf8String& Content, const Elysium::Core::Text::Encoding& Encoding);
		virtual ~StringContent();
	private:
		//const Elysium::Core::Text::Encoding _Encoding;
	};
}
#endif
