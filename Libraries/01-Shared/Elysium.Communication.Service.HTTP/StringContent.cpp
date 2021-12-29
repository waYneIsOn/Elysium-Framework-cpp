#include "StringContent.hpp"

Elysium::Communication::Service::Http::StringContent::StringContent(const Elysium::Core::Utf8String & Content)
	: ByteArrayContent(Elysium::Core::Text::Encoding::Default().GetBytes(&Content[0], Content.GetLength()))
{
	_Headers.SetContentLength(_Content.GetLength() - 1);
}
Elysium::Communication::Service::Http::StringContent::StringContent(const Elysium::Core::Utf8String & Content, const Elysium::Core::Text::Encoding & Encoding)
	: ByteArrayContent(Encoding.GetBytes(&Content[0], Content.GetLength()))
{
	_Headers.SetContentLength(_Content.GetLength() - 1);
}
Elysium::Communication::Service::Http::StringContent::~StringContent()
{ }
