#include "IrcClient.hpp"

#ifndef ELYSIUM_COMMUNICATION_KNOWNTCPPORT
#include "KnownTcpPort.hpp"
#endif

const Elysium::Core::uint16_t Elysium::Communication::Service::Irc::IrcClient::DefaultIrcPort = static_cast<const Elysium::Core::uint16_t>(KnownTcpPort::Irc);

Elysium::Communication::Service::Irc::IrcClient::IrcClient()
	: _Socket(Elysium::Core::Net::Sockets::Socket(Elysium::Core::Net::Sockets::AddressFamily::InterNetwork, Elysium::Core::Net::Sockets::SocketType::Stream, Elysium::Core::Net::Sockets::ProtocolType::Tcp)),
	_Transport(Transport::TcpClient(_Socket)), _Protocol(Protocol::ApplicationLayer::InternetRelayChat(_Transport))
{ }
Elysium::Communication::Service::Irc::IrcClient::~IrcClient()
{ }

void Elysium::Communication::Service::Irc::IrcClient::Connect(const Elysium::Core::Net::EndPoint & RemoteEndPoint)
{
	_Socket.Connect(RemoteEndPoint);

	const Elysium::Core::String bsdf1 = _Protocol.ReadLine();
	const Elysium::Core::String bsdf2 = _Protocol.ReadLine();
	const Elysium::Core::String bsdf3 = _Protocol.ReadLine();
	const Elysium::Core::String bsdf4 = _Protocol.ReadLine();
}

void Elysium::Communication::Service::Irc::IrcClient::Disconnect()
{
	static const Elysium::Core::String GoodbyeMessage = Elysium::Core::String(u8"");

	_Protocol.WriteQuit(GoodbyeMessage);
	_Socket.Shutdown(Elysium::Core::Net::Sockets::SocketShutdown::Both);
	_Socket.Disconnect(true);
}

void Elysium::Communication::Service::Irc::IrcClient::Test()
{
	const Elysium::Core::String Bla = _Protocol.WriteHelp();
}
