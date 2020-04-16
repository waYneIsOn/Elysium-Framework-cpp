/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_IO_PDF_PDFPAGE
#define ELYSIUM_IO_PDF_PDFPAGE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_IO_PDF_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_IO_PDF_PDFPAGEROTATION
#include "PdfPageRotation.hpp"
#endif

#ifndef ELYSIUM_IO_PDF_PDFPAGEDIMENSIONS
#include "PdfPageDimensions.hpp"
#endif

namespace Elysium::IO::PDF
{
	class ELYSIUM_IO_PDF_API PdfPage final
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
#endif
