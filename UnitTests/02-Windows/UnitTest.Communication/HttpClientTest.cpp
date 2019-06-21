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
		TEST_METHOD(ConnectionTest)
		{
			HttpClient Client = HttpClient();
			Client.Connect(Uri(L"http://13.32.24.99"));	// neverssl.com

			HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Get(), Uri(L"http://dcbfhklnmstrwxvz.neverssl.com/online"));
			Request.GetHeaders().SetHost(String(L"dcbfhklnmstrwxvz.neverssl.com"));
			Client.SendRequest(Request);

			HttpResponseMessage Response(&Request);
			Client.ReceiveResponse(Response);
			/*
			Client.SendRequest(Request);
			Client.ReceiveResponse(Response);
			*/
			Client.Disconnect();

			if (Response.GetHeaders().Contains(L"Content-Encoding"))
			{
				MemoryStream ContentStream;
				Response.GetContent()->ReadAsStream(ContentStream);
				const HttpContent* ResponseContent = Response.GetContent();

				if(Response.GetHeaders().GetValues(L"Content-Encoding").Contains(L"gzip"))
				{
					GZipStream UncompressedContentStream = GZipStream(ContentStream, CompressionMode::Decompress);
				}
			}
			/*
			const ByteArrayContent* ByteContent = static_cast<const ByteArrayContent*>(Response.GetContent());
			const size_t ByteLength = ByteContent->GetLength();
			const byte* Bytes = ByteContent->GetContent();
			*/
		}
	};
}