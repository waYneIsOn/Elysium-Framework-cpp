#include "SocketTransport.hpp"

using namespace Elysium::Core::Net::Sockets;

Elysium::Communication::Transport::SocketTransport::SocketTransport(Elysium::Core::Net::Sockets::Socket * Socket)
	: _InputNetworkStream(NetworkStream(Socket, false)),
	_OutputNetworkStream(NetworkStream(Socket, false)),
	_Socket(Socket),
	StreamTransport(&_InputNetworkStream, &_OutputNetworkStream)
{
}
Elysium::Communication::Transport::SocketTransport::~SocketTransport()
{
}

const Elysium::Core::Net::Sockets::Socket * Elysium::Communication::Transport::SocketTransport::GetSocket() const
{
	return _Socket;
}
