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
void Elysium::Communication::Service::Http::HttpMessageParser::ParseResponseMessageHeader(const HttpClient * Client, 
	const Elysium::Core::String * CompleteResponseHeader, HttpResponseMessage * Response)
{
	size_t LineNumber = 0;
	size_t IndexOfLineEnd = 0;
	size_t TotalIndexOfLineEnd = 0;
	size_t LineLength = 0;

	Elysium::Core::StringView ResponseHeaderView = CompleteResponseHeader;
	Elysium::Core::Collections::Generic::List<Elysium::Core::StringView> LineViews;
	ResponseHeaderView.Split(L"\r\n", &LineViews);

	// parse the first line
	Elysium::Core::Version HttpVersion = Elysium::Core::Version::Parse(&Elysium::Core::StringView(&LineViews[0][5], 3));
	size_t LengthOfHttpStatusCode = LineViews[0].IndexOf(L' ', 9);
	Elysium::Core::StringView HttpStatusCodeView = Elysium::Core::StringView(&LineViews[0][9], LengthOfHttpStatusCode);
	size_t IndexOfHttpStatusMessage = 10 + LengthOfHttpStatusCode;
	Elysium::Core::StringView HttpStatusMessageView = Elysium::Core::StringView(&LineViews[0][IndexOfHttpStatusMessage], LineViews[0].IndexOf(L"\r\n", IndexOfHttpStatusMessage));

	// parse the subsequent header lines
	size_t LineCount = LineViews.GetCount();
	size_t IndexOfKeyValueDelimiter = 0;
	size_t LengthOfValue = 0;
	Elysium::Core::StringView KeyView;
	Elysium::Core::StringView ValueView;
	for (size_t i = 1; i < LineCount; i++)
	{
		IndexOfKeyValueDelimiter = LineViews[i].IndexOf(L':');
		KeyView = Elysium::Core::StringView(&LineViews[i][0], IndexOfKeyValueDelimiter);
		LengthOfValue = LineViews[i].IndexOf(L"\r\n", IndexOfKeyValueDelimiter + 2);
		if (LengthOfValue == std::wstring::npos)
		{
			ValueView = Elysium::Core::StringView(&LineViews[i][IndexOfKeyValueDelimiter + 2]);
		}
		else
		{
			ValueView = Elysium::Core::StringView(&LineViews[i][IndexOfKeyValueDelimiter + 2], LengthOfValue);
		}

		Elysium::Core::String Bla = KeyView;
		Elysium::Core::String Blub = ValueView;
		int xy = 45;
	}

	int X = 45;
}

Elysium::Communication::Service::Http::HttpMessageParser::HttpMessageParser()
{
}
