#include "stdafx.h"
#include "CppUnitTest.h"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/DnsEndPoint.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.REST/RESTClient.hpp"

using namespace Elysium::Core::Net;
using namespace Elysium::Core::Net::Sockets;
using namespace Elysium::Communication::Service::Http;
using namespace Elysium::Communication::Service::Rest;
using namespace Elysium::Core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_RestClient)
	{
	public:
		TEST_METHOD(GetData)
		{
			RestClient Client = RestClient();
			Client.SetBaseAddress(Elysium::Core::Uri(Elysium::Core::String(u8"jsonplaceholder.typicode.com")));
			Client.Connect();
			
			Client.TestGET(u8"/todos/1");
			Client.TestGET(u8"/todos");
			
			Client.Disconnect();
		}
	};
}