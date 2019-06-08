#include "PdfVersion.hpp"

using namespace Elysium::Core;

const Elysium::IO::PDF::PdfVersion Elysium::IO::PDF::PdfVersion::PDF_1_0 = Elysium::IO::PDF::PdfVersion(1, 0);
const Elysium::IO::PDF::PdfVersion Elysium::IO::PDF::PdfVersion::PDF_1_1 = Elysium::IO::PDF::PdfVersion(1, 1);
const Elysium::IO::PDF::PdfVersion Elysium::IO::PDF::PdfVersion::PDF_1_2 = Elysium::IO::PDF::PdfVersion(1, 2);
const Elysium::IO::PDF::PdfVersion Elysium::IO::PDF::PdfVersion::PDF_1_3 = Elysium::IO::PDF::PdfVersion(1, 3);
const Elysium::IO::PDF::PdfVersion Elysium::IO::PDF::PdfVersion::PDF_1_4 = Elysium::IO::PDF::PdfVersion(1, 4);
const Elysium::IO::PDF::PdfVersion Elysium::IO::PDF::PdfVersion::PDF_1_5 = Elysium::IO::PDF::PdfVersion(1, 5);
const Elysium::IO::PDF::PdfVersion Elysium::IO::PDF::PdfVersion::PDF_1_6 = Elysium::IO::PDF::PdfVersion(1, 6);
const Elysium::IO::PDF::PdfVersion Elysium::IO::PDF::PdfVersion::PDF_1_7 = Elysium::IO::PDF::PdfVersion(1, 7);
const Elysium::IO::PDF::PdfVersion Elysium::IO::PDF::PdfVersion::PDF_2_0 = Elysium::IO::PDF::PdfVersion(2, 0);

Elysium::IO::PDF::PdfVersion::PdfVersion(const unsigned int & Major, const unsigned int & Minor)
	: _Major(Major), _Minor(Minor)
{
}
Elysium::IO::PDF::PdfVersion::PdfVersion(const PdfVersion & Value)
	: _Major(Value._Major), _Minor(Value._Minor)
{
}
Elysium::IO::PDF::PdfVersion::~PdfVersion()
{
}

const unsigned int Elysium::IO::PDF::PdfVersion::GetMajor() const
{
	return _Major;
}
const unsigned int Elysium::IO::PDF::PdfVersion::GetMinor() const
{
	return _Minor;
}
