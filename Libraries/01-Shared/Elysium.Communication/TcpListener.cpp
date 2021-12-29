#include "TcpListener.hpp"

Elysium::Communication::Transport::TcpListener::TcpListener(const Protocol::InternetLayer::InternetProtocolVersion IPVersion)
	: StreamTransport(_InputNetworkStream, _OutputNetworkStream),
	_Socket(Elysium::Core::Net::Sockets::Socket(Elysium::Core::Net::Sockets::AddressFamily::InterNetwork, Elysium::Core::Net::Sockets::SocketType::Stream, Elysium::Core::Net::Sockets::ProtocolType::Tcp)),
	_InputNetworkStream(Elysium::Core::Net::Sockets::NetworkStream(_Socket, false)),
	_OutputNetworkStream(Elysium::Core::Net::Sockets::NetworkStream(_Socket, false))
{ }
Elysium::Communication::Transport::TcpListener::~TcpListener()
{ }

const bool Elysium::Communication::Transport::TcpListener::GetIsOpen() const
{
	return _Socket.GetIsConnected();
}

void Elysium::Communication::Transport::TcpListener::Start(const Elysium::Core::Net::EndPoint & LocalEndPoint, const Elysium::Core::int32_t Backlog)
{
	_Socket.Bind(LocalEndPoint);
	_Socket.Listen(Backlog);
}

void Elysium::Communication::Transport::TcpListener::Stop()
{
	//_Socket.Shutdown(Elysium::Core::Net::Sockets::SocketShutdown::Both);
	//_Socket.Disconnect(true);
	_Socket.Close();
}

Elysium::Core::Net::Sockets::Socket Elysium::Communication::Transport::TcpListener::AcceptSocket()
{
	return _Socket.Accept();
}

const Elysium::Communication::Transport::TcpClient Elysium::Communication::Transport::TcpListener::AcceptTcpClient()
{
	return TcpClient(AcceptSocket());
}

const Elysium::Core::IAsyncResult * Elysium::Communication::Transport::TcpListener::BeginAcceptSocket(const Elysium::Core::Template::Container::Delegate<void, const Elysium::Core::IAsyncResult*>& Callback, void * State)
{
	return _Socket.BeginAccept(Callback, State);
}

Elysium::Core::Net::Sockets::Socket Elysium::Communication::Transport::TcpListener::EndAcceptSocket(const Elysium::Core::IAsyncResult * Result)
{
	return _Socket.EndAccept(Result);
}

const Elysium::Core::IAsyncResult * Elysium::Communication::Transport::TcpListener::BeginAcceptTcpClient(const Elysium::Core::Template::Container::Delegate<void, const Elysium::Core::IAsyncResult*>& Callback, void * State)
{
	return _Socket.BeginAccept(Callback, State);
}

const Elysium::Communication::Transport::TcpClient Elysium::Communication::Transport::TcpListener::EndAcceptTcpClient(const Elysium::Core::IAsyncResult * Result)
{
	return TcpClient(EndAcceptSocket(Result));
}

