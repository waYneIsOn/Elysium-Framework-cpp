/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TRANSPORTBASE
#define ELYSIUM_COMMUNICATION_TRANSPORT_TRANSPORTBASE

#ifndef ELYSIUM_COMMUNICATION_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_CORE_BYTE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Byte.hpp"
#endif

namespace Elysium::Communication::Transport
{
	class ELYSIUM_COMMUNICATION_API TransportBase
	{
	public:
		virtual ~TransportBase();
				
		virtual bool GetIsOpen() const = 0;
				
		//bool Peek();
		//virtual void Open() = 0;
		//virtual void Close() = 0;
		/*
		virtual int Read(...) = 0;
		virtual void Write(...) = 0;
		virtual void Flush();
		*/
		virtual size_t Read(Elysium::Core::byte* Buffer, const size_t Length) = 0;
		virtual void Write(const Elysium::Core::byte* Buffer, const size_t Length) = 0;
		virtual void Flush();
	protected:
		TransportBase();
	};
}
#endif
