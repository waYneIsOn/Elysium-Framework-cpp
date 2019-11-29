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
			
			Uri GetFirstEntryUri = Uri(u"http://jsonplaceholder.typicode.com/todos/1");
			Client.TestGET(GetFirstEntryUri);

			Uri GetAllEntriesUri = Uri(u"http://jsonplaceholder.typicode.com/todos");
			Client.TestGET(GetAllEntriesUri);
			
			Client.Disconnect();
		}
	private:
		Uri _ServiceUri = Uri(u"http://jsonplaceholder.typicode.com");
	};
}