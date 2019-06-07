/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_PDF_PDFPAGEDIMENSIONS
#define ELYSIUM_IO_PDF_PDFPAGEDIMENSIONS

#ifndef ELYSIUM_IO_PDF_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_CORE_MATH_GEOMETRY_RECTANGLESINGLE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Math/RectangleSingle.hpp"
#endif

namespace Elysium
{
	namespace IO
	{
		namespace PDF
		{
			class ELYSIUM_IO_PDF_API PdfPageDimensions final
			{
			public:
				PdfPageDimensions();
				~PdfPageDimensions();

				Elysium::Core::Math::Geometry::RectangleSingle GetArtBox() const;
				Elysium::Core::Math::Geometry::RectangleSingle GetBleedBox() const;
				Elysium::Core::Math::Geometry::RectangleSingle GetCropBox() const;
				Elysium::Core::Math::Geometry::RectangleSingle GetMediaBox() const;
				Elysium::Core::Math::Geometry::RectangleSingle GetTrimBox() const;
			private:
				Elysium::Core::Math::Geometry::RectangleSingle _ArtBox;
				Elysium::Core::Math::Geometry::RectangleSingle _BleedBox;
				Elysium::Core::Math::Geometry::RectangleSingle _CropBox;
				Elysium::Core::Math::Geometry::RectangleSingle _MediaBox;
				Elysium::Core::Math::Geometry::RectangleSingle _TrimBox;
			};
		}
	}
}
#endif
