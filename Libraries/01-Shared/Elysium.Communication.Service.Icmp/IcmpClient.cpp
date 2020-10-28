#include "IcmpClient.hpp"

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_IPV4HEADER
#include "../Elysium.Communication/IpV4Header.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_ICMPV4HEADER
#include "../Elysium.Communication/IcmpV4Header.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_IPENDPOINT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/IPEndPoint.hpp"
#endif

Elysium::Communication::Service::Icmp::IcmpClient::IcmpClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion)
	: _Socket(Elysium::Core::Net::Sockets::Socket(Elysium::Core::Net::Sockets::AddressFamily::InterNetwork, Elysium::Core::Net::Sockets::SocketType::Raw, 
		Elysium::Core::Net::Sockets::ProtocolType::Icmp))
{ }
Elysium::Communication::Service::Icmp::IcmpClient::~IcmpClient()
{ }

void Elysium::Communication::Service::Icmp::IcmpClient::Initialize()
{
	_Socket.Bind(Elysium::Core::Net::IPEndPoint(Elysium::Core::Net::IPAddress::Any(), 0));
	/*
	// seems like we cannot use ProtocolType::Raw and write the IPv4Message
	// this might be a limitation of winsock since we could do all sorts of silly stuff otherise
	_Socket.SetSocketOption(_Socket.GetAddressFamily() == Elysium::Core::Net::Sockets::AddressFamily::InterNetwork ? Elysium::Core::Net::Sockets::SocketOptionLevel::IP :
		Elysium::Core::Net::Sockets::SocketOptionLevel::IPv6, Elysium::Core::Net::Sockets::SocketOptionName::HeaderIncluded, true);
	*/
	_Socket.SetSocketOption(_Socket.GetAddressFamily() == Elysium::Core::Net::Sockets::AddressFamily::InterNetwork ? Elysium::Core::Net::Sockets::SocketOptionLevel::IP :
		Elysium::Core::Net::Sockets::SocketOptionLevel::IPv6, Elysium::Core::Net::Sockets::SocketOptionName::IpTimeToLive, 128);
}

void Elysium::Communication::Service::Icmp::IcmpClient::Close()
{
	_Socket.Shutdown(Elysium::Core::Net::Sockets::SocketShutdown::Both);
	_Socket.Disconnect(true);
}

void Elysium::Communication::Service::Icmp::IcmpClient::Ping(const Elysium::Core::Net::EndPoint& RemoteEndPoint)
{
	/*
	// seems like we cannot use ProtocolType::Raw and write the IPv4Message
	// this might be a limitation of winsock since we could do all sorts of silly stuff otherise
	Elysium::Core::byte IPv4RequestMessage[Protocol::InternetLayer::IPv4Header::MINIMUMHEADERSIZE + Protocol::InternetLayer::IcmpV4Header::HEADERSIZE + 32];
	const size_t SizeOfIPv4RequestMessage = sizeof(IPv4RequestMessage);
	const size_t SizeOfIPv4RequestHeader = Protocol::InternetLayer::IPv4Header::MINIMUMHEADERSIZE;
	const size_t SizeOfIcmpRequestMessage = sizeof(IPv4RequestMessage - Protocol::InternetLayer::IPv4Header::MINIMUMHEADERSIZE);

	Protocol::InternetLayer::IPv4Header* IPv4RequestHeader = (Protocol::InternetLayer::IPv4Header*)&IPv4RequestMessage;
	IPv4RequestHeader->SetVersion(4);
	IPv4RequestHeader->SetHeaderLength(Protocol::InternetLayer::IPv4Header::MINIMUMHEADERSIZE / 4);
	IPv4RequestHeader->SetDifferentiatedServicesCodePoint(0);
	IPv4RequestHeader->SetExplicitCongestionNotification(0);
	IPv4RequestHeader->SetTotalLength(SizeOfIPv4RequestMessage);
	IPv4RequestHeader->SetIdentification(0);
	IPv4RequestHeader->SetReservedFlag(false);
	IPv4RequestHeader->SetDontFragmentFlag(true);
	IPv4RequestHeader->SetMoreFragmentsFlag(false);
	IPv4RequestHeader->SetFragmentOffset(0);
	IPv4RequestHeader->SetTimeToLive(128);
	IPv4RequestHeader->SetProtocol(Protocol::InternetLayer::InternetProtocolNumber::Icmp);
	IPv4RequestHeader->SetSourceIPAddress(3232235876);
	IPv4RequestHeader->SetDestinationIPAddress(3232235777);
	IPv4RequestHeader->ComputeAndSetChecksum(SizeOfIPv4RequestHeader);

	Protocol::InternetLayer::IcmpV4Header* RequestHeader = (Protocol::InternetLayer::IcmpV4Header*)&IPv4RequestMessage[Protocol::InternetLayer::IPv4Header::MINIMUMHEADERSIZE];
	RequestHeader->SetType(Elysium::Communication::Protocol::InternetLayer::IcmpType::EchoRequest);
	RequestHeader->SetCode(0);
	RequestHeader->SetRestOfHeader(0x0100 | (0x9700 << 16));	// Id and sequence number
	RequestHeader->ComputeAndSetChecksum(SizeOfIcmpRequestMessage);

	const size_t BytesSent = _Socket.SendTo(&IPv4RequestMessage[0], SizeOfIPv4RequestMessage, RemoteEndPoint);
	*/
	Elysium::Core::byte IcmpRequestMessage[Protocol::InternetLayer::IcmpV4Header::HEADERSIZE + 32];
	const size_t SizeOfIcmpRequestMessage = sizeof(IcmpRequestMessage);

	Protocol::InternetLayer::IcmpV4Header* RequestHeader = (Protocol::InternetLayer::IcmpV4Header*)&IcmpRequestMessage;
	RequestHeader->SetType(Elysium::Communication::Protocol::InternetLayer::IcmpType::EchoRequest);
	RequestHeader->SetCode(0);
	RequestHeader->SetRestOfHeader(0x0100 | (0x9700 << 16));	// Id and sequence number
	RequestHeader->ComputeAndSetChecksum(SizeOfIcmpRequestMessage);

	const size_t BytesSent = _Socket.SendTo(&IcmpRequestMessage[0], SizeOfIcmpRequestMessage, RemoteEndPoint);

	Elysium::Core::byte IcmpResponseMessage[1024];
	Elysium::Core::Net::IPEndPoint ReceiverEndPoint = Elysium::Core::Net::IPEndPoint(Elysium::Core::Net::IPAddress::Any(), 0);
	const size_t BytesReceived = _Socket.ReceiveFrom(&IcmpResponseMessage[0], sizeof(IcmpResponseMessage), ReceiverEndPoint);

	Protocol::InternetLayer::IPv4Header* IPv4ResponseHeader = (Protocol::InternetLayer::IPv4Header*)&IcmpResponseMessage;
	const Elysium::Core::uint8_t IpVersion = IPv4ResponseHeader->GetVersion();
	const Elysium::Core::uint8_t IpTimeToLive = IPv4ResponseHeader->GetTimeToLive();
	const Elysium::Core::uint16_t IpSourceAddress = IPv4ResponseHeader->GetSourceIPAddress();
}
