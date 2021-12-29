/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_BYTEARRAYCONTENT
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_BYTEARRAYCONTENT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCONTENT
#include "HttpContent.hpp"
#endif

#ifndef ELYSIUM_CORE_COLLECTIONS_TEMPLATE_ARRAYOFBYTE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/ArrayOfByte.hpp"
#endif

#ifndef ELYSIUM_CORE_COLLECTIONS_TEMPLATE_LISTOFBYTE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/ListOfByte.hpp"
#endif

namespace Elysium::Communication::Service::Http
{
	class ELYSIUM_COMMUNICATION_API ByteArrayContent : public HttpContent
	{
	public:
		ByteArrayContent(const Elysium::Core::Collections::Template::List<Elysium::Core::byte>& Content);
		ByteArrayContent(const Elysium::Core::Collections::Template::Array<Elysium::Core::byte>& Content);
		virtual ~ByteArrayContent();

		virtual void ReadAsStream(Elysium::Core::IO::Stream& TargetStream) const override;
		virtual Elysium::Core::Utf8String ReadAsString() const override;
	protected:
		Elysium::Core::Collections::Template::Array<Elysium::Core::byte> _Content;
	};
}
#endif
