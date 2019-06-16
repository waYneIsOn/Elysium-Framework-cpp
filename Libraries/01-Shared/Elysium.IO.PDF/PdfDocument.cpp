#include "PdfDocument.hpp"

#ifndef ELYSIUM_CORE_IO_FILESTREAM
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/FileStream.hpp"
#endif

#ifndef ELYSIUM_CORE_TEXT_ENCODING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"
#endif

using namespace Elysium::Core;
using namespace Elysium::Core::IO;

Elysium::IO::PDF::PdfDocument::PdfDocument()
	: PdfObject(),
	_Version(PdfVersion(PdfVersion::PDF_1_7))
{
}
Elysium::IO::PDF::PdfDocument::PdfDocument(const PdfVersion & Version)
	: PdfObject(), 
	_Version(Version)
{
}
Elysium::IO::PDF::PdfDocument::~PdfDocument()
{
}
Elysium::IO::PDF::PdfVersion Elysium::IO::PDF::PdfDocument::GetVersion() const
{
	return _Version;
}

void Elysium::IO::PDF::PdfDocument::Save(const Elysium::Core::String & Target)
{
	FileStream TargetStream = FileStream(Target, FileMode::Create, FileAccess::Write, FileShare::None);
	Save(TargetStream);
}
void Elysium::IO::PDF::PdfDocument::Save(Elysium::Core::IO::Stream & Target)
{
	const Elysium::Core::Text::Encoding* DefaultEncoding = Elysium::Core::Text::Encoding::Default();
	const Elysium::Core::Text::Encoding* ASCIIEncoding = Elysium::Core::Text::Encoding::ASCII();

	// magic number
	static byte MagicNumber[] = { 0x25, 0x50, 0x44, 0x46, 0x2D };	// %PDF-
	Target.Write(&MagicNumber[0], 5);

	// pdf version
	String VersionString = L"1.7\r\n\r\n";
	Elysium::Core::Collections::Generic::List<byte> ConvertedBytes;
	ASCIIEncoding->GetBytes(&VersionString, 0, VersionString.GetLength(), &ConvertedBytes);
	Target.Write(&ConvertedBytes[0], ConvertedBytes.GetCount());

	// catalog????
	String InitialCatalog = L"1 0 obj\r\n<<\r\n/Type /Catalog\r\n/Outlines 2 0 R\r\n/Pages 3 0 R\r\n>>\r\nendobj\r\n\r\n";
	ConvertedBytes.Clear();
	ASCIIEncoding->GetBytes(&InitialCatalog, 0, InitialCatalog.GetLength(), &ConvertedBytes);
	Target.Write(&ConvertedBytes[0], ConvertedBytes.GetCount());

	// Outlines
	String Outlines = L"2 0 obj\r\n<<\r\n/Type /Outlines\r\n/Count 0\r\n>>\r\nendobj\r\n\r\n";
	ConvertedBytes.Clear();
	ASCIIEncoding->GetBytes(&Outlines, 0, Outlines.GetLength(), &ConvertedBytes);
	Target.Write(&ConvertedBytes[0], ConvertedBytes.GetCount());

	// Pages
	String Pages = L"3 0 obj\r\n<<\r\n/Type /Pages\r\n/Count 1\r\n/Kids [ 4 0 R ]\r\n>>\r\nendobj\r\n\r\n";
	ConvertedBytes.Clear();
	ASCIIEncoding->GetBytes(&Pages, 0, Pages.GetLength(), &ConvertedBytes);
	Target.Write(&ConvertedBytes[0], ConvertedBytes.GetCount());

	// Page 1
	String Page1 = L"4 0 obj\r\n<<\r\n/Type /Page\r\n";

	// trailer
	String Trailer = L"trailer\r\n<<\r\n/Size 6\r\n/Root 1 0 R\r\n/Info 5 0 R\r\n>>\r\n\r\n";
	ConvertedBytes.Clear();
	ASCIIEncoding->GetBytes(&Trailer, 0, Trailer.GetLength(), &ConvertedBytes);
	Target.Write(&ConvertedBytes[0], ConvertedBytes.GetCount());

	// end of file
	String EndOfFile = L"startxref\r\n1337\r\n%%EOF\r\n";
	ConvertedBytes.Clear();
	ASCIIEncoding->GetBytes(&EndOfFile, 0, EndOfFile.GetLength(), &ConvertedBytes);
	Target.Write(&ConvertedBytes[0], ConvertedBytes.GetCount());

	int x = 354;
}
