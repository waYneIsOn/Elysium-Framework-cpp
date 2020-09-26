#include "TextProtocol.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::Collections::Template;

Elysium::Communication::Protocol::TextProtocol::TextProtocol(Transport::TransportBase & Transport, const Elysium::Core::Text::Encoding & Encoding)
	: ProtocolBase(Transport), _Encoding(Encoding)
{
	_TotalReadBuffer.Clear();
}
Elysium::Communication::Protocol::TextProtocol::~TextProtocol()
{ }

void Elysium::Communication::Protocol::TextProtocol::WriteString(const Elysium::Core::String & Value)
{
	Elysium::Core::Collections::Template::Array<Elysium::Core::byte> ByteBuffer = _Encoding.GetBytes(Value, 0, Value.GetLength());
	_Transport.Write(&ByteBuffer[0], ByteBuffer.GetLength());
}

const Elysium::Core::String Elysium::Communication::Protocol::TextProtocol::ReadLine()
{
	if (_IndexOfMessageEnd != static_cast<size_t>(-1))
	{	// remove the last part of the previous message
		_TotalReadBuffer.RemoveRange(0, _IndexOfMessageEnd + 2);
		_IndexOfMessageEnd = static_cast<size_t>(-1);
	}

	size_t TotalBytesReceived = 0;
	size_t PossibleIndexOfHeaderEnd = 0;
	while (true)
	{
		PossibleIndexOfHeaderEnd = _TotalReadBuffer.IndexOf('\r', PossibleIndexOfHeaderEnd + 1);
		if (PossibleIndexOfHeaderEnd != -1)
		{
			if (PossibleIndexOfHeaderEnd + 1 <= _TotalReadBuffer.GetCount())
			{
				if (_TotalReadBuffer[PossibleIndexOfHeaderEnd + 1] == '\n')
				{
					_IndexOfMessageEnd = PossibleIndexOfHeaderEnd;
					return _Encoding.GetString(&_TotalReadBuffer[0], _IndexOfMessageEnd);
				}
			}
		}

		size_t BytesReceived = _Transport.Read(&_ReadBuffer[0], _ReadBufferSize);
		/*
		if (BytesReceived == 0)
		{	// ToDo: if we get here, something is wrong!
			break;
		}
		*/
		_TotalReadBuffer.AddRange(_ReadBuffer, BytesReceived);
		TotalBytesReceived += BytesReceived;
	}
}

void Elysium::Communication::Protocol::TextProtocol::WriteBinary(const Elysium::Core::byte * Buffer, const size_t Length)
{
	_Transport.Write(Buffer, Length);
}

const size_t Elysium::Communication::Protocol::TextProtocol::ReadBinary(Elysium::Core::byte * Buffer, const size_t Length)
{
	return _Transport.Read(Buffer, Length);
}
