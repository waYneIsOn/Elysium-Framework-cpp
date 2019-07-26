#include "HttpMessageParser.hpp"

#ifndef ELYSIUM_CORE_TEXT_STRINGBUILDER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/StringBuilder.hpp"
#endif

#ifndef _STRING_
#include <string>
#endif

Elysium::Communication::Service::Http::HttpMessageParser::~HttpMessageParser()
{
}

Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::ParseRequestMessage(HttpRequestMessage & Request)
{
	// prepare required variables
	Elysium::Core::Text::StringBuilder Builder = Elysium::Core::Text::StringBuilder(1024);
	const Elysium::Core::Uri& RequestUri = Request.GetRequestUri();
	const Elysium::Core::Version& Version = Request.GetVersion();

	// prepare the header
	Builder.Append(Request.GetMethod().GetMethod());
	Builder.Append(L" /");
	Builder.Append(RequestUri.GetPathAndQuery());
	Builder.Append(L" HTTP/");
	Builder.Append(std::to_wstring(Version.GetMajor()).c_str());
	Builder.Append(L".");
	Builder.Append(std::to_wstring(Version.GetMinor()).c_str());
	Builder.Append(L"\r\nHost: ");
	Builder.Append(RequestUri.GetHost());
	Builder.Append(L"\r\nUser-Agent: Elysium/0.1\r\n");
	if (Version.GetMajor() == 1 && Version.GetMinor() == 1)
	{
		Builder.Append(L"Connection: keep-alive\r\n");
	}

	// ToDo: remove these lines - they're just here for testing purposes
	Builder.Append(L"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n");
	Builder.Append(L"Accept-Language: de,en-US;q=0.7,en;q=0.3\r\n");
	//Builder.Append(L"Accept-Encoding: gzip, deflate\r\n");

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

	return Builder.ToString();
}

Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpMessageParser::ParseResponseMessageHeader(HttpRequestMessage& Request, const Elysium::Core::String & CompleteResponseHeader)
{
	HttpResponseMessage ResponseMessage(Request);

	size_t LineNumber = 0;
	size_t IndexOfLineEnd = 0;
	size_t TotalIndexOfLineEnd = 0;
	size_t LineLength = 0;

	Elysium::Core::StringView ResponseHeaderView = CompleteResponseHeader;
	Elysium::Core::Collections::Generic::List<Elysium::Core::StringView> LineViews;
	ResponseHeaderView.Split(L"\r\n", &LineViews);

	// parse the first line
	ResponseMessage._Version = Elysium::Core::Version::Parse(&Elysium::Core::StringView(&LineViews[0][5], 3));
	size_t LengthOfHttpStatusCode = LineViews[0].IndexOf(L' ', 9);
	ResponseMessage._StatusCode = static_cast<HttpStatusCode>(wcstoul(&Elysium::Core::StringView(&LineViews[0][9], LengthOfHttpStatusCode)[0], nullptr, 10));
	size_t IndexOfHttpStatusMessage = 10 + LengthOfHttpStatusCode;
	ResponseMessage._ReasonPhrase = Elysium::Core::StringView(&LineViews[0][IndexOfHttpStatusMessage], LineViews[0].IndexOf(L"\r\n", IndexOfHttpStatusMessage));

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

		// add the header
		ResponseMessage._Headers.Add(KeyView, ValueView);
	}

	return ResponseMessage;
}

Elysium::Communication::Service::Http::HttpMessageParser::HttpMessageParser()
{
}
