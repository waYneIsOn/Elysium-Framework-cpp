#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.IO.PDF/PdfDocument.hpp"

using namespace Elysium::Core;
using namespace Elysium::IO::PDF;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIOPDF
{		
	TEST_CLASS(IO_PDF)
	{
	public:
		TEST_METHOD(SaveEmptyPdf)
		{
			PdfDocument EmptyDocument;
			EmptyDocument.Save(u"Empty.pdf");
		}
	};
}