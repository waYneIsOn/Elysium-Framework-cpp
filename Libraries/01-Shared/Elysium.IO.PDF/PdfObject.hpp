/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_PDF_PDFOBJECT
#define ELYSIUM_IO_PDF_PDFOBJECT

#ifndef ELYSIUM_IO_PDF_API
#include "API.hpp"
#endif

namespace Elysium
{
	namespace IO
	{
		namespace PDF
		{
			class ELYSIUM_IO_PDF_API PdfObject
			{
			public:
				virtual ~PdfObject() = 0;
			protected:
				PdfObject();
			};
		}
	}
}
#endif
