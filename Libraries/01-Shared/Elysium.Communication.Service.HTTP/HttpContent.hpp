/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCONTENT
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCONTENT

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
				class ELYSIUM_COMMUNICATION_API HttpContent
				{
				public:
					virtual ~HttpContent() = 0;
				protected:
					HttpContent();
				};
			}
		}
	}
}
#endif
