/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_FILETRANSFERPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_APPLICATIONLAYER_FILETRANSFERPROTOCOL

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_TEXTPROTOCOL
#include "TextProtocol.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_STRINGBUILDER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/StringBuilder.hpp"
#endif

namespace Elysium::Communication::Protocol::ApplicationLayer
{
	class ELYSIUM_COMMUNICATION_API FileTransferProtocol final : public TextProtocol
	{
	public:
		FileTransferProtocol(Transport::TransportBase& Transport);
		FileTransferProtocol(const FileTransferProtocol& Source) = delete;
		FileTransferProtocol(FileTransferProtocol&& Right) noexcept = delete;
		virtual ~FileTransferProtocol();

		FileTransferProtocol& operator=(const FileTransferProtocol& Source) = delete;
		FileTransferProtocol& operator=(FileTransferProtocol&& Right) noexcept = delete;

		// Read the message sent by the server once connected
		const Elysium::Core::String ReadWelcomeMessage();

		// ...
		void WriteResponseMessage(const Elysium::Core::uint32_t StatusCode, const Elysium::Core::String& Message);

		// Upgrade to SSL/TLS
		const Elysium::Core::String WriteAuth(const Elysium::Core::String& Value);

		// Authentication username
		const Elysium::Core::String WriteUser(const Elysium::Core::String& Value);

		// Authentication password
		const Elysium::Core::String WritePass(const Elysium::Core::String& Value);

		// Returns usage documentation on a command if specified, else a general help document is returned.
		const Elysium::Core::String WriteHelp(const Elysium::Core::String& Value);

		// Identify desired virtual host on server, by name.
		const Elysium::Core::String WriteHost();

		// Return system type.
		const Elysium::Core::String WriteSyst();

		// Get information about the server's features.
		const Elysium::Core::String WriteFeat();

		// Get account information.
		const Elysium::Core::String WriteAcct();

		// Get the available space.
		const Elysium::Core::String WriteAvbl();

		// Inform the server about the client being used
		const Elysium::Core::String WriteClnt(const Elysium::Core::String& Value);

		// Sets the transfer mode (A = ASCII, I = Image/Binary)
		const Elysium::Core::String WriteType(const Elysium::Core::String& Value);

		// Enter passive mode
		const Elysium::Core::String WritePasv();

		// Enter extended passive mode.
		const Elysium::Core::String WriteEpsv();

		// Enter long passive mode.
		const Elysium::Core::String WriteLpsv();

		// Print working directory. Returns the current directory of the host.
		const Elysium::Core::String WritePwd();

		// Change working directory
		const Elysium::Core::String WriteCwd(const Elysium::Core::String& Value);

		// Change to upper directory
		const Elysium::Core::String WriteCdup();

		// Returns information of a file or directory if specified, else information of the current working directory is returned. 
		const Elysium::Core::String WriteList(const Elysium::Core::String& Value, Protocol::ApplicationLayer::FileTransferProtocol& DataProtocol);

		// List the contents of a directory (if a directory is named)
		const Elysium::Core::String WriteMlsd(const Elysium::Core::String& Value, Protocol::ApplicationLayer::FileTransferProtocol& DataProtocol);

		// Provides data about exactly the object named on its command line, and no others.
		const Elysium::Core::String WriteMlst(const Elysium::Core::String& Value, Protocol::ApplicationLayer::FileTransferProtocol& DataProtocol);

		// Returns a list of file names in a specified directory.
		const Elysium::Core::String WriteNlst(const Elysium::Core::String& Value, Protocol::ApplicationLayer::FileTransferProtocol& DataProtocol);

		// Make directory. 
		const Elysium::Core::String WriteMkd(const Elysium::Core::String& Value);

		// Remove a directory. 
		const Elysium::Core::String WriteRmd(const Elysium::Core::String& Value);

		// Retrieve a copy of the file.
		const Elysium::Core::String WriteRetr(const Elysium::Core::String& Value);

		// Accept the data and to store the data as a file at the server site 
		const Elysium::Core::String WriteStor(const Elysium::Core::String& Value);

		// Tell the server that we're about to disconnect
		const Elysium::Core::String WriteQuit();
	private:
		static const Elysium::Core::String NEWLINE;

		const bool ReadFirstLine(Elysium::Core::Text::StringBuilder& ResponseBuilder);
		void ReadSubsequentLines(Elysium::Core::Text::StringBuilder& ResponseBuilder);
		void ReadSubsequentDataLines(Elysium::Core::Text::StringBuilder& ResponseBuilder, Protocol::ApplicationLayer::FileTransferProtocol& DataProtocol);
	};
}
#endif
