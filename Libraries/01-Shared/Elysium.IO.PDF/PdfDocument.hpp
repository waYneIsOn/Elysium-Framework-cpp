/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_PDF_PDFDOCUMENT
#define ELYSIUM_IO_PDF_PDFDOCUMENT

#ifndef ELYSIUM_IO_PDF_EXPORT
#include "Export.hpp"
#endif

namespace Elysium
{
	namespace IO
	{
		namespace PDF
		{
			class EXPORT PdfDocument final
			{
			public:
				PdfDocument();
				~PdfDocument();
			};

		}
	}
}
#endif
