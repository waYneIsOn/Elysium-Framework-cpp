#include "IPv4Header.hpp"

#ifndef ELYSIUM_CORE_BITCONVERTER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#endif

Elysium::Communication::Protocol::InternetLayer::IPv4Header::IPv4Header()
{ }
Elysium::Communication::Protocol::InternetLayer::IPv4Header::~IPv4Header()
{ }

const Elysium::Core::uint8_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetVersion() const
{
	return _Data[0] >> 4;
}

const Elysium::Core::uint8_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetHeaderLength() const
{
	return _Data[0] & 0x0F;
}

const Elysium::Core::uint8_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetDifferentiatedServicesCodePoint() const
{
	return _Data[1] >> 6;
}

const Elysium::Core::uint8_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetExplicitCongestionNotification() const
{
	return _Data[1] & 0x03;
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetTotalLength() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[2]);
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetIdentification() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[4]);
}

const bool Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetReservedFlag() const
{
	return (_Data[6] >> 3) & 0x04;
}

const bool Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetDontFragmentFlag() const
{
	return (_Data[6] >> 3) & 0x02;
}

const bool Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetMoreFragmentsFlag() const
{
	return (_Data[6] >> 3) & 0x01;
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetFragmentOffset() const
{
	return ((_Data[6] & 0x1F) << 8) | _Data[7];
}

const Elysium::Core::uint8_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetTimeToLive() const
{
	return _Data[8];
}

const Elysium::Communication::Protocol::InternetLayer::InternetProtocolNumber Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetProtocol() const
{
	return static_cast<const Elysium::Communication::Protocol::InternetLayer::InternetProtocolNumber>(_Data[9]);
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetChecksum() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[10]);
}

const Elysium::Core::uint32_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetSourceIPAddress() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[10]);
}

const Elysium::Core::uint32_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetDestinationIPAddress() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[10]);
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetVersion(const Elysium::Core::uint8_t Value)
{
	_Data[0] = Value << 4;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetHeaderLength(const Elysium::Core::uint8_t Value)
{
	_Data[0] |= Value & 0x0F;

	Elysium::Core::byte b1 = _Data[0];
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetDifferentiatedServicesCodePoint(const Elysium::Core::uint8_t Value)
{
	_Data[1] = Value << 6;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetExplicitCongestionNotification(const Elysium::Core::uint8_t Value)
{
	_Data[1] = Value & 0x03;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetTotalLength(const Elysium::Core::uint16_t Value)
{
	_Data[2] = Value & 0xFF;
	_Data[3] = Value >> 8;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetIdentification(const Elysium::Core::uint16_t Value)
{
	_Data[4] = Value & 0xFF;
	_Data[5] = Value >> 8;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetReservedFlag(const bool Value)
{
	_Data[6] = Value << 7;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetDontFragmentFlag(const bool Value)
{
	_Data[6] = Value << 6;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetMoreFragmentsFlag(const bool Value)
{
	_Data[6] = Value << 5;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetFragmentOffset(const Elysium::Core::uint16_t Value)
{
	_Data[6] = Value & 0x1F;
	_Data[7] = Value >> 8;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetTimeToLive(const Elysium::Core::uint8_t Value)
{
	_Data[8] = Value;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetProtocol(const InternetProtocolNumber Value)
{
	_Data[9] = static_cast<Elysium::Core::uint8_t>(Value);
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetSourceIPAddress(const Elysium::Core::uint32_t Value)
{
	_Data[12] = Value & 0xFF;
	_Data[13] = Value >> 8;
	_Data[14] = Value >> 16;
	_Data[15] = Value >> 24;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::SetDestinationIPAddress(const Elysium::Core::uint32_t Value)
{
	_Data[16] = Value & 0xFF;
	_Data[17] = Value >> 8;
	_Data[18] = Value >> 16;
	_Data[19] = Value >> 24;
}

void Elysium::Communication::Protocol::InternetLayer::IPv4Header::ComputeAndSetChecksum(const Elysium::Core::uint8_t NumberOfBytes)
{
	if (NumberOfBytes < MINIMUMHEADERSIZE)
	{	// ToDo: throw according exception
		throw 1;
	}

	// reset stored checksum so we don't have to omit byte 10 and 11 when (re-)computing the icmp checksum
	_Data[10] = 0x00;
	_Data[11] = 0x00;

	Elysium::Core::uint32_t Checksum = 0;
	Elysium::Core::uint8_t BytesLeft = NumberOfBytes;
	Elysium::Core::uint16_t* DataPointer = (Elysium::Core::uint16_t*)&_Data[0];

	// sum up all 16bit values
	while (BytesLeft > 1)
	{
		Checksum += *DataPointer++;
		BytesLeft -= 2;
	}

	// if we're working with an odd number of bytes, we need to perform padding
	if (BytesLeft == 1)
	{
		Checksum += *(Elysium::Core::uint8_t*)DataPointer;
	}

	// high bit/low bit
	Checksum = (Checksum >> 16) + (Checksum & 0xFFFF);
	Checksum += (Checksum >> 16);

	// one's complement
	Checksum = ~Checksum;

	_Data[10] = Checksum & 0xFF;
	_Data[11] = Checksum >> 8;
}
