/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_PDF_PDFVERSION
#define ELYSIUM_IO_PDF_PDFVERSION

#ifndef ELYSIUM_IO_PDF_API
#include "API.hpp"
#endif

namespace Elysium
{
	namespace IO
	{
		namespace PDF
		{
			class ELYSIUM_IO_PDF_API PdfVersion final
			{
			public:
				PdfVersion(const unsigned int& Major, const unsigned int& Minor);
				PdfVersion(const PdfVersion& Value);
				~PdfVersion();

				const unsigned int GetMajor() const;
				const unsigned int GetMinor() const;

				static const PdfVersion PDF_1_0;
				static const PdfVersion PDF_1_1;
				static const PdfVersion PDF_1_2;
				static const PdfVersion PDF_1_3;
				static const PdfVersion PDF_1_4;
				static const PdfVersion PDF_1_5;
				static const PdfVersion PDF_1_6;
				static const PdfVersion PDF_1_7;
				static const PdfVersion PDF_2_0;
			private:
				unsigned int _Major;
				unsigned int _Minor;
			};
		}
	}
}
#endif
