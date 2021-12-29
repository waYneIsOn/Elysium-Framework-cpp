#include "RfbClient.hpp"

Elysium::Communication::Service::Rfb::RfbClient::RfbClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion)
	: _Transport(Transport::TcpClient(IPVersion)), _Protocol(Protocol::ApplicationLayer::RemoteFrameBufferProtocol(_Transport))
{ }

Elysium::Communication::Service::Rfb::RfbClient::~RfbClient()
{ }

void Elysium::Communication::Service::Rfb::RfbClient::Connect(const Elysium::Core::Net::EndPoint& RemoteEndPoint)
{
	_Transport.Connect(RemoteEndPoint);
	Elysium::Core::Utf8String AvailableProtocolVersions = _Protocol.ReadAvailableProtocolVersions();

	bool bla = false;
}

void Elysium::Communication::Service::Rfb::RfbClient::Disconnect()
{
	//_Protocol.WriteQuit();
	_Transport.Close();
}
