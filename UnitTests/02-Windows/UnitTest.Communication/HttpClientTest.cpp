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
			Client.Connect(Uri(L"http://13.32.24.99"));	// neverssl.com

			HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Get(), Uri(L"http://dcbfhklnmstrwxvz.neverssl.com/online"));
			Request.GetHeaders().SetHost(String(L"dcbfhklnmstrwxvz.neverssl.com"));
			Client.SendRequest(Request);

			HttpResponseMessage Response(&Request);
			Client.ReceiveResponse(Response);
			
			Client.SendRequest(Request);
			Client.ReceiveResponse(Response);
			
			Client.Disconnect();
		}
	};
}