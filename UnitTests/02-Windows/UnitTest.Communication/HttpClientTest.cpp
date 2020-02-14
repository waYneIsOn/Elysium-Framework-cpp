#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.HTTP/HttpClient.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.HTTP/StringContent.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/FileStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/MemoryStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/GZipStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Security/MD5.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::IO;
using namespace Elysium::Core::IO::Compression;
using namespace Elysium::Core::Security::Cryptography;
using namespace Elysium::Core::Text;
using namespace Elysium::Communication::Service::Http;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_HttpClient)
	{
	public:
		TEST_METHOD(Delete)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response = Client.Delete(u"/delete");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(Get)
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
		TEST_METHOD(GetBrotli)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response = Client.Get(u"/brotli");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
			if (!Response.GetHeaders().GetValues(u"Content-Encoding").Contains(u"br"))
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(GetGzip)
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
		TEST_METHOD(GetDeflate)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response = Client.Get(u"/deflate");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
			if (!Response.GetHeaders().GetValues(u"Content-Encoding").Contains(u"deflate"))
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(Options)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));
			HttpResponseMessage Response = Client.Options(u"/get");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(Patch)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));

			StringContent Content = StringContent(String(u"<html><head></head><body>bla</body></html>"));

			HttpResponseMessage Response = Client.Patch(u"/patch", Content);
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(Post)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));

			StringContent Content = StringContent(String(u"<html><head></head><body>bla</body></html>"));

			HttpResponseMessage Response = Client.Post(u"/post", Content);
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(Put)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));

			StringContent Content = StringContent(String(u"<html><head></head><body>bla</body></html>"));

			HttpResponseMessage Response = Client.Put(u"/put", Content);
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}

		TEST_METHOD(AuthenticationBasic)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));

			// send a request without authorization-headers
			HttpResponseMessage UnauthorizedResponse = Client.Get(u"/basic-auth/SomeUser/SomePassword");

			// add authorization-headers and send the same request again
			String AuthInfo = u"SomeUser:SomePassword";
			String Base64AuthInfo = Convert::ToBase64String(Encoding::ASCII().GetBytes(AuthInfo, 0, AuthInfo.GetLength()));
			Client.GetDefaultRequestHeaders().SetAuthorization(Headers::AuthenticationHeaderValue(u"Basic", Base64AuthInfo));
			HttpResponseMessage AuthorizedResponse = Client.Get(u"/basic-auth/SomeUser/SomePassword");

			Client.Disconnect();

			// check responses
			Assert::AreEqual((uint32_t)HttpStatusCode::Unauthorized, (uint32_t)UnauthorizedResponse.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)AuthorizedResponse.GetStatusCode());
		}
		TEST_METHOD(AuthenticationBasicHidden)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));

			// send a request without authorization-headers
			HttpResponseMessage UnauthorizedResponse = Client.Get(u"/hidden-basic-auth/SomeUser/SomePassword");

			// add authorization-headers and send the same request again
			String AuthInfo = u"SomeUser:SomePassword";
			String Base64AuthInfo = Convert::ToBase64String(Encoding::ASCII().GetBytes(AuthInfo, 0, AuthInfo.GetLength()));
			Client.GetDefaultRequestHeaders().SetAuthorization(Headers::AuthenticationHeaderValue(u"Basic", Base64AuthInfo));
			HttpResponseMessage AuthorizedResponse = Client.Get(u"/hidden-basic-auth/SomeUser/SomePassword");

			Client.Disconnect();

			// check responses
			Assert::AreEqual((uint32_t)HttpStatusCode::NotFound, (uint32_t)UnauthorizedResponse.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)AuthorizedResponse.GetStatusCode());
		}

		TEST_METHOD(AuthenticationBearer)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));

			// send a request without authorization-headers
			HttpResponseMessage UnauthorizedResponse = Client.Get(u"/bearer");

			// add authorization-headers and send the same request again
			Client.GetDefaultRequestHeaders().SetAuthorization(Headers::AuthenticationHeaderValue(u"Bearer", u"SomeToken"));
			HttpResponseMessage AuthorizedResponse = Client.Get(u"/bearer");

			Client.Disconnect();

			// check responses
			Assert::AreEqual((uint32_t)HttpStatusCode::Unauthorized, (uint32_t)UnauthorizedResponse.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)AuthorizedResponse.GetStatusCode());
		}

		TEST_METHOD(AuthenticationDigest)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(u"http://httpbin.org"));

			// send a request without authorization-headers
			HttpResponseMessage UnauthorizedResponse = Client.Get(u"/digest-auth/auth/SomeUser/SomePassword");

			// add authorization-headers and send the same request again
			MD5 MD5HashAlgorithm = MD5();
			//Array<byte> HashValue = MD5HashAlgorithm.ComputeHash()
			// Digest username="SomeUser", realm="me@kennethreitz.com", nonce="1046d954b07d4532474f285cea83c6e9", uri="/digest-auth/auth/SomeUser/SomePassword", algorithm=MD5, response="fa21c135d9de01911ed0939e8281153e", opaque="ee0fc51b95bc7c966858cd509d14d6b8", qop=auth, nc=00000001, cnonce="ca4c9227a0d10c35"
			Client.GetDefaultRequestHeaders().SetAuthorization(Headers::AuthenticationHeaderValue(u"Digest", u"username\"...\", realm=\"...\", nonce=\"...\", uri=\"...\", algorithm=\"...\", response=\"...\", opaque=\"...\", qop=\"...\", nc=\"...\", cnonce=\"...\" "));
			HttpResponseMessage AuthorizedResponse = Client.Get(u"/digest-auth/auth/SomeUser/SomePassword");

			Client.Disconnect();

			// check responses
			Assert::AreEqual((uint32_t)HttpStatusCode::Unauthorized, (uint32_t)UnauthorizedResponse.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)AuthorizedResponse.GetStatusCode());
		}
	};
}