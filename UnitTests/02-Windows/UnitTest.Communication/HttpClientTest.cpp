#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.HTTP/HttpClient.hpp"

using namespace Elysium::Communication::Service::Http;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_HttpClient)
	{
	public:
		TEST_METHOD(ConnectionTest)
		{
			HttpClient Client = HttpClient(Elysium::Core::Uri(L""));

			HttpRequestMessage Request = HttpRequestMessage(HttpMethod::Get(), Elysium::Core::Uri(L""));
			Client.SendRequest(Request);
		}
	};
}