/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_PDF_PDFPAGEROTATION
#define ELYSIUM_IO_PDF_PDFPAGEROTATION

namespace Elysium
{
	namespace IO
	{
		namespace PDF
		{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
			enum class PdfPageRotation : long
#elif defined(__ANDROID__)
			enum class PdfPageRotation
#else
#error "undefined os"
#endif
			{
				Normal = 0,
				Rotate90 = 1,
				Rotate180 = 2,
				Rotate270 = 3
			};
		}
	}
}
#endif
