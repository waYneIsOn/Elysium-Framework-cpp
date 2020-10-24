#include "TransmissionControlProtocol.hpp"

Elysium::Communication::Protocol::TransportLayer::TransmissionControlProtocol::TransmissionControlProtocol(Transport::TransportBase & Transport, const Elysium::Core::uint16_t SourcePort, const Elysium::Core::uint16_t DestinationPort)
	: BinaryProtocol(Transport),
	_SourcePort(SourcePort), _DestinationPort(DestinationPort)
{ }
Elysium::Communication::Protocol::TransportLayer::TransmissionControlProtocol::~TransmissionControlProtocol()
{ }
