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

Elysium::Core::String Elysium::Communication::Service::Http::HttpMessageParser::ParseRequestMessage(HttpRequestMessage & Request)
{
	// prepare required variables
	Elysium::Core::Text::StringBuilder Builder = Elysium::Core::Text::StringBuilder(1024);
	const Elysium::Core::Uri& RequestUri = Request.GetRequestUri();
	const Elysium::Core::Version& Version = Request.GetVersion();
	const Headers::HttpRequestHeaders& RequestHeaders = Request.GetHeaders();

	// add the "standard-parts" of the http-request-header
	Builder.Append(Request.GetMethod().GetMethod());
	Builder.Append(u" /");
	Builder.Append(RequestUri.GetPathAndQuery());
	Builder.Append(u" HTTP/");
	Builder.Append(Elysium::Core::Convert::ToString(Version.GetMajor(), 10));
	Builder.Append(u".");
	Builder.Append(Elysium::Core::Convert::ToString(Version.GetMinor(), 10));
	Builder.Append(u"\r\nHost: ");
	Builder.Append(RequestUri.GetHost());
	Builder.Append(u"\r\nUser-Agent: Elysium/0.1\r\n");
	if (Version.GetMajor() == 1 && Version.GetMinor() == 1)
	{
		Builder.Append(u"Connection: keep-alive\r\n");
	}

	// add all default headers using the client
	// ToDo

	// add the authorization header values
	// ToDo

	// add all "generic" request messages
	// ToDo: as soon as IEnumerable and IEnumerator have been implemented in some way, this needs to be changed accordingly
	std::map<Elysium::Core::String, Elysium::Core::Collections::Template::List<Elysium::Core::String>> RequestHeadersMap = RequestHeaders.GetInternalHeaders();
	for (std::pair<Elysium::Core::String, Elysium::Core::Collections::Template::List<Elysium::Core::String>> RequestHeadersValue : RequestHeadersMap)
	{
		Builder.Append(RequestHeadersValue.first);
		Builder.Append(u": ");
		Builder.Append(RequestHeadersValue.second[0]);
		Builder.Append(u"\r\n");
	}
	
	// add a finale newline to end the header
	Builder.Append(u"\r\n");

	// add the content
	// ToDo
	/*
	if (Request._Content != nullptr)
	{

	}
	*/
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
	Elysium::Core::Collections::Template::List<Elysium::Core::StringView> LineViews;
	ResponseHeaderView.Split(u"\r\n", LineViews);

	// parse the first line
	ResponseMessage._Version = Elysium::Core::Version::Parse(Elysium::Core::StringView(&LineViews[0][5], 3));
	size_t LengthOfHttpStatusCode = LineViews[0].IndexOf(u' ', 9);
	ResponseMessage._StatusCode = static_cast<HttpStatusCode>(Elysium::Core::Convert::ToInt32(&Elysium::Core::StringView(&LineViews[0][9], LengthOfHttpStatusCode)[0], 10));
	size_t IndexOfHttpStatusMessage = 10 + LengthOfHttpStatusCode;
	ResponseMessage._ReasonPhrase = Elysium::Core::StringView(&LineViews[0][IndexOfHttpStatusMessage], LineViews[0].GetLength() - IndexOfHttpStatusMessage);

	// parse the subsequent header lines
	size_t LineCount = LineViews.GetCount();
	size_t IndexOfKeyValueDelimiter = 0;
	size_t LengthOfValue = 0;
	Elysium::Core::StringView KeyView;
	Elysium::Core::StringView ValueView;
	for (size_t i = 1; i < LineCount; i++)
	{
		IndexOfKeyValueDelimiter = LineViews[i].IndexOf(u':');
		KeyView = Elysium::Core::StringView(&LineViews[i][0], IndexOfKeyValueDelimiter);
		LengthOfValue = LineViews[i].GetLength() - IndexOfKeyValueDelimiter - 2;
		if (LengthOfValue == static_cast<size_t>(-1))
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
