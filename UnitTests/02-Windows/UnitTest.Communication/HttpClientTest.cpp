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
			Client.Connect(Uri(L"http://neverssl.com"));

			HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Get(), Uri(L"http://dcbfhklnmstrwxvz.neverssl.com/online"));
			Request.GetHeaders().SetHost(String(L"neverssl.com"));
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

				if(Response.GetHeaders().GetValues(L"Content-Encoding").Contains(L"gzip"))
				{
					FileStream FS = FileStream(L"test.lz77", FileMode::Create);
					ContentStream.CopyTo(FS);

					GZipStream UncompressedContentStream = GZipStream(ContentStream, CompressionMode::Decompress);
					byte Buffer[1024];
					size_t BytesRead = 0;
					do
					{
						//BytesRead = UncompressedContentStream.Read(&Buffer[0], 1024);
						BytesRead = ContentStream.Read(&Buffer[0], 1024);

						uint32_t Timestamp;
						memcpy(&Timestamp, &Buffer[0], 4);

						byte Test1 = Buffer[0];
						if (Buffer[0] == 0x1F)
						{
							int sdf = 45;
						}
						else
						{
							int sdf = 45;
						}
					} while (BytesRead > 0);
				}
			}
		}
	};
}