#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.HTTP/HttpClient.hpp"

using namespace Elysium::Core;
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
			Client.Connect(Uri(L"https://93.184.220.42"));

			HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Get(), Uri(L"https://93.184.220.42/NonExistent.html"));
			Client.SendRequest(&Request);

			HttpResponseMessage Response(&Request);
			Client.ReceiveResponse(&Response);

			Client.Disconnect();
		}
	};
}