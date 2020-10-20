#include "InternetRelayChat.hpp"

#ifndef ELYSIUM_CORE_ENVIRONMENT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Environment.hpp"
#endif

const Elysium::Core::String Elysium::Communication::Protocol::ApplicationLayer::InternetRelayChat::NEWLINE = Elysium::Core::Environment::NewLine();

Elysium::Communication::Protocol::ApplicationLayer::InternetRelayChat::InternetRelayChat(Transport::TransportBase & Transport)
	: TextProtocol(Transport, Elysium::Core::Text::Encoding::UTF8())
{ }
Elysium::Communication::Protocol::ApplicationLayer::InternetRelayChat::~InternetRelayChat()
{ }

const Elysium::Core::String Elysium::Communication::Protocol::ApplicationLayer::InternetRelayChat::WriteHelp()
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"HELP");

	WriteString(Command);
	WriteString(NEWLINE);
	_Transport.Flush();

	return ReadLine();
}

void Elysium::Communication::Protocol::ApplicationLayer::InternetRelayChat::WriteQuit(const Elysium::Core::String & Message)
{
	static const Elysium::Core::String Command = Elysium::Core::String(u8"QUIT ");

	WriteString(Command);
	if (Message.GetLength() > 0)
	{
		WriteString(Message);
	}
	WriteString(NEWLINE);
	_Transport.Flush();
}
