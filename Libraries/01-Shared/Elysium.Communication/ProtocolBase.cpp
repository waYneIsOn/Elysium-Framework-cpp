#include "ProtocolBase.hpp"

Elysium::Communication::Protocol::ProtocolBase::~ProtocolBase()
{ }

Elysium::Communication::Protocol::ProtocolBase::ProtocolBase(Transport::TransportBase & Transport)
	: _Transport(Transport)
{ }