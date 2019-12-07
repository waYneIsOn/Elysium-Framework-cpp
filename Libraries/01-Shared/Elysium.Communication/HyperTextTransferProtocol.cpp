#include "HyperTextTransferProtocol.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::Collections::Template;

Elysium::Communication::Protocol::HyperTextTransferProtocol::HyperTextTransferProtocol(Transport::TransportBase & Transport)
	: TextProtocol(Transport)
{
}
Elysium::Communication::Protocol::HyperTextTransferProtocol::HyperTextTransferProtocol(Transport::TransportBase & Transport, const Elysium::Core::Text::Encoding & Encoding)
	: TextProtocol(Transport, Encoding)
{
}
Elysium::Communication::Protocol::HyperTextTransferProtocol::~HyperTextTransferProtocol()
{
}

Elysium::Core::String Elysium::Communication::Protocol::HyperTextTransferProtocol::ReadResponseHeader()
{
	if (_IndexOfMessageEnd != static_cast<size_t>(-1))
	{	// remove the last part of the previous message
		_TotalReadBuffer.RemoveRange(0, _IndexOfMessageEnd + 4);
		_IndexOfMessageEnd = static_cast<size_t>(-1);
	}

	// read until we reach \r\n\r\n
	size_t TotalBytesReceived = 0;
	size_t PossibleIndexOfHeaderEnd = 0;
	do
	{
		// read the next block of bytes and copy the block into the _TotalReadBuffer
		size_t BytesReceived = _Transport.Read(&_ReadBuffer[0], _ReadBufferSize);
		_TotalReadBuffer.AddRange(_ReadBuffer, BytesReceived);

		// check whether we are at the end
		do
		{
			PossibleIndexOfHeaderEnd = _TotalReadBuffer.IndexOf('\r', PossibleIndexOfHeaderEnd + 1);
			if (PossibleIndexOfHeaderEnd != -1)
			{
				if (PossibleIndexOfHeaderEnd + 3 <= _TotalReadBuffer.GetCount())
				{
					if (_TotalReadBuffer[PossibleIndexOfHeaderEnd + 1] == '\n' &&
						_TotalReadBuffer[PossibleIndexOfHeaderEnd + 2] == '\r' &&
						_TotalReadBuffer[PossibleIndexOfHeaderEnd + 3] == '\n')
					{
						_IndexOfMessageEnd = PossibleIndexOfHeaderEnd;
					}
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
	
	return _Encoding.GetString(&_TotalReadBuffer[0], _IndexOfMessageEnd);
}

void Elysium::Communication::Protocol::HyperTextTransferProtocol::ReadResponseContent(const size_t ContentLength, Elysium::Core::Collections::Template::List<Elysium::Core::Byte>* Value)
{
	// check _MessageBuilder for parts of previously received messages
	if (_IndexOfMessageEnd != -1)
	{	// remove the last part of the previous message
		/*
		if (_IndexOfMessageEnd + 4 == _TotalReadBuffer.GetCount())
		{
			_TotalReadBuffer.Clear();
		}
		else
		{
			_TotalReadBuffer.RemoveRange(0, _IndexOfMessageEnd + 4);
		}
		*/
		_TotalReadBuffer.RemoveRange(0, _IndexOfMessageEnd + 4);	// ToDo: shouldn't this be 2 for \r\n?
	}

	// read until we've got the whole content
	while (_TotalReadBuffer.GetCount() < ContentLength)
	{
		// read the next block of bytes and convert them to a string
		size_t BytesReceived = _Transport.Read(&_ReadBuffer[0], _ReadBufferSize);

		// copy the converted block into the _TotalReadBuffer
		_TotalReadBuffer.AddRange(_ReadBuffer, BytesReceived);
	}

	// write to output, clear the buffer and reset the index of message end
	if (ContentLength > 0)
	{
		Value->AddRange(&_TotalReadBuffer[0], ContentLength);
	}
	_TotalReadBuffer.Clear();
	_IndexOfMessageEnd = -1;
}
bool Elysium::Communication::Protocol::HyperTextTransferProtocol::ReadResponseContentChunk(Elysium::Core::Collections::Template::List<Elysium::Core::Byte>* Value)
{
	// check _MessageBuilder for parts of previously received messages
	if (_IndexOfMessageEnd != -1)
	{	// remove the last part of the previous message
		/*
		if (_IndexOfMessageEnd + 4 == _TotalReadBuffer.GetCount())
		{
			_TotalReadBuffer.Clear();
		}
		else
		{
			_TotalReadBuffer.RemoveRange(0, _IndexOfMessageEnd + 4);
		}
		*/
		_TotalReadBuffer.RemoveRange(0, _IndexOfMessageEnd + 4);	// ToDo: shouldn't this be 2 for \r\n?
	}
	
	// get the size of the chunk and read those bytes
	size_t ChunkSize = 0;
	size_t RequiredLength = -1;
	do
	{
		// check whether we've already got the chunk size
		_IndexOfMessageEnd = _TotalReadBuffer.IndexOf('\r');
		if (_IndexOfMessageEnd != -1)
		{
			if (_IndexOfMessageEnd + 1 <= _TotalReadBuffer.GetCount())
			{
				if (_TotalReadBuffer[_IndexOfMessageEnd + 1] == '\n')
				{
					ChunkSize = strtoul((const char*)&_TotalReadBuffer[0], nullptr, 16);
					RequiredLength = ChunkSize == 0 ? 5 : _IndexOfMessageEnd + 4 + ChunkSize;
				}
			}
		}

		if (_TotalReadBuffer.GetCount() < RequiredLength)
		{	// read more bytes and copy the block into the _TotalReadBuffer
			size_t BytesReceived = _Transport.Read(&_ReadBuffer[0], _ReadBufferSize);
			_TotalReadBuffer.AddRange(_ReadBuffer, BytesReceived);
		}
	} while (_TotalReadBuffer.GetCount() < RequiredLength);

	// copy content to Value and clean up _TotalReadBuffer afterwards
	Value->AddRange(&_TotalReadBuffer[_IndexOfMessageEnd + sizeof("\r\n") - 1], ChunkSize);
	//_TotalReadBuffer.RemoveRange(0, ChunkSize);
	_TotalReadBuffer.RemoveRange(0, RequiredLength);
	_IndexOfMessageEnd = -1;

	return ChunkSize == 0 ? false : true;
}
