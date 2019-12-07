#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.HTTP/HttpClient.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.HTTP/StringContent.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/FileStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/MemoryStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/GZipStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::IO;
using namespace Elysium::Core::IO::Compression;
using namespace Elysium::Core::Text;
using namespace Elysium::Communication::Service::Http;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_HttpClient)
	{
	public:
		TEST_METHOD(HttpDelete)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response = Client.Delete(u"/delete");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(HttpGet)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response1 = Client.Get(u"/get", HttpCompletionOption::ResponseHeadersRead);
			HttpResponseMessage Response2 = Client.Get(u"/get", Response1);
			HttpResponseMessage Response3 = Client.Get(u"/get");
			HttpResponseMessage Response4 = Client.Get(u"/get");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response1.GetStatusCode());
			Assert::IsTrue(Response1.GetHeaders().Contains(u"Content-Length"));
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response2.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response3.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response4.GetStatusCode());
		}
		TEST_METHOD(HttpGetGzip)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response = Client.Get(u"/gzip");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
			if (!Response.GetHeaders().GetValues(u"Content-Encoding").Contains(u"gzip"))
			{
				Assert::Fail();
			}
			/*
			MemoryStream ContentStream;
			Response.GetContent()->ReadAsStream(ContentStream);
			GZipStream UncompressedContentStream = GZipStream(ContentStream, CompressionMode::Decompress);
			*/
		}
		TEST_METHOD(HttpOptions)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response = Client.Options(u"/get");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(HttpPatch)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response = Client.Patch(u"/patch");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(HttpPost)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response = Client.Post(u"/post");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(HttpPut)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response = Client.Put(u"/put");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}

		TEST_METHOD(HttpBasicAuthentication)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));

			// send a request without authorization-headers
			HttpResponseMessage UnauthorizedResponse = Client.Get(u"/basic-auth/SomeUser/SomePassword");

			// add authorization-headers and send the same request again
			String AuthInfo = u"SomeUser:SomePassword";
			String Base64AuthInfo = Convert::ToBase64String(Encoding::ASCII().GetBytes(AuthInfo, 0, AuthInfo.GetLength()));
			StringBuilder AuthBuilder = StringBuilder(6 + Base64AuthInfo.GetLength());
			AuthBuilder.Append(String(u"Basic "));
			AuthBuilder.Append(Base64AuthInfo);
			Client.GetDefaultRequestHeaders().SetAuthorization(Headers::AuthenticationHeaderValue(u"Authorization", AuthBuilder.ToString()));
			HttpResponseMessage AuthorizedResponse = Client.Get(u"/basic-auth/SomeUser/SomePassword");

			Client.Disconnect();

			// check responses
			Assert::AreEqual((uint32_t)HttpStatusCode::Unauthorized, (uint32_t)UnauthorizedResponse.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)AuthorizedResponse.GetStatusCode());
		}
		TEST_METHOD(HttpBasicAuthenticationHidden)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));

			// send a request without authorization-headers
			HttpResponseMessage UnauthorizedResponse = Client.Get(u"/hidden-basic-auth/SomeUser/SomePassword");

			// add authorization-headers and send the same request again
			String AuthInfo = u"SomeUser:SomePassword";
			String Base64AuthInfo = Convert::ToBase64String(Encoding::ASCII().GetBytes(AuthInfo, 0, AuthInfo.GetLength()));
			StringBuilder AuthBuilder = StringBuilder(6 + Base64AuthInfo.GetLength());
			AuthBuilder.Append(String(u"Basic "));
			AuthBuilder.Append(Base64AuthInfo);
			Client.GetDefaultRequestHeaders().SetAuthorization(Headers::AuthenticationHeaderValue(u"Authorization", AuthBuilder.ToString()));
			HttpResponseMessage AuthorizedResponse = Client.Get(u"/hidden-basic-auth/SomeUser/SomePassword");

			Client.Disconnect();

			// check responses
			Assert::AreEqual((uint32_t)HttpStatusCode::NotFound, (uint32_t)UnauthorizedResponse.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)AuthorizedResponse.GetStatusCode());
		}
	};
}