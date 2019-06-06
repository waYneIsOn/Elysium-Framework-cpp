/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_PDF_PDFPAGE
#define ELYSIUM_IO_PDF_PDFPAGE

#ifndef ELYSIUM_IO_PDF_EXPORT
#include "Export.hpp"
#endif

#ifndef ELYSIUM_IO_PDF_PDFPAGEROTATION
#include "PdfPageRotation.hpp"
#endif

#ifndef ELYSIUM_IO_PDF_PDFPAGEDIMENSIONS
#include "PdfPageDimensions.hpp"
#endif

namespace Elysium
{
	namespace IO
	{
		namespace PDF
		{
			class EXPORT PdfPage final
			{
			public:
				PdfPage();
				~PdfPage();

				PdfPageDimensions GetDimensions() const;
				unsigned int GetIndex() const;
				float GetPreferredZoom() const;
				PdfPageRotation GetRotation() const;
			private:
				PdfPageDimensions _Dimensions;
				unsigned int _Index;
				float _PreferredZoom;
				PdfPageRotation _Rotation;
				//Size _Size;
			};
		}
	}
}
#endif
