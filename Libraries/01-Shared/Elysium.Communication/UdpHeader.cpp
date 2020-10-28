#include "UdpHeader.hpp"

#ifndef ELYSIUM_CORE_BITCONVERTER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#endif

Elysium::Communication::Protocol::TransportLayer::UdpHeader::UdpHeader()
{ }
Elysium::Communication::Protocol::TransportLayer::UdpHeader::~UdpHeader()
{ }

const Elysium::Core::uint16_t Elysium::Communication::Protocol::TransportLayer::UdpHeader::GetSourcePort() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[0]);
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::TransportLayer::UdpHeader::GetDestinationPort() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[2]);
}

const Elysium::Core::uint32_t Elysium::Communication::Protocol::TransportLayer::UdpHeader::GetTotalLength() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[4]);
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::TransportLayer::UdpHeader::GetChecksum() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[6]);
}
