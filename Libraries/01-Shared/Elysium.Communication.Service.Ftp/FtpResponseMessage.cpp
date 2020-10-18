#include "FtpResponseMessage.hpp"

#ifndef ELYSIUM_CORE_CONVERT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#endif

#ifndef ELYSIUM_CORE_ENVIRONMENT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Environment.hpp"
#endif

Elysium::Communication::Service::Ftp::FtpResponseMessage::FtpResponseMessage(const Elysium::Core::String & Content)
	: _Content(Content)
{ }
Elysium::Communication::Service::Ftp::FtpResponseMessage::FtpResponseMessage(Elysium::Core::String && Content)
	: _Content(Content)
{ }
Elysium::Communication::Service::Ftp::FtpResponseMessage::~FtpResponseMessage()
{ }

const Elysium::Core::String & Elysium::Communication::Service::Ftp::FtpResponseMessage::GetContent() const
{
	return _Content;
}

const Elysium::Communication::Service::Ftp::FtpStatusCode Elysium::Communication::Service::Ftp::FtpResponseMessage::GetCode() const
{
	const Elysium::Core::StringView LastLine = GetLastLine();

	return static_cast<FtpStatusCode>(Elysium::Core::Convert::ToInt32(LastLine.Substringview(0, 3), 10));
}

const bool Elysium::Communication::Service::Ftp::FtpResponseMessage::GetIsSuccesful() const
{
	return GetCode() < Elysium::Communication::Service::Ftp::FtpStatusCode::TemporaryError;
}

const Elysium::Core::StringView Elysium::Communication::Service::Ftp::FtpResponseMessage::GetFirstLine() const
{
	const size_t IndexOfNewLine = _Content.IndexOf(Elysium::Core::Environment::NewLine(), 0);
	if (IndexOfNewLine == -1)
	{
		return Elysium::Core::StringView(_Content, 0, _Content.GetLength());
	}
	else
	{
		return Elysium::Core::StringView(_Content, 0, IndexOfNewLine - 4);
	}
}

const Elysium::Core::StringView Elysium::Communication::Service::Ftp::FtpResponseMessage::GetLastLine() const
{
	const size_t LastIndexOfNewLine = _Content.LastIndexOf(Elysium::Core::Environment::NewLine(), 0);
	if (LastIndexOfNewLine == -1)
	{
		return GetFirstLine();
	}
	else
	{
		return Elysium::Core::StringView(_Content, LastIndexOfNewLine);
	}
}
