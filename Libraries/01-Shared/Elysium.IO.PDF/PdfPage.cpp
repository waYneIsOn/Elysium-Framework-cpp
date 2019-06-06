#include "PdfPage.hpp"

Elysium::IO::PDF::PdfPage::PdfPage()
{
}
Elysium::IO::PDF::PdfPage::~PdfPage()
{
}

Elysium::IO::PDF::PdfPageDimensions Elysium::IO::PDF::PdfPage::GetDimensions() const
{
	return _Dimensions;
}

unsigned int Elysium::IO::PDF::PdfPage::GetIndex() const
{
	return _Index;
}
float Elysium::IO::PDF::PdfPage::GetPreferredZoom() const
{
	return _PreferredZoom;
}
Elysium::IO::PDF::PdfPageRotation Elysium::IO::PDF::PdfPage::GetRotation() const
{
	return _Rotation;
}
