/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_IO_DSV_DSVDOCUMENT
#define ELYSIUM_IO_DSV_DSVDOCUMENT

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_IO_DSV_API
#include "API.hpp"
#endif

namespace Elysium::IO::DSV
{
	class ELYSIUM_IO_DSV_API DsvDocument final
	{
	public:
		DsvDocument();
		~DsvDocument();
	};
}
#endif
