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

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
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

				virtual void WriteString(const Elysium::Core::String* Value) = 0;
				/*
				virtual void WriteBool(bool Value) = 0;
				virtual void WriteByte(byte Value) = 0;
				virtual void WriteBinary(byte* Value, size_t Length);
				*/

				virtual size_t ReadString(Elysium::Core::String* Value) = 0;
			protected:
				ProtocolBase(Transport::TransportBase* Transport);

				Transport::TransportBase* _Transport;
			};
		}
	}
}
#endif
