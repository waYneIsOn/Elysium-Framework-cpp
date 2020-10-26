/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TRANSPORTBASE
#define ELYSIUM_COMMUNICATION_TRANSPORT_TRANSPORTBASE

#ifdef _MSC_VER
#pragma once
#endif

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
		
		virtual const bool GetIsOpen() const = 0;
		
		//bool Peek();
		virtual void Write(const Elysium::Core::byte* Buffer, const size_t Length) = 0;

		virtual void Flush() = 0;

		virtual const size_t Read(Elysium::Core::byte* Buffer, const size_t Length) = 0;
	protected:
		TransportBase();
	};
}
#endif
