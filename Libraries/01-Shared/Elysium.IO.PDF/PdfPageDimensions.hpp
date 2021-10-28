/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_IO_PDF_PDFPAGEDIMENSIONS
#define ELYSIUM_IO_PDF_PDFPAGEDIMENSIONS

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_IO_PDF_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_CORE_MATH_GEOMETRY_RECTANGLESINGLE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Math/Rectangle.hpp"
#endif

namespace Elysium::IO::PDF
{
	class ELYSIUM_IO_PDF_API PdfPageDimensions final
	{
	public:
		PdfPageDimensions();
		~PdfPageDimensions();

		Elysium::Core::Math::Geometry::Rectangle GetArtBox() const;
		Elysium::Core::Math::Geometry::Rectangle GetBleedBox() const;
		Elysium::Core::Math::Geometry::Rectangle GetCropBox() const;
		Elysium::Core::Math::Geometry::Rectangle GetMediaBox() const;
		Elysium::Core::Math::Geometry::Rectangle GetTrimBox() const;
	private:
		Elysium::Core::Math::Geometry::Rectangle _ArtBox;
		Elysium::Core::Math::Geometry::Rectangle _BleedBox;
		Elysium::Core::Math::Geometry::Rectangle _CropBox;
		Elysium::Core::Math::Geometry::Rectangle _MediaBox;
		Elysium::Core::Math::Geometry::Rectangle _TrimBox;
	};
}
#endif
