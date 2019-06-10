#include "TextProtocol.hpp"

Elysium::Communication::Protocol::TextProtocol::TextProtocol(Transport::TransportBase * Transport)
	: ProtocolBase(Transport),
	_Encoding(Elysium::Core::Text::Encoding(*Elysium::Core::Text::Encoding::Default()))
{
}
Elysium::Communication::Protocol::TextProtocol::TextProtocol(Transport::TransportBase * Transport, const Elysium::Core::Text::Encoding * Encoding)
	: ProtocolBase(Transport),
	_Encoding(Elysium::Core::Text::Encoding(*Encoding))
{
}
Elysium::Communication::Protocol::TextProtocol::~TextProtocol()
{
}

void Elysium::Communication::Protocol::TextProtocol::WriteString(const Elysium::Core::String * Value)
{
	Elysium::Core::Collections::Generic::List<Elysium::Core::byte> ByteBuffer;
	size_t BytesConverted = _Encoding.GetBytes(Value, 0, Value->GetLength(), &ByteBuffer);
	_Transport->Write(&ByteBuffer[0], BytesConverted);
}

void Elysium::Communication::Protocol::TextProtocol::ReadString(Elysium::Core::String * Value)
{
	Elysium::Core::byte Buffer[1024];
	size_t BytesRead = _Transport->Read(&Buffer[0], 1024);
	
	int x = 345;
}
