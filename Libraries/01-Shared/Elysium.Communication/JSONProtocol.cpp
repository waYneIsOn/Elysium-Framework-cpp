#include "JSONProtocol.hpp"

Elysium::Communication::Protocol::JSONProtocol::JSONProtocol(Transport::TransportBase & Transport)
	: TextProtocol(Transport)
{
}
Elysium::Communication::Protocol::JSONProtocol::~JSONProtocol()
{
}

void Elysium::Communication::Protocol::JSONProtocol::WriteBinary(const Elysium::Core::byte * Buffer, const size_t Length)
{
	_Transport.Write(Buffer, Length);
}

size_t Elysium::Communication::Protocol::JSONProtocol::ReadBinary(Elysium::Core::byte * Buffer, const size_t Length)
{
	return _Transport.Read(Buffer, Length);
}
