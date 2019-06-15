#include "TextProtocol.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::Collections::Generic;

Elysium::Communication::Protocol::TextProtocol::TextProtocol(Transport::TransportBase * Transport)
	: ProtocolBase(Transport),
	_Encoding(Elysium::Core::Text::Encoding(*Elysium::Core::Text::Encoding::Default()))
{
	_TotalReadBuffer.Clear();
}
Elysium::Communication::Protocol::TextProtocol::TextProtocol(Transport::TransportBase * Transport, const Elysium::Core::Text::Encoding * Encoding)
	: ProtocolBase(Transport),
	_Encoding(Elysium::Core::Text::Encoding(*Encoding))
{
}
Elysium::Communication::Protocol::TextProtocol::~TextProtocol()
{
}

void Elysium::Communication::Protocol::TextProtocol::WriteBinary(const Elysium::Core::byte * Buffer, const size_t Length)
{
	_Transport->Write(Buffer, Length);
}
void Elysium::Communication::Protocol::TextProtocol::WriteString(const Elysium::Core::String * Value)
{
	Elysium::Core::Collections::Generic::List<Elysium::Core::byte> ByteBuffer;
	size_t BytesConverted = _Encoding.GetBytes(Value, 0, Value->GetLength(), &ByteBuffer);
	_Transport->Write(&ByteBuffer[0], BytesConverted);
}

size_t Elysium::Communication::Protocol::TextProtocol::ReadBinary(Elysium::Core::byte * Buffer, const size_t Length)
{
	return _Transport->Read(Buffer, Length);
}
size_t Elysium::Communication::Protocol::TextProtocol::ReadString(Elysium::Core::String * Value)
{
	return size_t();
	/*
	// check _MessageBuilder for parts of previously received messages
	if (_IndexOfMessageEnd != std::wstring::npos)
	{	// remove the last part of the previous message
		_MessageBuilder.Remove(0, _IndexOfMessageEnd + 4);

		// check whether we've already got the next message in _MessageBuilder
		_IndexOfMessageEnd = _MessageBuilder.IndexOf(L"\r\n\r\n");
		/*
		if (_IndexOfMessageEnd != std::wstring::npos)
		{
			int x = 45;
		}
		*-/
	}

	// read until we reach \r\n\r\n
	String PartialMessage;
	size_t TotalBytesConverted = 0;
	do
	{
		// read the next block of bytes and convert them to a string
		size_t BytesReceived = _Transport->Read(&_ReadBuffer[0], _ReadBufferSize);
		size_t BytesConverted = _Encoding.GetString(&_ReadBuffer[0], BytesReceived, &PartialMessage);

		// copy the converted block into the _MessageBuilder
		_MessageBuilder.Append(&PartialMessage[0], BytesConverted);

		// check whether we are at the end
		_IndexOfMessageEnd = _MessageBuilder.IndexOf(L"\r\n\r\n");
		if (_IndexOfMessageEnd == std::wstring::npos)
		{
			TotalBytesConverted += BytesConverted;
		}
		else
		{
			TotalBytesConverted += _IndexOfMessageEnd;
		}
	} while (_IndexOfMessageEnd == std::wstring::npos);

	_MessageBuilder.ToString(Value, TotalBytesConverted);
	return _MessageBuilder.GetLength();
	*/
}
