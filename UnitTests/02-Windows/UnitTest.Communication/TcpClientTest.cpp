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
	TEST_CLASS(Service_TcpClient)
	{
	public:
		TEST_METHOD(CommuncationTest)
		{
			Socket ClientSocket = Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
			TcpClient Client = TcpClient(&ClientSocket);
			BinaryProtocol Protocol = BinaryProtocol(&Client);

			Client.Connect(String(L"172.217.21.3"), 80);

			//Client.g

			Client.Close();
		}
	};
}