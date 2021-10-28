#include "RemoteFrameBufferProtocol.hpp"

Elysium::Communication::Protocol::ApplicationLayer::RemoteFrameBufferProtocol::RemoteFrameBufferProtocol(Transport::TransportBase& Transport)
	: TextProtocol(Transport, Elysium::Core::Text::Encoding::UTF8())
{ }

Elysium::Communication::Protocol::ApplicationLayer::RemoteFrameBufferProtocol::~RemoteFrameBufferProtocol()
{ }

const Elysium::Core::String Elysium::Communication::Protocol::ApplicationLayer::RemoteFrameBufferProtocol::WriteProtocolVersionHandshake(const Elysium::Core::String & Value)
{	// "RFB xxx.yyy\n" where xxx and yyy are the majorand minor version numbers, left - padded with zeros
	// 3.3, 3.7 or 3.8
	static const Elysium::Core::String Command = Elysium::Core::String(u8"RFB 0003.008\n");

	WriteString(Command);
	//WriteString(Value);
	_Transport.Flush();

	return ReadLine();
}
