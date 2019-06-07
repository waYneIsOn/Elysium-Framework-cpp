#include "PdfDocument.hpp"

#ifndef ELYSIUM_CORE_IO_FILESTREAM
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/FileStream.hpp"
#endif

using namespace Elysium::Core::IO;

Elysium::IO::PDF::PdfDocument::PdfDocument()
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
	Elysium::Core::byte T = 0x12;
	Target.Write(&T, 0, 1);
	// header
	// %PDF-1.3
	//Target.Write()
}
