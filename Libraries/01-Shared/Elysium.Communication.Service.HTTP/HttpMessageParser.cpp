#include "HttpMessageParser.hpp"

#ifndef ELYSIUM_CORE_TEXT_STRINGBUILDER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/StringBuilder.hpp"
#endif

#ifndef ELYSIUM_CORE_CONVERT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#endif

Elysium::Communication::Service::Http::HttpMessageParser::~HttpMessageParser()
{
}

Elysium::Core::Utf8String Elysium::Communication::Service::Http::HttpMessageParser::ParseRequestMessage(HttpRequestMessage & Request)
{
	// prepare required variables
	Elysium::Core::Text::StringBuilder Builder = Elysium::Core::Text::StringBuilder(1024);
	const Elysium::Core::Uri& RequestUri = Request.GetRequestUri();
	const Elysium::Core::Version& Version = Request.GetVersion();
	const Headers::HttpRequestHeaders& RequestHeaders = Request.GetHeaders();
	const HttpContent* Content = Request.GetContent();

	// add the "standard-parts" of the http-request-header
	Builder.Append(Request.GetMethod().GetMethod());
	Builder.Append(u8" /");
	Builder.Append(RequestUri.GetPathAndQuery().ToString());
	Builder.Append(u8" HTTP/");
	Builder.Append(Elysium::Core::Convert::ToString(Version.GetMajor(), 10));
	Builder.Append(u8".");
	Builder.Append(Elysium::Core::Convert::ToString(Version.GetMinor(), 10));
	Builder.Append(u8"\r\nHost: ");
	Builder.Append(RequestUri.GetHost().ToString());
	Builder.Append(u8"\r\nUser-Agent: Elysium/0.1\r\n");

	// add the authorization header values
	const Headers::AuthenticationHeaderValue& AuthorizationHeader = RequestHeaders.GetAuthorization();
	const Elysium::Core::Utf8String& AuthorizationScheme = AuthorizationHeader.GetScheme();
	if (AuthorizationScheme.GetLength() > 0)
	{
		Builder.Append(u8"Authorization: ");
		Builder.Append(AuthorizationScheme);
		Builder.Append(u8" ");
		Builder.Append(AuthorizationHeader.GetParameter());
		Builder.Append(u8"\r\n");
	}
	
	// add all "generic" request headers
	std::map<Elysium::Core::Utf8String, Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>> RequestHeadersMap = RequestHeaders.GetInternalHeaders();
	for (std::pair<Elysium::Core::Utf8String, Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>> RequestHeadersValue : RequestHeadersMap)
	{
		Builder.Append(RequestHeadersValue.first);
		Builder.Append(u8": ");
		Builder.Append(RequestHeadersValue.second[0]);
		Builder.Append(u8"\r\n");
	}

	// make sure the connection is persistent if required
	static const Elysium::Core::Version Http10 = Elysium::Core::Version(1, 0);
	if (Version == Http10)
	{	// ToDo: check headers before adding
		Builder.Append(u8"Connection: keep-alive\r\n");
	}

	// write content headers
	if (Content != nullptr)
	{
		std::map<Elysium::Core::Utf8String, Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>> ContentHeaderMap = Content->GetHeaders().GetInternalHeaders();
		for (std::pair<Elysium::Core::Utf8String, Elysium::Core::Collections::Template::List<Elysium::Core::Utf8String>> ContentHeaderValue : ContentHeaderMap)
		{
			Builder.Append(ContentHeaderValue.first);
			Builder.Append(u8": ");
			Builder.Append(ContentHeaderValue.second[0]);
			Builder.Append(u8"\r\n");
		}
	}

	// add a final newline to end the header
	Builder.Append(u8"\r\n");
	
	// add the content
	if (Content != nullptr)
	{	// ToDo: write content in a correct fashion
		Builder.Append(Content->ReadAsString());
	}
	
	return Builder.ToString();
}

Elysium::Communication::Service::Http::HttpResponseMessage Elysium::Communication::Service::Http::HttpMessageParser::ParseResponseMessageHeader(HttpRequestMessage& Request, const Elysium::Core::Utf8String & CompleteResponseHeader)
{
	HttpResponseMessage ResponseMessage(Request);

	size_t LineNumber = 0;
	size_t IndexOfLineEnd = 0;
	size_t TotalIndexOfLineEnd = 0;
	size_t LineLength = 0;

	Elysium::Core::Utf8StringView ResponseHeaderView = Elysium::Core::Utf8StringView(&CompleteResponseHeader[0], CompleteResponseHeader.GetLength());
	Elysium::Core::Template::Container::Vector<Elysium::Core::Utf8StringView> LineViews= ResponseHeaderView.Split(u8"\r\n");

	// parse the first line
	ResponseMessage._Version = Elysium::Core::Version::Parse(Elysium::Core::Utf8StringView(&LineViews[0][5], 3));
	size_t LengthOfHttpStatusCode = LineViews[0].IndexOf(' ', 9);
	ResponseMessage._StatusCode = static_cast<HttpStatusCode>(Elysium::Core::Convert::ToInt32(Elysium::Core::Utf8StringView(&LineViews[0][9], LengthOfHttpStatusCode), 10));
	size_t IndexOfHttpStatusMessage = 10 + LengthOfHttpStatusCode;
	ResponseMessage._ReasonPhrase = Elysium::Core::Utf8String(&LineViews[0][IndexOfHttpStatusMessage], LineViews[0].GetLength() - IndexOfHttpStatusMessage);

	// parse the subsequent header lines
	size_t LineCount = LineViews.GetLength();
	size_t IndexOfKeyValueDelimiter = 0;
	size_t LengthOfValue = 0;
	Elysium::Core::Utf8StringView KeyView;
	Elysium::Core::Utf8StringView ValueView;
	for (size_t i = 1; i < LineCount; i++)
	{
		IndexOfKeyValueDelimiter = LineViews[i].IndexOf(u8':');
		KeyView = Elysium::Core::Utf8StringView(&LineViews[i][0], IndexOfKeyValueDelimiter);
		LengthOfValue = LineViews[i].GetLength() - IndexOfKeyValueDelimiter - 2;
		if (LengthOfValue == static_cast<size_t>(-1))
		{
			ValueView = Elysium::Core::Utf8StringView(&LineViews[i][IndexOfKeyValueDelimiter + 2]);
		}
		else
		{
			ValueView = Elysium::Core::Utf8StringView(&LineViews[i][IndexOfKeyValueDelimiter + 2], LengthOfValue);
		}

		// add the header
		ResponseMessage._Headers.Add(KeyView, ValueView);
	}

	return ResponseMessage;
}

Elysium::Communication::Service::Http::HttpMessageParser::HttpMessageParser()
{ }
