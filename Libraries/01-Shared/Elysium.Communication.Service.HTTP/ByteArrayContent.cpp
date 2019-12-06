#include "ByteArrayContent.hpp"

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

#ifndef _INC_STRING
#include <string>
#endif

#ifndef ELYSIUM_CORE_ARGUMENTNULLEXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/ArgumentNullException.hpp"
#endif

Elysium::Communication::Service::Http::ByteArrayContent::ByteArrayContent(const Elysium::Core::byte * Content, const size_t Length)
	: HttpContent(),
	_Content(new Elysium::Core::byte[Length]), _Length(Length)
{
	memcpy(_Content, Content, _Length);
}
Elysium::Communication::Service::Http::ByteArrayContent::~ByteArrayContent()
{
	delete[] _Content;
}

void Elysium::Communication::Service::Http::ByteArrayContent::ReadAsStream(Elysium::Core::IO::Stream & TargetStream) const
{
	TargetStream.Write(_Content, _Length);
}
Elysium::Core::String Elysium::Communication::Service::Http::ByteArrayContent::ReadAsString() const
{
	return Elysium::Core::Text::Encoding::UTF8().GetString(_Content, _Length);
}
