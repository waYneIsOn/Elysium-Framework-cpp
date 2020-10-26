#include "TcpClient.hpp"

using namespace Elysium::Core::Net::Sockets;

Elysium::Communication::Transport::TcpClient::TcpClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion)
	: StreamTransport(_InputNetworkStream, _OutputNetworkStream),
	_Socket(Elysium::Core::Net::Sockets::Socket(Elysium::Core::Net::Sockets::AddressFamily::InterNetwork, Elysium::Core::Net::Sockets::SocketType::Stream, Elysium::Core::Net::Sockets::ProtocolType::Tcp)),
	_InputNetworkStream(NetworkStream(_Socket, false)),
	_OutputNetworkStream(NetworkStream(_Socket, false))
{ }
Elysium::Communication::Transport::TcpClient::~TcpClient()
{ }

const bool Elysium::Communication::Transport::TcpClient::GetIsOpen() const
{
	return _Socket.GetIsConnected();
}

void Elysium::Communication::Transport::TcpClient::Connect(const Elysium::Core::String & Host, int Port)
{
	_Socket.Connect(Host, Port);
}
void Elysium::Communication::Transport::TcpClient::Connect(const Elysium::Core::Net::EndPoint & RemoteEndPoint)
{
	_Socket.Connect(RemoteEndPoint);
}
void Elysium::Communication::Transport::TcpClient::Close()
{
	_Socket.Shutdown(Elysium::Core::Net::Sockets::SocketShutdown::Both);
	_Socket.Disconnect(true);
}
