#include "InternetProtocol.hpp"

#ifndef ELYSIUM_CORE_BITCONVERTER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#endif

Elysium::Communication::Protocol::InternetLayer::InternetProtocol::InternetProtocol(Transport::TransportBase & Transport, const Elysium::Core::uint8_t Version)
	: BinaryProtocol(Transport),
	_Version(Version)
{ }
Elysium::Communication::Protocol::InternetLayer::InternetProtocol::~InternetProtocol()
{ }
