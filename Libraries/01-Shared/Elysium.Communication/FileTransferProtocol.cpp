#include "FileTransferProtocol.hpp"

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

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WritePWD()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"PWD");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteCWD(const Elysium::Core::String & Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"CWD ");

	WriteString(Command);
	WriteString(Value);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteCDUP()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"CDUP");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WriteMLSD(const Elysium::Core::String& Value)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"MLSD ");

	WriteString(Command);
	WriteString(Value);
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

	Elysium::Core::Text::StringBuilder Response = Elysium::Core::Text::StringBuilder();
	Elysium::Core::String Line;
	Elysium::Core::uint32_t LineNumber = 0;
	do
	{
		Line = ReadLine();
		Response.Append(Line);
		LineNumber++;

		if (LineNumber > 1 && !Line.StartsWith(u8" "))
		{
			break;
		}
	} while (true);

	return Response.ToString();
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

const Elysium::Core::String Elysium::Communication::Protocol::FileTransferProtocol::WritePASV()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"PASV ");

	WriteString(Command);
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
