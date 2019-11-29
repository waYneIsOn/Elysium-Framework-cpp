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
		TEST_METHOD(ConnectionTest)
		{
			Socket ClientSocket = Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
			TcpClient Client = TcpClient(ClientSocket);
			BinaryProtocol Protocol = BinaryProtocol(Client);

			Client.Connect(String(u"www.google.com"), 80);
			Client.Close();
		}
	};
}