/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_FILETRANSFERPROTOCOL
#define ELYSIUM_COMMUNICATION_PROTOCOL_FILETRANSFERPROTOCOL

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

namespace Elysium::Communication::Protocol
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

		// ...
		const Elysium::Core::String ReadWelcomeMessage();

		// Upgrade to SSL/TLS
		const Elysium::Core::String WriteAuth(const Elysium::Core::String& Value);

		// Authentication username
		const Elysium::Core::String WriteUser(const Elysium::Core::String& Value);

		// Authentication password
		const Elysium::Core::String WritePass(const Elysium::Core::String& Value);

		// Get information about the server's system.
		const Elysium::Core::String WriteSyst();

		// Get information about the server's features.
		const Elysium::Core::String WriteFeat();

		// Inform the server about the client being used
		const Elysium::Core::String WriteClnt(const Elysium::Core::String& Value);

		// Sets the transfer mode (A = ASCII, I = Image/Binary)
		const Elysium::Core::String WriteType(const Elysium::Core::String& Value);

		// Enter passive mode
		const Elysium::Core::String WritePASV();

		// Print working directory
		const Elysium::Core::String WritePWD();

		// ...
		const Elysium::Core::String WriteCWD(const Elysium::Core::String& Value);

		// ...
		const Elysium::Core::String WriteCDUP();

		// ...
		const Elysium::Core::String WriteMLSD(const Elysium::Core::String& Value);

		// Disconnect
		const Elysium::Core::String WriteQuit();
	private:
		static const Elysium::Core::String NEWLINE;
	};
}
#endif
