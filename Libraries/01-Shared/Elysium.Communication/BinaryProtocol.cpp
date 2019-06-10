#include "BinaryProtocol.hpp"

#ifndef ELYSIUM_CORE_NOTIMPLEMENTEDEXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/NotImplementedException.hpp"
#endif

Elysium::Communication::Protocol::BinaryProtocol::BinaryProtocol(Transport::TransportBase * Transport)
	: ProtocolBase(Transport)
{
}
Elysium::Communication::Protocol::BinaryProtocol::~BinaryProtocol()
{
}

void Elysium::Communication::Protocol::BinaryProtocol::WriteString(const Elysium::Core::String * Value)
{
	throw Elysium::Core::NotImplementedException();
}

void Elysium::Communication::Protocol::BinaryProtocol::ReadString(Elysium::Core::String * Value)
{
	throw Elysium::Core::NotImplementedException();
}
