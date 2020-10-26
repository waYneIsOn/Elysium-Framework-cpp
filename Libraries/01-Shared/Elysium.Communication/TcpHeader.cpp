#include "TcpHeader.hpp"

#ifndef ELYSIUM_CORE_BITCONVERTER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#endif

Elysium::Communication::Protocol::TransportLayer::TcpHeader::TcpHeader()
{ }
Elysium::Communication::Protocol::TransportLayer::TcpHeader::~TcpHeader()
{ }

const Elysium::Core::uint16_t Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetSourcePort() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[0]);
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetDestinationPort() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[2]);
}

const Elysium::Core::uint32_t Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetSequenceNumber() const
{
	return Elysium::Core::BitConverter::ToUInt32(&_Data[4]);
}

const Elysium::Core::uint32_t Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetAcknowledgmentNumber() const
{
	return Elysium::Core::BitConverter::ToUInt32(&_Data[8]);
}

const Elysium::Core::uint8_t Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetHeaderLength() const
{
	return _Data[12] >> 4;
}

const Elysium::Core::uint8_t Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetReserved() const
{
	return (_Data[12] >> 1) & 0x0F;
}

const bool Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetNonceFlag() const
{
	return _Data[12] & 0x01;
}

const bool Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetCongestionWindowReducedFlag() const
{
	return (_Data[13] >> 7) & 0x01;
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetWindowSize() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[14]);
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetChecksum() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[16]);
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::TransportLayer::TcpHeader::GetUrgentPointer() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[18]);
}
