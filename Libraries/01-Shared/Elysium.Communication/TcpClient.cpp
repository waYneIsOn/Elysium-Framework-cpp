#include "TcpClient.hpp"

using namespace Elysium::Core::Net::Sockets;

Elysium::Communication::Transport::TcpClient::TcpClient(Elysium::Core::Net::Sockets::Socket & Socket)
	: _Socket(Socket), 
	_InputNetworkStream(NetworkStream(Socket, false)),
	_OutputNetworkStream(NetworkStream(Socket, false)),
	StreamTransport(_InputNetworkStream, _OutputNetworkStream)
{ }
Elysium::Communication::Transport::TcpClient::~TcpClient()
{ }

const Elysium::Core::Net::Sockets::Socket & Elysium::Communication::Transport::TcpClient::GetSocket() const
{
	return _Socket;
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
	_Socket.Disconnect(true);
}
