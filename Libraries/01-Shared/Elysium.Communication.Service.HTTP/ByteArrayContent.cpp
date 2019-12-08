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

Elysium::Communication::Service::Http::ByteArrayContent::ByteArrayContent(const Elysium::Core::Collections::Template::List<Elysium::Core::byte>& Content)
	: HttpContent(),
	_Content(Elysium::Core::Collections::Template::List<Elysium::Core::byte>(Content))
{
}
Elysium::Communication::Service::Http::ByteArrayContent::~ByteArrayContent()
{
}

void Elysium::Communication::Service::Http::ByteArrayContent::ReadAsStream(Elysium::Core::IO::Stream & TargetStream) const
{
	TargetStream.Write(&_Content[0], _Content.GetCount());
}
Elysium::Core::String Elysium::Communication::Service::Http::ByteArrayContent::ReadAsString() const
{
	return Elysium::Core::Text::Encoding::UTF8().GetString(&_Content[0], _Content.GetCount());
}
