#include "TcpClient.hpp"

using namespace Elysium::Core::Net::Sockets;

Elysium::Communication::Service::Tcp::TcpClient::TcpClient()
	: _Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp),
	_Transport(&_Socket),
	_Protocol(&_Transport)
{
}
Elysium::Communication::Service::Tcp::TcpClient::~TcpClient()
{
}

void Elysium::Communication::Service::Tcp::TcpClient::Connect(Elysium::Core::String & Host, int Port)
{
	_Socket.Connect(Host, Port);
}
void Elysium::Communication::Service::Tcp::TcpClient::Close()
{
	_Socket.Disconnect(true);
}
