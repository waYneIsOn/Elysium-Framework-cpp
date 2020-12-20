#include "FtpMessage.hpp"

Elysium::Communication::Service::Ftp::FtpMessage::~FtpMessage()
{ }

const Elysium::Core::String & Elysium::Communication::Service::Ftp::FtpMessage::GetContent() const
{
	return _Content;
}

Elysium::Communication::Service::Ftp::FtpMessage::FtpMessage(const Elysium::Core::String & Content)
	: _Content(Content)
{ }
Elysium::Communication::Service::Ftp::FtpMessage::FtpMessage(Elysium::Core::String && Content)
	: _Content(Content)
{ }

