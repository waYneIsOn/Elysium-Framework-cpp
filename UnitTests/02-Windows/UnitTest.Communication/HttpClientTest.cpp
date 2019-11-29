#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.HTTP/HttpClient.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.HTTP/StringContent.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/FileStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/MemoryStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/GZipStream.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::IO;
using namespace Elysium::Core::IO::Compression;
using namespace Elysium::Communication::Service::Http;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_HttpClient)
	{
	public:
		TEST_METHOD(GetDeflatedData)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://neverssl.com"));

			HttpRequestMessage Request(HttpMethod::Get(), Uri(u"http://dcbfhklnmstrwxvz.neverssl.com/online"));
			Request.GetHeaders().Add(u"Accept", u"text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
			Request.GetHeaders().Add(u"Accept-Language", u"de,en-US;q=0.7,en;q=0.3");
			Request.GetHeaders().Add(u"Accept-Encoding", u"gzip, deflate");
			HttpResponseMessage Response = Client.Get(Request);

			Client.Disconnect();

			// check response
			if (!Response.GetHeaders().GetValues(u"Content-Encoding").Contains(u"gzip"))
			{
				Assert::Fail();
			}

			MemoryStream ContentStream;
			Response.GetContent()->ReadAsStream(ContentStream);
			GZipStream UncompressedContentStream = GZipStream(ContentStream, CompressionMode::Decompress);

			// ToDo: unzip the content
		}
		TEST_METHOD(GetUncompressedData)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://neverssl.com"));

			HttpRequestMessage Request(HttpMethod::Get(), Uri(u"http://dcbfhklnmstrwxvz.neverssl.com/online"));
			Request.GetHeaders().Add(u"Accept", u"text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
			Request.GetHeaders().Add(u"Accept-Language", u"de,en-US;q=0.7,en;q=0.3");
			HttpResponseMessage Response = Client.Get(Request);

			Client.Disconnect();

			// check response
			Assert::IsTrue(Response.GetHeaders().Contains(u"Content-Length"));
		}
	};
}