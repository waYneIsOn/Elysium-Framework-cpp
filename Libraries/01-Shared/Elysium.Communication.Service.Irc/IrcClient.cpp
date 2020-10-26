#include "IrcClient.hpp"

#ifndef ELYSIUM_COMMUNICATION_KNOWNTCPPORT
#include "KnownTcpPort.hpp"
#endif

const Elysium::Core::uint16_t Elysium::Communication::Service::Irc::IrcClient::DefaultIrcPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::Irc);

Elysium::Communication::Service::Irc::IrcClient::IrcClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion)
	: _Transport(Transport::TcpClient(IPVersion)), _Protocol(Protocol::ApplicationLayer::InternetRelayChat(_Transport))
{ }
Elysium::Communication::Service::Irc::IrcClient::~IrcClient()
{ }

void Elysium::Communication::Service::Irc::IrcClient::Connect(const Elysium::Core::Net::EndPoint & RemoteEndPoint)
{
	_Transport.Connect(RemoteEndPoint);

	const Elysium::Core::String bsdf1 = _Protocol.ReadLine();
	const Elysium::Core::String bsdf2 = _Protocol.ReadLine();
	const Elysium::Core::String bsdf3 = _Protocol.ReadLine();
	const Elysium::Core::String bsdf4 = _Protocol.ReadLine();
}

void Elysium::Communication::Service::Irc::IrcClient::Disconnect()
{
	static const Elysium::Core::String GoodbyeMessage = Elysium::Core::String(u8"");

	_Protocol.WriteQuit(GoodbyeMessage);
	_Transport.Close();
}

void Elysium::Communication::Service::Irc::IrcClient::Test()
{
	const Elysium::Core::String Bla = _Protocol.WriteHelp();
}
