/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPRESPONSEMESSAGE
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPRESPONSEMESSAGE

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				class ELYSIUM_COMMUNICATION_API HttpResponseMessage final
				{
				public:
					HttpResponseMessage();
					~HttpResponseMessage();
				};
			}
		}
	}
}
#endif
