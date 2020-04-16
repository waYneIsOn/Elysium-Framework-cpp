/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_IO_PDF_PDFVERSION
#define ELYSIUM_IO_PDF_PDFVERSION

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_IO_PDF_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

namespace Elysium::IO::PDF
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
#endif
