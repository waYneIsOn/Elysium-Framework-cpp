/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_IO_PDF_PDFDOCUMENT
#define ELYSIUM_IO_PDF_PDFDOCUMENT

#ifndef ELYSIUM_CORE_EXPORT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Export.hpp"
#endif

namespace Elysium
{
	namespace IO
	{
		namespace PDF
		{
			class EXPORT PdfDocument final
			{
			public:
				PdfDocument();
				~PdfDocument();

				bool GetIsPasswordProtected() const;
				unsigned int GetPageCount() const;

				//GetPage(const unsigned int Index);
				//Load(const Stream& Stream);
				//Load(const String& Uri/FileName);
				//Save(const String& Uri/FileName);
			private:
				bool _IsPasswordProtected;
				unsigned int _PageCount;
			};

		}
	}
}
#endif
