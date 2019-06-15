#include "ByteArrayContent.hpp"

Elysium::Communication::Service::Http::ByteArrayContent::ByteArrayContent(const Elysium::Core::byte * Content, const size_t Length)
	: HttpContent(),
	_Content(nullptr), _Length(Length)
{
}
Elysium::Communication::Service::Http::ByteArrayContent::~ByteArrayContent()
{
}
