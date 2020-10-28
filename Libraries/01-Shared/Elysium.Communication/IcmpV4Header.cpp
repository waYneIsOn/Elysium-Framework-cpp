#include "IcmpV4Header.hpp"

#ifndef ELYSIUM_CORE_BITCONVERTER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#endif

Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::IcmpV4Header()
{ }
Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::~IcmpV4Header()
{ }

const Elysium::Communication::Protocol::InternetLayer::IcmpType Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::GetType() const
{
	return static_cast<const Elysium::Communication::Protocol::InternetLayer::IcmpType>(_Data[0]);
}

const Elysium::Core::uint8_t Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::GetCode() const
{
	return _Data[1];
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::GetChecksum() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[2]);
}

const Elysium::Core::uint32_t Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::GetRestOfHeader() const
{
	return Elysium::Core::BitConverter::ToUInt32(&_Data[4]);
}

void Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::SetType(const IcmpType Value)
{
	_Data[0] = static_cast<const Elysium::Core::byte>(Value);
}

void Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::SetCode(const Elysium::Core::uint8_t Value)
{
	if (!IsValidCode(GetType(), Value))
	{	// ToDo: throw specific exception
		throw 1;
	}

	_Data[1] = Value;
}

void Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::SetRestOfHeader(const Elysium::Core::uint32_t Value)
{
	_Data[4] = Value & 0xFF;
	_Data[5] = Value >> 8;
	_Data[6] = Value >> 16;
	_Data[7] = Value >> 24;
}

void Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::ComputeAndSetChecksum(const Elysium::Core::uint8_t NumberOfBytes)
{
	if (NumberOfBytes < HEADERSIZE)
	{	// ToDo: throw according exception
		throw 1;
	}

	// reset stored checksum so we don't have to omit byte 2 and 3 when (re-)computing the icmp checksum
	_Data[2] = 0x00;
	_Data[3] = 0x00;

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

	_Data[2] = Checksum & 0xFF;
	_Data[3] = Checksum >> 8;
}

const bool Elysium::Communication::Protocol::InternetLayer::IcmpV4Header::IsValidCode(const IcmpType Type, const Elysium::Core::uint8_t Code)
{
	switch (Type)
	{
	case IcmpType::EchoReply:
	case IcmpType::SourceQuench:
	case IcmpType::EchoRequest:
	case IcmpType::RouterAdvertisement:
	case IcmpType::RouterSolicitation:
	case IcmpType::Timestamp:
	case IcmpType::TimestampReply:
	case IcmpType::InformationRequest:
	case IcmpType::AddressMaskRequest:
	case IcmpType::AddressMaskReply:
	case IcmpType::Traceroute:
	case IcmpType::ExtendedEchoRequest:
		return Code == 0;
	case IcmpType::DestinationUnreachable:
		return Code < 16;
	case IcmpType::RedirectMessage:
		return Code < 4;
	case IcmpType::TimeExceeded:
		return Code < 2;
	case IcmpType::ParameterProblemBadIPHeader:
		return Code < 3;
	case IcmpType::ExtendedEchoReply:
		return Code < 5;
	default:
		return false;
	}
}
