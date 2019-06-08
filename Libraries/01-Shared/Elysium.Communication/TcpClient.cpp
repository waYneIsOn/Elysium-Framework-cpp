#include "TcpClient.hpp"

using namespace Elysium::Core::Net::Sockets;
using namespace Elysium::Core::Text;

Elysium::Communication::Service::Tcp::TcpClient::TcpClient(Elysium::Core::Net::Sockets::Socket * Socket, Elysium::Communication::Transport::TransportBase * Transport, Elysium::Communication::Protocol::ProtocolBase * Protocol)
	: _Socket(Socket), _Transport(Transport), _Protocol(Protocol)
{
}
Elysium::Communication::Service::Tcp::TcpClient::~TcpClient()
{
}

void Elysium::Communication::Service::Tcp::TcpClient::Connect(Elysium::Core::String & Host, int Port)
{
	_Socket->Connect(Host, Port);
}
void Elysium::Communication::Service::Tcp::TcpClient::Close()
{
	_Socket->Disconnect(true);
}
