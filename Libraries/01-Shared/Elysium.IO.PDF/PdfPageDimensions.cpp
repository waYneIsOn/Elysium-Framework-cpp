#include "PdfPageDimensions.hpp"

Elysium::IO::PDF::PdfPageDimensions::PdfPageDimensions()
{
}
Elysium::IO::PDF::PdfPageDimensions::~PdfPageDimensions()
{
}

Elysium::Core::Math::Geometry::Rectangle Elysium::IO::PDF::PdfPageDimensions::GetArtBox() const
{
	return _ArtBox;
}
Elysium::Core::Math::Geometry::Rectangle Elysium::IO::PDF::PdfPageDimensions::GetBleedBox() const
{
	return _BleedBox;
}
Elysium::Core::Math::Geometry::Rectangle Elysium::IO::PDF::PdfPageDimensions::GetCropBox() const
{
	return _CropBox;
}
Elysium::Core::Math::Geometry::Rectangle Elysium::IO::PDF::PdfPageDimensions::GetMediaBox() const
{
	return _MediaBox;
}
Elysium::Core::Math::Geometry::Rectangle Elysium::IO::PDF::PdfPageDimensions::GetTrimBox() const
{
	return _TrimBox;
}
