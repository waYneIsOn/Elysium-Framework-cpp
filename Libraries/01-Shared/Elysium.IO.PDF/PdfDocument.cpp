#include "PdfDocument.hpp"

Elysium::IO::PDF::PdfDocument::PdfDocument()
{
}
Elysium::IO::PDF::PdfDocument::~PdfDocument()
{
}

bool Elysium::IO::PDF::PdfDocument::GetIsPasswordProtected() const
{
	return _IsPasswordProtected;
}
unsigned int Elysium::IO::PDF::PdfDocument::GetPageCount() const
{
	return _PageCount;
}
