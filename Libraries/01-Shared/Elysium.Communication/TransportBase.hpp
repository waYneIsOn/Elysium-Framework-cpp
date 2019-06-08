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

namespace Elysium
{
	namespace Communication
	{
		namespace Transport
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
			protected:
				TransportBase();
			};
		}
	}
}
#endif
