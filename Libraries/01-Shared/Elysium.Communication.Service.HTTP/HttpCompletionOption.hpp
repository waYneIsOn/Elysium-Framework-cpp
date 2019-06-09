/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCOMPLETIONOPTION
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HTTPCOMPLETIONOPTION

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				enum class HttpCompletionOption : long
				{
					// The operation should complete after reading the entire response including the content.
					ResponseContentRead,

					// The operation should complete as soon as a response is available and headers are read. The content is not read yet. 
					ResponseHeadersRead,
				};
			}
		}
	}
}
#endif
