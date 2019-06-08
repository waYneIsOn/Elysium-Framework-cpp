/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE
#define ELYSIUM_COMMUNICATION_PROTOCOL_PROTOCOLBASE

#ifndef ELYSIUM_COMMUNICATION_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_TRANSPORT_TRANSPORTBASE
#include "TransportBase.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Protocol
		{
			class ELYSIUM_COMMUNICATION_API ProtocolBase
			{
			public:
				virtual ~ProtocolBase();
				/*
				virtual void WriteBool(bool Value) = 0;
				virtual void WriteByte(byte Value) = 0;
				virtual void WriteString(String& Value) = 0;
				virtual void WriteBinary(byte* Value, size_t Length);
				*/
			protected:
				ProtocolBase(const Transport::TransportBase* Transport);

				const Transport::TransportBase* _Transport;
			};
		}
	}
}
#endif
