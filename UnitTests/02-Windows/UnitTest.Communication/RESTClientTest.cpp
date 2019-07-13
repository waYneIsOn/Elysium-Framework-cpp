#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.REST/RESTClient.hpp"

using namespace Elysium::Communication::Service::Http;
using namespace Elysium::Communication::Service::REST;
using namespace Elysium::Core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_RESTClient)
	{
	public:
		TEST_METHOD(ConnectionTest)
		{
			RESTClient Client = RESTClient();
			Client.Connect(_ServiceUri);
			Client.Disconnect();
		}

		TEST_METHOD(GetData)
		{
			RESTClient Client = RESTClient();
			Client.Connect(_ServiceUri);

			Uri GetFirstEntryUri = Uri(L"http://jsonplaceholder.typicode.com/todos/1");
			Client.TestGET(GetFirstEntryUri);

			Client.Disconnect();
		}
	private:
		Uri _ServiceUri = Uri(L"http://jsonplaceholder.typicode.com");
	};
}