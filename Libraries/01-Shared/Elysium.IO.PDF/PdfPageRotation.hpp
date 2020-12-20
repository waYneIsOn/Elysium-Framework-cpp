/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_IO_PDF_PDFPAGEROTATION
#define ELYSIUM_IO_PDF_PDFPAGEROTATION

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::IO::PDF
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class PdfPageRotation : Elysium::Core::uint32_t
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
#endif
