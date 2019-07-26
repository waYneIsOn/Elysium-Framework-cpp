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
		TEST_METHOD(GetUncompressedData)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(L"http://neverssl.com"));

			HttpRequestMessage Request(HttpMethod::Get(), Uri(L"http://dcbfhklnmstrwxvz.neverssl.com/online"));
			HttpResponseMessage Response = Client.Get(Request);

			HttpResponseMessage* x = &Response;

			Client.Disconnect();

			// check response
			Assert::IsTrue(Response.GetHeaders().Contains(L"Content-Length"));
		}
		TEST_METHOD(GetDeflatedData)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(L"http://neverssl.com"));

			HttpRequestMessage Request(HttpMethod::Get(), Uri(L"http://dcbfhklnmstrwxvz.neverssl.com/online"));
			Request.GetHeaders().Add(L"Accept-Encoding", L"gzip, deflate");
			HttpResponseMessage Response = Client.Get(Request);

			Client.Disconnect();

			MemoryStream ContentStream;
			Response.GetContent()->ReadAsStream(ContentStream);

			if (Response.GetHeaders().GetValues(L"Content-Encoding").Contains(L"gzip"))
			{
				GZipStream UncompressedContentStream = GZipStream(ContentStream, CompressionMode::Decompress);
				//ContentStream.CopyTo(UncompressedContentStream);
			}
			else
			{
				Assert::Fail();
			}

			// ToDo: assert with expected result
		}
	};
}