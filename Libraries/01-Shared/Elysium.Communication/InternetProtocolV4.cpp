#include "InternetProtocolV4.hpp"

const Elysium::Core::int32_t Elysium::Communication::Protocol::InternetProtocolV4::VERSION = 4;

Elysium::Communication::Protocol::InternetProtocolV4::InternetProtocolV4(Transport::TransportBase & Transport)
	: ProtocolBase(Transport)
{ }
Elysium::Communication::Protocol::InternetProtocolV4::~InternetProtocolV4()
{ }
