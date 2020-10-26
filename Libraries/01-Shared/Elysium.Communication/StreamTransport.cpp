#include "StreamTransport.hpp"

Elysium::Communication::Transport::StreamTransport::StreamTransport(Elysium::Core::IO::Stream & InputStream, Elysium::Core::IO::Stream & OutputStream)
	: TransportBase(),
	_InputStream(InputStream), _OutputStream(OutputStream)
{ }
Elysium::Communication::Transport::StreamTransport::~StreamTransport()
{ }

Elysium::Core::IO::Stream & Elysium::Communication::Transport::StreamTransport::GetInputStream() const
{
	return _InputStream;
}

Elysium::Core::IO::Stream & Elysium::Communication::Transport::StreamTransport::GetOutputStream() const
{
	return _OutputStream;
}

void Elysium::Communication::Transport::StreamTransport::Write(const Elysium::Core::byte * Buffer, const size_t Length)
{
	_OutputStream.Write(Buffer, Length);
}

void Elysium::Communication::Transport::StreamTransport::Flush()
{
	_OutputStream.Flush();
}

const size_t Elysium::Communication::Transport::StreamTransport::Read(Elysium::Core::byte * Buffer, const size_t Length)
{
	return _InputStream.Read(Buffer, Length);
}
