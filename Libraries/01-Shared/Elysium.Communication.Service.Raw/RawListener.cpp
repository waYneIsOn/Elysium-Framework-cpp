#include "RawListener.hpp"

#ifndef ELYSIUM_CORE_BITCONVERTER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#endif

Elysium::Communication::Service::Raw::RawListener::RawListener(const Elysium::Core::Net::Sockets::AddressFamily AddressFamily)
	: _Socket(Elysium::Core::Net::Sockets::Socket(AddressFamily, Elysium::Core::Net::Sockets::SocketType::Raw, Elysium::Core::Net::Sockets::ProtocolType::IP))
{ }
Elysium::Communication::Service::Raw::RawListener::~RawListener()
{ }

void Elysium::Communication::Service::Raw::RawListener::Bind(const Elysium::Core::Net::EndPoint & LocalEndPoint)
{
	_Socket.Bind(LocalEndPoint);
	_Socket.SetSocketOption(_Socket.GetAddressFamily() == Elysium::Core::Net::Sockets::AddressFamily::InterNetwork ? Elysium::Core::Net::Sockets::SocketOptionLevel::IP :
		Elysium::Core::Net::Sockets::SocketOptionLevel::IPv6, Elysium::Core::Net::Sockets::SocketOptionName::HeaderIncluded, true);
	
	// enter promiscuous mode -> https://en.wikipedia.org/wiki/Promiscuous_mode
	Elysium::Core::Collections::Template::Array<Elysium::Core::byte> OptionOutValue = Elysium::Core::BitConverter::GetBytes(0);
	const Elysium::Core::int32_t OptionOutValueLength = _Socket.IOControl(Elysium::Core::Net::Sockets::IOControlCode::ReceiveAll, 1, &OptionOutValue[0], OptionOutValue.GetLength());
}

const size_t Elysium::Communication::Service::Raw::RawListener::Read(Elysium::Core::byte * Buffer, const size_t Length)
{
	return _Socket.Receive(Buffer, Length);
}
