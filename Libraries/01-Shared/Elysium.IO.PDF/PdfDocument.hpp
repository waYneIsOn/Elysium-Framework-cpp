/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_PDF_PDFDOCUMENT
#define ELYSIUM_IO_PDF_PDFDOCUMENT

#ifndef ELYSIUM_IO_PDF_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_IO_PDF_PDFVERSION
#include "PdfVersion.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

#ifndef ELYSIUM_CORE_IO_STREAM
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/Stream.hpp"
#endif

namespace Elysium
{
	namespace IO
	{
		namespace PDF
		{
			// PDF
			// PDF/A
			// PDF/E
			// PDF/UA
			// PDF/VT
			// PDF/X
			class ELYSIUM_IO_PDF_API PdfDocument final
			{
			public:
				PdfDocument();
				~PdfDocument();

				// properties - getter
				PdfVersion GetVersion() const;






				//bool GetIsPasswordProtected() const;
				//unsigned int GetPageCount() const;

				//GetPage(const unsigned int Index);
				//Load(const Stream& Stream);
				//Load(const String& Uri/FileName);
				void Save(const Elysium::Core::String& Target);
				void Save(Elysium::Core::IO::Stream& Target);
			private:
				PdfVersion _Version = PdfVersion(PdfVersion::PDF_1_7);
				//bool _IsPasswordProtected;
				//unsigned int _PageCount;
			};
		}
	}
}
#endif
