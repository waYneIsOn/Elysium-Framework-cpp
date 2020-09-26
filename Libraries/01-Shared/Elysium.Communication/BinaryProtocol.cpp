#include "BinaryProtocol.hpp"

#ifndef ELYSIUM_CORE_NOTIMPLEMENTEDEXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/NotImplementedException.hpp"
#endif

Elysium::Communication::Protocol::BinaryProtocol::BinaryProtocol(Transport::TransportBase & Transport)
	: ProtocolBase(Transport)
{ }
Elysium::Communication::Protocol::BinaryProtocol::~BinaryProtocol()
{ }

void Elysium::Communication::Protocol::BinaryProtocol::WriteBinary(const Elysium::Core::byte * Buffer, const size_t Length)
{
	_Transport.Write(Buffer, Length);
}

const size_t Elysium::Communication::Protocol::BinaryProtocol::ReadBinary(Elysium::Core::byte * Buffer, const size_t Length)
{
	return _Transport.Read(Buffer, Length);
}
