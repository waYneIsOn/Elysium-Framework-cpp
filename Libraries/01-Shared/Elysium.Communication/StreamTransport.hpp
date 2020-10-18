/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_STREAMTRANSPORT
#define ELYSIUM_COMMUNICATION_TRANSPORT_STREAMTRANSPORT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TRANSPORTBASE
#include "TransportBase.hpp"
#endif

#ifndef ELYSIUM_CORE_IO_STREAM
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/Stream.hpp"
#endif

namespace Elysium::Communication::Transport
{
	class ELYSIUM_COMMUNICATION_API StreamTransport : public TransportBase
	{
	public:
		StreamTransport(Elysium::Core::IO::Stream& InputStream, Elysium::Core::IO::Stream& OutputStream);
		virtual ~StreamTransport();

		virtual bool GetIsOpen() const override;
		Elysium::Core::IO::Stream& GetInputStream() const;
		Elysium::Core::IO::Stream& GetOutputStream() const;

		//virtual void Open() override;
		//virtual void Close() override;
		//int Read(...);
		//void Write(...);
		//void Flush();
		virtual size_t Read(Elysium::Core::byte* Buffer, const size_t Length) override;
		virtual void Write(const Elysium::Core::byte* Buffer, const size_t Length) override;
	protected:
		Elysium::Core::IO::Stream& _InputStream;
		Elysium::Core::IO::Stream& _OutputStream;
	};
}
#endif
