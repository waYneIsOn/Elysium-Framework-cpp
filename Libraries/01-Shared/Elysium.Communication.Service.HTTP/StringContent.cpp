#include "StringContent.hpp"

Elysium::Communication::Service::Http::StringContent::StringContent(const Elysium::Core::byte * Content, const size_t Length)
	: ByteArrayContent(Content, Length)
{
}
Elysium::Communication::Service::Http::StringContent::StringContent(const Elysium::Core::byte * Content, const size_t Length, const Elysium::Core::Text::Encoding & Encoding)
	: ByteArrayContent(Content, Length)
{
}
Elysium::Communication::Service::Http::StringContent::StringContent(const Elysium::Core::String & Content)
	: ByteArrayContent(nullptr, 0)
{
}
Elysium::Communication::Service::Http::StringContent::StringContent(const Elysium::Core::String & Content, const Elysium::Core::Text::Encoding & Encoding)
	: ByteArrayContent(nullptr, 0)
{
}
Elysium::Communication::Service::Http::StringContent::~StringContent()
{
}
