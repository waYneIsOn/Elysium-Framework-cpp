#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.HTTP/HttpClient.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.HTTP/StringContent.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/FileStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/MemoryStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/GZipStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Security.Cryptography.Algorithms/MD5.hpp"
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
			Client.Connect(Uri("http://httpbin.org"));
			HttpResponseMessage Response = Client.Delete("/delete");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(Get)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));
			HttpResponseMessage Response1 = Client.Get("/get", HttpCompletionOption::ResponseHeadersRead);
			HttpResponseMessage Response2 = Client.Get("/get", Response1);
			HttpResponseMessage Response3 = Client.Get("/get");
			HttpResponseMessage Response4 = Client.Get("/get");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response1.GetStatusCode());
			Assert::IsTrue(Response1.GetHeaders().Contains("Content-Length"));
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response2.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response3.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response4.GetStatusCode());
		}
		TEST_METHOD(GetBrotli)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));
			HttpResponseMessage Response = Client.Get("/brotli");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
			if (!Response.GetHeaders().GetValues("Content-Encoding").Contains("br"))
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(GetGzip)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));
			HttpResponseMessage Response = Client.Get("/gzip");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
			if (!Response.GetHeaders().GetValues("Content-Encoding").Contains("gzip"))
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
			Client.Connect(Uri("http://httpbin.org"));
			HttpResponseMessage Response = Client.Get("/deflate");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
			if (!Response.GetHeaders().GetValues("Content-Encoding").Contains("deflate"))
			{
				Assert::Fail();
			}
		}
		TEST_METHOD(Options)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));
			HttpResponseMessage Response = Client.Options("/get");
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(Patch)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));

			StringContent Content = StringContent(String("<html><head></head><body>bla</body></html>"));

			HttpResponseMessage Response = Client.Patch("/patch", Content);
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(Post)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));

			StringContent Content = StringContent(String("<html><head></head><body>bla</body></html>"));

			HttpResponseMessage Response = Client.Post("/post", Content);
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}
		TEST_METHOD(Put)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));

			StringContent Content = StringContent(String("<html><head></head><body>bla</body></html>"));

			HttpResponseMessage Response = Client.Put("/put", Content);
			Client.Disconnect();

			// check response
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)Response.GetStatusCode());
		}

		TEST_METHOD(AuthenticationBasic)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));

			// send a request without authorization-headers
			HttpResponseMessage UnauthorizedResponse = Client.Get("/basic-auth/SomeUser/SomePassword");

			// add authorization-headers and send the same request again
			String AuthInfo = "SomeUser:SomePassword";
			Elysium::Core::Collections::Template::Array<Elysium::Core::byte> Bytes = Encoding::UTF8().GetBytes(AuthInfo, 0, AuthInfo.GetLength());
			String Base64AuthInfo = Convert::ToBase64String(&Bytes[0], Bytes.GetLength());
			Client.GetDefaultRequestHeaders().SetAuthorization(Headers::AuthenticationHeaderValue("Basic", Base64AuthInfo));
			HttpResponseMessage AuthorizedResponse = Client.Get("/basic-auth/SomeUser/SomePassword");

			Client.Disconnect();

			// check responses
			Assert::AreEqual((uint32_t)HttpStatusCode::Unauthorized, (uint32_t)UnauthorizedResponse.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)AuthorizedResponse.GetStatusCode());
		}
		TEST_METHOD(AuthenticationBasicHidden)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));

			// send a request without authorization-headers
			HttpResponseMessage UnauthorizedResponse = Client.Get("/hidden-basic-auth/SomeUser/SomePassword");

			// add authorization-headers and send the same request again
			String AuthInfo = "SomeUser:SomePassword";
			Elysium::Core::Collections::Template::Array<Elysium::Core::byte> Bytes = Encoding::UTF8().GetBytes(AuthInfo, 0, AuthInfo.GetLength());
			String Base64AuthInfo = Convert::ToBase64String(&Bytes[0], Bytes.GetLength());
			Client.GetDefaultRequestHeaders().SetAuthorization(Headers::AuthenticationHeaderValue("Basic", Base64AuthInfo));
			HttpResponseMessage AuthorizedResponse = Client.Get("/hidden-basic-auth/SomeUser/SomePassword");

			Client.Disconnect();

			// check responses
			Assert::AreEqual((uint32_t)HttpStatusCode::NotFound, (uint32_t)UnauthorizedResponse.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)AuthorizedResponse.GetStatusCode());
		}

		TEST_METHOD(AuthenticationBearer)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));

			// send a request without authorization-headers
			HttpResponseMessage UnauthorizedResponse = Client.Get("/bearer");

			// add authorization-headers and send the same request again
			Client.GetDefaultRequestHeaders().SetAuthorization(Headers::AuthenticationHeaderValue("Bearer", "SomeToken"));
			HttpResponseMessage AuthorizedResponse = Client.Get("/bearer");

			Client.Disconnect();

			// check responses
			Assert::AreEqual((uint32_t)HttpStatusCode::Unauthorized, (uint32_t)UnauthorizedResponse.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)AuthorizedResponse.GetStatusCode());
		}

		TEST_METHOD(AuthenticationDigest)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("http://httpbin.org"));

			// send a request without authorization-headers
			HttpResponseMessage UnauthorizedResponse = Client.Get("/digest-auth/auth/SomeUser/SomePassword");

			// add authorization-headers and send the same request again
			MD5 MD5HashAlgorithm = MD5();
			//Array<byte> HashValue = MD5HashAlgorithm.ComputeHash()
			// Digest username="SomeUser", realm="me@kennethreitz.com", nonce="1046d954b07d4532474f285cea83c6e9", uri="/digest-auth/auth/SomeUser/SomePassword", algorithm=MD5, response="fa21c135d9de01911ed0939e8281153e", opaque="ee0fc51b95bc7c966858cd509d14d6b8", qop=auth, nc=00000001, cnonce="ca4c9227a0d10c35"
			Client.GetDefaultRequestHeaders().SetAuthorization(Headers::AuthenticationHeaderValue("Digest", "username\"...\", realm=\"...\", nonce=\"...\", uri=\"...\", algorithm=\"...\", response=\"...\", opaque=\"...\", qop=\"...\", nc=\"...\", cnonce=\"...\" "));
			HttpResponseMessage AuthorizedResponse = Client.Get("/digest-auth/auth/SomeUser/SomePassword");

			Client.Disconnect();

			// check responses
			Assert::AreEqual((uint32_t)HttpStatusCode::Unauthorized, (uint32_t)UnauthorizedResponse.GetStatusCode());
			Assert::AreEqual((uint32_t)HttpStatusCode::OK, (uint32_t)AuthorizedResponse.GetStatusCode());
		}

		TEST_METHOD(TLSGet)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri("https://httpbin.org"));
			//HttpResponseMessage Response = Client.Get(u"");
			Client.Disconnect();

			int x = 234;
		}
	};
}