/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_DSV_DSVDOCUMENT
#define ELYSIUM_IO_DSV_DSVDOCUMENT

#ifndef ELYSIUM_IO_DSV_API
#include "API.hpp"
#endif

namespace Elysium
{
	namespace IO
	{
		namespace DSV
		{
			class ELYSIUM_IO_DSV_API DsvDocument final
			{
			public:
				DsvDocument();
				~DsvDocument();
			};
		}
	}
}
#endif