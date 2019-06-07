/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_DSV_DSVDOCUMENT
#define ELYSIUM_IO_DSV_DSVDOCUMENT

#ifndef ELYSIUM_CORE_EXPORT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Export.hpp"
#endif

namespace Elysium
{
	namespace IO
	{
		namespace DSV
		{
			class EXPORT DsvDocument final
			{
			public:
				DsvDocument();
				~DsvDocument();
			};
		}
	}
}
#endif
