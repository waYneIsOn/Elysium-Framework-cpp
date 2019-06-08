#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication/TcpClient.hpp"

using namespace Elysium::Communication::Service::Tcp;
using namespace Elysium::Core;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{		
	TEST_CLASS(Service_TcpClient)
	{
	public:
		TEST_METHOD(CommuncationTest)
		{
			TcpClient Client = TcpClient();
			Client.Connect(String(L"172.217.21.3"), 80);

			//Client.g

			Client.Close();
		}
	};
}