#include "FtpRequestMessage.hpp"

Elysium::Communication::Service::Ftp::FtpRequestMessage::FtpRequestMessage(const Elysium::Core::String & Content)
	: Elysium::Communication::Service::Ftp::FtpMessage(Content)
{ }
Elysium::Communication::Service::Ftp::FtpRequestMessage::FtpRequestMessage(Elysium::Core::String && Content)
	: Elysium::Communication::Service::Ftp::FtpMessage(Content)
{ }
Elysium::Communication::Service::Ftp::FtpRequestMessage::~FtpRequestMessage()
{ }

const Elysium::Core::StringView Elysium::Communication::Service::Ftp::FtpRequestMessage::GetCommandText() const
{
	const size_t IndexOfNewLine = _Content.IndexOf(u8" ", 0);
	if (IndexOfNewLine == -1)
	{
		return Elysium::Core::StringView(_Content, 0, _Content.GetLength());
	}
	else
	{
		return Elysium::Core::StringView(_Content, 0, IndexOfNewLine - 1);
	}
}

const Elysium::Communication::Service::Ftp::FtpRequestType Elysium::Communication::Service::Ftp::FtpRequestMessage::GetCommandType() const
{
	const Elysium::Core::StringView CommandText = GetCommandText();

	Elysium::Core::uint32_t Checksum = 0;
	for (size_t i = 0; i < CommandText.GetLength(); i++)
	{
		Checksum += CommandText[i];
	}

	return static_cast<FtpRequestType>(Checksum);
}
