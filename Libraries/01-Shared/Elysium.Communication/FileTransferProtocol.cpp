#include "FileTransferProtocol.hpp"

#ifndef ELYSIUM_CORE_CONVERT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#endif

#ifndef ELYSIUM_CORE_ENVIRONMENT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Environment.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_STRINGBUILDER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/StringBuilder.hpp"
#endif

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::NEWLINE = Elysium::Core::Environment::NewLine();

Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::FileTransferProtocol(Transport::TransportBase & Transport)
	: TextProtocol(Transport, Elysium::Core::Text::Encoding::ASCII())
{ }
Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::~FileTransferProtocol()
{ }

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::ReadWelcomeMessage()
{
	return ReadLine();
}

void Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteResponseMessage(const Elysium::Core::uint32_t StatusCode, const Elysium::Core::Utf8String & Value)
{
	WriteString(Elysium::Core::Convert::ToString(StatusCode, 10));
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteAuth(const Elysium::Core::Utf8String & Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"AUTH ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteUser(const Elysium::Core::Utf8String & Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"USER ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WritePass(const Elysium::Core::Utf8String & Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"PASS ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteHelp(const Elysium::Core::Utf8String & Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"HELP ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	Elysium::Core::Text::StringBuilder ResponseBuilder = Elysium::Core::Text::StringBuilder();
	if (!ReadFirstLine(ResponseBuilder))
	{
		return ResponseBuilder.ToString();
	}
	ReadSubsequentLines(ResponseBuilder);

	return ResponseBuilder.ToString();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteHost()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"HOST");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteSyst()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"SYST");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteFeat()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"FEAT");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	Elysium::Core::Text::StringBuilder ResponseBuilder = Elysium::Core::Text::StringBuilder();
	if (!ReadFirstLine(ResponseBuilder))
	{
		return ResponseBuilder.ToString();
	}
	ReadSubsequentLines(ResponseBuilder);

	return ResponseBuilder.ToString();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteAcct()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"ACCT");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteAvbl()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"AVBL");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteClnt(const Elysium::Core::Utf8String& Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"CLNT ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteType(const Elysium::Core::Utf8String & Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"TYPE ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WritePasv()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"PASV");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteEpsv()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"EPSV");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteLpsv()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"LPSV");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WritePwd()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"PWD");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteCwd(const Elysium::Core::Utf8String & Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"CWD ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteCdup()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"CDUP");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteList(const Elysium::Core::Utf8String & Value, Protocol::ApplicationLayer::FileTransferProtocol & DataProtocol)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"LIST ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	Elysium::Core::Text::StringBuilder ResponseBuilder = Elysium::Core::Text::StringBuilder();
	if (!ReadFirstLine(ResponseBuilder))
	{
		return ResponseBuilder.ToString();
	}
	ReadSubsequentDataLines(ResponseBuilder, DataProtocol);
	ReadSubsequentLines(ResponseBuilder);

	return ResponseBuilder.ToString();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteMlsd(const Elysium::Core::Utf8String & Value, Protocol::ApplicationLayer::FileTransferProtocol & DataProtocol)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"MLSD ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	Elysium::Core::Text::StringBuilder ResponseBuilder = Elysium::Core::Text::StringBuilder();
	if (!ReadFirstLine(ResponseBuilder))
	{
		return ResponseBuilder.ToString();
	}
	ReadSubsequentDataLines(ResponseBuilder, DataProtocol);
	ReadSubsequentLines(ResponseBuilder);

	return ResponseBuilder.ToString();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteMlst(const Elysium::Core::Utf8String & Value, Protocol::ApplicationLayer::FileTransferProtocol & DataProtocol)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"MLST ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	Elysium::Core::Text::StringBuilder ResponseBuilder = Elysium::Core::Text::StringBuilder();
	if (!ReadFirstLine(ResponseBuilder))
	{
		return ResponseBuilder.ToString();
	}
	ReadSubsequentLines(ResponseBuilder);

	return ResponseBuilder.ToString();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteNlst(const Elysium::Core::Utf8String & Value, Protocol::ApplicationLayer::FileTransferProtocol & DataProtocol)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"NLST ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	Elysium::Core::Text::StringBuilder ResponseBuilder = Elysium::Core::Text::StringBuilder();
	if (!ReadFirstLine(ResponseBuilder))
	{
		return ResponseBuilder.ToString();
	}
	ReadSubsequentDataLines(ResponseBuilder, DataProtocol);
	ReadSubsequentLines(ResponseBuilder);

	return ResponseBuilder.ToString();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteMkd(const Elysium::Core::Utf8String & Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"MKD ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteRmd(const Elysium::Core::Utf8String & Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"RMD ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteRetr(const Elysium::Core::Utf8String & Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"RETR ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteStor(const Elysium::Core::Utf8String & Value)
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"STOR ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::Utf8String Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::WriteQuit()
{
	static const Elysium::Core::Utf8String Command = Elysium::Core::Utf8String(u8"QUIT");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const bool Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::ReadFirstLine(Elysium::Core::Text::StringBuilder& ResponseBuilder)
{
	const Elysium::Core::Utf8String Line = ReadLine();
	ResponseBuilder.Append(Line);
	ResponseBuilder.Append(NEWLINE);

	return Elysium::Core::Convert::ToInt32(Line.Substring(0, 3), 10) < 400;
}

void Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::ReadSubsequentLines(Elysium::Core::Text::StringBuilder & ResponseBuilder)
{
	Elysium::Core::Utf8String Line;

	do
	{
		Line = ReadLine();
		ResponseBuilder.Append(Line);

		if (!Line.StartsWith(u8" "))
		{
			break;
		}
		else
		{
			ResponseBuilder.Append(NEWLINE);
		}
	} while (true);
}

void Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol::ReadSubsequentDataLines(Elysium::Core::Text::StringBuilder & ResponseBuilder, Protocol::ApplicationLayer::FileTransferProtocol & DataProtocol)
{
	Elysium::Core::Utf8String Line;
	do
	{
		Line = DataProtocol.ReadLine();
		if (Line.GetLength() == 0)
		{
			break;
		}
		else
		{
			ResponseBuilder.Append(Line);
			ResponseBuilder.Append(NEWLINE);
		}
	} while (true);
}
