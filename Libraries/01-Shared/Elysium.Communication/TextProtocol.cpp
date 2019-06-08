#include "TextProtocol.hpp"

Elysium::Communication::Protocol::TextProtocol::TextProtocol(const Transport::TransportBase * Transport)
	: ProtocolBase(Transport),
	_Encoding(Elysium::Core::Text::Encoding(*Elysium::Core::Text::Encoding::Default()))
{
}
Elysium::Communication::Protocol::TextProtocol::TextProtocol(const Transport::TransportBase * Transport, const Elysium::Core::Text::Encoding * Encoding)
	: ProtocolBase(Transport),
	_Encoding(Elysium::Core::Text::Encoding(*Encoding))
{
}
Elysium::Communication::Protocol::TextProtocol::~TextProtocol()
{
}
