#include "HttpMessageParser.hpp"

#ifndef ELYSIUM_CORE_TEXT_STRINGBUILDER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/StringBuilder.hpp"
#endif

#ifndef _STRING_
#include <string>
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

void Elysium::Communication::Service::Http::HttpMessageParser::ParseRequestMessage(const HttpClient * Client, const HttpRequestMessage * Request, Elysium::Core::String * Output)
{
	// prepare required variables
	Elysium::Core::Text::StringBuilder Builder = Elysium::Core::Text::StringBuilder(1024);
	const Elysium::Core::Uri& RequestUri = Request->GetRequestUri();
	const Elysium::Core::Version& Version = Request->GetVersion();

	// prepare the header
	Builder.Append(Request->GetMethod().GetMethod());
	Builder.Append(L" /");
	Builder.Append(RequestUri.GetPathAndQuery());
	Builder.Append(L" HTTP/");
	Builder.Append(std::to_wstring(Version.GetMajor()).c_str());
	Builder.Append(L".");
	Builder.Append(std::to_wstring(Version.GetMinor()).c_str());
	Builder.Append(L"\r\nUser-Agent: Elysium/0.1\r\nHost: ");
	Builder.Append(RequestUri.GetHost());
	Builder.Append(L"\r\n");

	// add all default headers using the client
	// ToDo

	// add the authorization header values
	// ToDo

	// add all "generic" request messages
	// ToDo

	// add a finale newline to end the header
	Builder.Append(L"\r\n");

	// add the content
	// ToDo

	Builder.ToString(Output);
}
void Elysium::Communication::Service::Http::HttpMessageParser::ParseResponseMessageHeader(const HttpClient * Client, const Elysium::Core::String * CompleteResponseHeader, HttpResponseMessage * Request)
{
	size_t LineNumber = 0;
	size_t IndexOfLineEnd = 0;
	size_t TotalIndexOfLineEnd = 0;
	size_t LineLength = 0;

	// parse the first line


	// just for testing
	/*
	while(true)
	{
		IndexOfLineEnd = CompleteResponseHeader->IndexOf(L"\r\n", TotalIndexOfLineEnd);
		LineLength = IndexOfLineEnd;
		if (IndexOfLineEnd == std::wstring::npos)
		{
			LineLength = CompleteResponseHeader->GetLength() - TotalIndexOfLineEnd;
		}

		Elysium::Core::StringView CurrenLineView = Elysium::Core::StringView(CompleteResponseHeader, TotalIndexOfLineEnd, LineLength);
		//Elysium::Core::String CurrentLine = CurrenLineView;

		if (IndexOfLineEnd == std::wstring::npos)
		{
			break;
		}
		TotalIndexOfLineEnd += IndexOfLineEnd + 2;
	}
	*/
}

Elysium::Communication::Service::Http::HttpMessageParser::HttpMessageParser()
{
}
