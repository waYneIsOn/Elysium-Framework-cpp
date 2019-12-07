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
		TEST_METHOD(GetData)
		{
			RESTClient Client = RESTClient();
			Client.Connect(_ServiceUri);
			
			Client.TestGET(u"/todos/1");
			Client.TestGET(u"/todos");
			
			Client.Disconnect();
		}
	private:
		Uri _ServiceUri = Uri(u"http://jsonplaceholder.typicode.com");
	};
}