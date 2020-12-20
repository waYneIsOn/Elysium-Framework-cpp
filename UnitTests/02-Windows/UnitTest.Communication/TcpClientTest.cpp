#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication/TcpClient.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/BinaryProtocol.hpp"

using namespace Elysium::Communication::Protocol;
using namespace Elysium::Communication::Transport;
using namespace Elysium::Core;
using namespace Elysium::Core::Net::Sockets;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{		
	TEST_CLASS(Transport_TcpClient)
	{
	public:
		TEST_METHOD(ConnectionTestIPv4)
		{
			TcpClient Client = TcpClient(Elysium::Communication::Protocol::InternetLayer::InternetProtocolVersion::V4);
			BinaryProtocol Protocol = BinaryProtocol(Client);

			Client.Connect(String(u8"www.google.com"), 80);
			Client.Close();
		}

		TEST_METHOD(ConnectionTestIPv6)
		{
			Assert::Fail();
		}
	};
}