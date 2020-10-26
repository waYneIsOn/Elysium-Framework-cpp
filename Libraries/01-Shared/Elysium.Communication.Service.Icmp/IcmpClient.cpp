#include "IcmpClient.hpp"

Elysium::Communication::Service::Icmp::IcmpClient::IcmpClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion)
	//: _Transport(Transport::TcpClient(IPVersion)), _Protocol(Protocol::ApplicationLayer::InternetRelayChat(_Transport))
{
	// socket(PF_INET, SOCK_DGRAM, PROT_ICMP)
	// socket(PF_INET, RAAAAAAAAW, PROT_ICMP)
}
Elysium::Communication::Service::Icmp::IcmpClient::~IcmpClient()
{ }
