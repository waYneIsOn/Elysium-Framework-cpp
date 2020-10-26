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

const Elysium::Core::uint16_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetSourceIPAddress() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[10]);
}

const Elysium::Core::uint16_t Elysium::Communication::Protocol::InternetLayer::IPv4Header::GetDestrinationIPAddress() const
{
	return Elysium::Core::BitConverter::ToUInt16(&_Data[10]);
}
