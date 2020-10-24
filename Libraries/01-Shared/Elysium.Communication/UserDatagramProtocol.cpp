#include "UserDatagramProtocol.hpp"

#ifndef ELYSIUM_CORE_BITCONVERTER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#endif

const Elysium::Core::uint16_t Elysium::Communication::Protocol::TransportLayer::UserDatagramProtocol::HEADERLENGTH = 8;
const Elysium::Core::uint16_t Elysium::Communication::Protocol::TransportLayer::UserDatagramProtocol::MAXIMUMDATALENGTH = 65507;

Elysium::Communication::Protocol::TransportLayer::UserDatagramProtocol::UserDatagramProtocol(Transport::TransportBase & Transport, const Elysium::Core::uint16_t SourcePort, const Elysium::Core::uint16_t DestinationPort)
	: BinaryProtocol(Transport),
	_SourcePort(SourcePort), _DestinationPort(DestinationPort)
{ }
Elysium::Communication::Protocol::TransportLayer::UserDatagramProtocol::~UserDatagramProtocol()
{ }

void Elysium::Communication::Protocol::TransportLayer::UserDatagramProtocol::WriteData(const Elysium::Core::byte * Buffer, const size_t Length)
{
	if (Length > 0 && Buffer == nullptr)
	{
		throw 1;
	}
	if (Length > MAXIMUMDATALENGTH)
	{
		throw 1;
	}

	static const size_t SizeOfUint16_t = sizeof(Elysium::Core::uint16_t);

	WriteBinary(&Elysium::Core::BitConverter::GetBytes(_SourcePort)[0], SizeOfUint16_t);
	WriteBinary(&Elysium::Core::BitConverter::GetBytes(_DestinationPort)[0], SizeOfUint16_t);
	//uint16_t _TotalLength = Header + Data
	//uint16_t _CrcChecksum

	WriteBinary(Buffer, Length);
}

const size_t Elysium::Communication::Protocol::TransportLayer::UserDatagramProtocol::ReadData(Elysium::Core::byte * Buffer, const size_t Length)
{
	throw 1;
}
