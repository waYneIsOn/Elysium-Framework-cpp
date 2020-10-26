#include "UdpClient.hpp"

#ifndef ELYSIUM_CORE_BITCONVERTER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#endif

Elysium::Communication::Transport::UdpClient::UdpClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion)
	: TransportBase(),
	_Socket(Elysium::Core::Net::Sockets::Socket(Elysium::Core::Net::Sockets::AddressFamily::InterNetwork,
		Elysium::Core::Net::Sockets::SocketType::Dgram, 
		Elysium::Core::Net::Sockets::ProtocolType::Udp))
{ }
Elysium::Communication::Transport::UdpClient::~UdpClient()
{ }

const bool Elysium::Communication::Transport::UdpClient::GetIsOpen() const
{
	return true;
}

void Elysium::Communication::Transport::UdpClient::Connect(const Elysium::Core::Net::EndPoint & RemoteEndPoint)
{
	// connecting means we can simply use Send and Receive instead of SendTo and ReceiveFrom
	_Socket.Connect(RemoteEndPoint);

	//_Socket.SetSocketOption(Elysium::Core::Net::Sockets::SocketOptionLevel::Socket, Elysium::Core::Net::Sockets::SocketOptionName::ReceiveTimeout, 10);

	// ...
	//_Socket.SetSocketOption(Elysium::Core::Net::Sockets::SocketOptionLevel::IP, Elysium::Core::Net::Sockets::SocketOptionName::IpTimeToLive, 1);

	// ...
	//_Socket.SetSocketOption(Elysium::Core::Net::Sockets::SocketOptionLevel::Socket, Elysium::Core::Net::Sockets::SocketOptionName::Error, 1);

	// Set the SIO_UDP_CONNRESET ioctl to true for this UDP socket. If this UDP socket
	//    ever sends a UDP packet to a remote destination that exists but there is
	//    no socket to receive the packet, an ICMP port unreachable message is returned
	//    to the sender. By default, when this is received the next operation on the
	//    UDP socket that send the packet will receive a SocketException. The native
	//    (Winsock) error that is received is WSAECONNRESET (10054). Since we don't want
	//    to wrap each UDP socket operation in a try/except, we'll disable this error
	//    for the socket with this ioctl call. IOControl is analogous to the WSAIoctl method of Winsock 2
	//const Elysium::Core::int32_t OptionOutValueLength = _Socket.IOControl(Elysium::Core::Net::Sockets::IOControlCode::UdpConnectionReset, true, nullptr, 0);
	//const Elysium::Core::int32_t OptionOutValueLength = _Socket.IOControl(Elysium::Core::Net::Sockets::IOControlCode::UdpConnectionReset, false, nullptr, 0);
}

void Elysium::Communication::Transport::UdpClient::Close()
{
	_Socket.Shutdown(Elysium::Core::Net::Sockets::SocketShutdown::Both);
	_Socket.Disconnect(true);
}

void Elysium::Communication::Transport::UdpClient::Write(const Elysium::Core::byte * Buffer, const size_t Length)
{
	_Socket.Send(Buffer, Length);
}

void Elysium::Communication::Transport::UdpClient::Flush()
{ }

const size_t Elysium::Communication::Transport::UdpClient::Read(Elysium::Core::byte * Buffer, const size_t Length)
{
	return _Socket.Receive(Buffer, Length);
}
