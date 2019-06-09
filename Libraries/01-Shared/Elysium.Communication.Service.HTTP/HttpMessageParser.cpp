#include "HttpMessageParser.hpp"

#ifndef ELYSIUM_CORE_TEXT_STRINGBUILDER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/StringBuilder.hpp"
#endif

const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::ENDOFMESSAGEHEADER = L"\r\n\r\n";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::ENDOFCHUNKEDCONTENTBEFOREFOOTER = L"\r\n0\r\n";

const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_APPLICATION = L"application/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_AUDIO = L"audio/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_CHEMICAL = L"chemical/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_DRAWING = L"drawing/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_IMAGE = L"image/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_MESSAGE = L"message/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_MODEL = L"model/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_MULTIPART = L"multipart/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_TEXT = L"text/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_VIDEO = L"video/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_WORKBOOK = L"workbook/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_XCONFERENCE = L"x-conference/";
const Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::MIMETYPE_XWORLD = L"x-world/";

Elysium::Communication::Service::Http::HttpMessageParser::~HttpMessageParser()
{
}

void Elysium::Communication::Service::Http::HttpMessageParser::ParseRequestMessage(const HttpClient & Client, const HttpRequestMessage & RequestMessage, Elysium::Core::String * Output)
{
	Elysium::Core::Text::StringBuilder Builder = Elysium::Core::Text::StringBuilder(1024);

	// prepare the header
	Builder.Append(RequestMessage.GetMethod().GetMethod());
	Builder.Append(L" ");
	//Builder.Append(RequestMessage.GetRequestUri().GetPathAndQuery());
	Builder.Append(L" HTTP/");
	//Builder.Append(RequestMessage.GetVersion());
	Builder.Append(L"\r\n");

	Builder.Append(L"; ; ; ");
	Builder.SetLength(Builder.GetLength() - 2);

	/*
	Elysium::Core::String Test1 = L"first";
	Elysium::Core::String Test2 = L"second";
	Elysium::Core::String Test3 = L"third";
	*-/
	Elysium::Core::String Test1 = L"aSDFASDFSD";
	Elysium::Core::String Test2 = L"dsefgdfsg";
	Elysium::Core::String Test3 = L"gchj6578788i";

	Builder.Append(Test1);
	Builder.Append(Test2);
	Builder.Append(Test3);
	*/
	Elysium::Core::String Blub;
	Builder.ToString(&Blub);
	
	int x = 456;
}

Elysium::Communication::Service::Http::HttpMessageParser::HttpMessageParser()
{
}
