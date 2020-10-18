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

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::NEWLINE = Elysium::Core::Environment::NewLine();

Elysium::Communication::Protocol::FileTransferProtocol::FileTransferProtocol(Transport::TransportBase & Transport)
	: TextProtocol(Transport, Elysium::Core::Text::Encoding::ASCII())
{ }
Elysium::Communication::Protocol::FileTransferProtocol::~FileTransferProtocol()
{ }

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::ReadWelcomeMessage()
{
	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteAuth(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"AUTH ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteUser(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"USER ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WritePass(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"PASS ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteHelp(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"HELP ");

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

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteHost()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"HOST");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteSyst()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"SYST");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteFeat()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"FEAT");

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

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteAcct()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"ACCT");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteAvbl()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"AVBL");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteClnt(const Elysium::Core::String& Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"CLNT ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteType(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"TYPE ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WritePasv()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"PASV");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteEpsv()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"EPSV");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteLpsv()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"LPSV");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WritePwd()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"PWD");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteCwd(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"CWD ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteCdup()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"CDUP");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteList(const Elysium::Core::String & Value, Protocol::FileTransferProtocol & DataProtocol)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"LIST ");

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

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteMlsd(const Elysium::Core::String & Value, Protocol::FileTransferProtocol & DataProtocol)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"MLSD ");

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

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteMlst(const Elysium::Core::String & Value, Protocol::FileTransferProtocol & DataProtocol)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"MLST ");

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

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteNlst(const Elysium::Core::String & Value, Protocol::FileTransferProtocol & DataProtocol)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"NLST ");

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

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteMkd(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"MKD ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteRmd(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"RMD ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteRetr(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"RETR ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteStor(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"STOR ");

	WriteString(Command);
	if (Value.GetLength() > 0)
	{
		WriteString(Value);
	}
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteQuit()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"QUIT");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const bool Elysium::Communication::Protocol::FileTransferProtocol::ReadFirstLine(Elysium::Core::Text::StringBuilder& ResponseBuilder)
{
	const Elysium::Core::String Line = ReadLine();
	ResponseBuilder.Append(Line);
	ResponseBuilder.Append(NEWLINE);

	return Elysium::Core::Convert::ToInt32(Line.Substring(0, 3), 10) < 400;
}

void Elysium::Communication::Protocol::FileTransferProtocol::ReadSubsequentLines(Elysium::Core::Text::StringBuilder & ResponseBuilder)
{
	Elysium::Core::String Line;

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

void Elysium::Communication::Protocol::FileTransferProtocol::ReadSubsequentDataLines(Elysium::Core::Text::StringBuilder & ResponseBuilder, Protocol::FileTransferProtocol & DataProtocol)
{
	Elysium::Core::String Line;
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
