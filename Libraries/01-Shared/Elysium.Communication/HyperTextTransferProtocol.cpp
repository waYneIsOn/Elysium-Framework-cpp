#include "HyperTextTransferProtocol.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::Collections::Generic;

Elysium::Communication::Protocol::HyperTextTransferProtocol::HyperTextTransferProtocol(Transport::TransportBase * Transport)
	: TextProtocol(Transport)
{
}
Elysium::Communication::Protocol::HyperTextTransferProtocol::HyperTextTransferProtocol(Transport::TransportBase * Transport, const Elysium::Core::Text::Encoding * Encoding)
	: TextProtocol(Transport, Encoding)
{
}
Elysium::Communication::Protocol::HyperTextTransferProtocol::~HyperTextTransferProtocol()
{
}

void Elysium::Communication::Protocol::HyperTextTransferProtocol::ReadResponseHeader(Elysium::Core::String * Value)
{
	// read until we reach \r\n\r\n
	size_t TotalBytesReceived = 0;
	size_t PossibleIndexOfHeaderEnd = 0;
	do
	{
		// read the next block of bytes and convert them to a string
		size_t BytesReceived = _Transport->Read(&_ReadBuffer[0], _ReadBufferSize);

		// copy the converted block into the _MessageBuilder
		_TotalReadBuffer.AddRange(_ReadBuffer, 0, BytesReceived);

		// check whether we are at the end
		do
		{
			PossibleIndexOfHeaderEnd = _TotalReadBuffer.IndexOf('\r', PossibleIndexOfHeaderEnd + 1);
			if (PossibleIndexOfHeaderEnd + 3 <= _TotalReadBuffer.GetCount())
			{
				if (_TotalReadBuffer[PossibleIndexOfHeaderEnd + 1] == '\n' &&
					_TotalReadBuffer[PossibleIndexOfHeaderEnd + 2] == '\r' &&
					_TotalReadBuffer[PossibleIndexOfHeaderEnd + 3] == '\n')
				{
					_IndexOfMessageEnd = PossibleIndexOfHeaderEnd;
				}
			}
		} while (_IndexOfMessageEnd == -1 && PossibleIndexOfHeaderEnd != -1);

		if (_IndexOfMessageEnd == -1)
		{
			TotalBytesReceived += BytesReceived;
		}
		else
		{
			TotalBytesReceived += _IndexOfMessageEnd;
		}
	} while (_IndexOfMessageEnd == -1);

	size_t BytesConverted = _Encoding.GetString(&_TotalReadBuffer[0], _IndexOfMessageEnd, Value);
}
void Elysium::Communication::Protocol::HyperTextTransferProtocol::ReadResponseContent(const size_t ContentLength, Elysium::Core::String * Value)
{
	// check _MessageBuilder for parts of previously received messages
	if (_IndexOfMessageEnd != -1)
	{	// remove the last part of the previous message
		_TotalReadBuffer.RemoveRange(0, _IndexOfMessageEnd + 4);
	}

	if (ContentLength > _TotalReadBuffer.GetCount())
	{
		throw NotImplementedException();
	}
	else
	{	// we've already go the whole content
		size_t BytesConverted = _Encoding.GetString(&_TotalReadBuffer[0], ContentLength, Value);
	}
}
