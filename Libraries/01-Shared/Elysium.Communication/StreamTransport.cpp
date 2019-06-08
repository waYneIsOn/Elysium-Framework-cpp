#include "StreamTransport.hpp"

Elysium::Communication::Transport::StreamTransport::StreamTransport(Elysium::Core::IO::Stream * InputStream, Elysium::Core::IO::Stream * OutputStream)
	: TransportBase(),
	_InputStream(InputStream), _OutputStream(OutputStream)
{
}

Elysium::Communication::Transport::StreamTransport::~StreamTransport()
{
}

bool Elysium::Communication::Transport::StreamTransport::GetIsOpen() const
{
	return true;
}
const Elysium::Core::IO::Stream * Elysium::Communication::Transport::StreamTransport::GetInputStream() const
{
	return _InputStream;
}
const Elysium::Core::IO::Stream * Elysium::Communication::Transport::StreamTransport::GetOutputStream() const
{
	return _OutputStream;
}
/*
void Elysium::Communication::Transport::StreamTransport::Open()
{
}
void Elysium::Communication::Transport::StreamTransport::Close()
{
	if (_InputStream != nullptr)
	{
		_InputStream->Close();
		_InputStream = nullptr;
	}
	if (_OutputStream != nullptr)
	{
		_OutputStream->Close();
		_OutputStream = nullptr;
	}
}
*/
Elysium::Communication::Transport::StreamTransport::StreamTransport()
	: TransportBase(),
	_InputStream(nullptr), _OutputStream(nullptr)
{
}
