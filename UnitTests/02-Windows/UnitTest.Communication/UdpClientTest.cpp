#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication/UdpClient.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/IPEndPoint.hpp"

using namespace Elysium::Communication::Protocol::InternetLayer;
using namespace Elysium::Communication::Transport;
using namespace Elysium::Core;
using namespace Elysium::Core::Net;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{
	TEST_CLASS(Transport_UdpClient)
	{
	public:
		TEST_METHOD(ConnectionTest)
		{
			IPEndPoint RemoteEndpoint = IPEndPoint(IPAddress::Parse(String("192.168.1.1")), 1337);

			UdpClient Client = UdpClient(InternetProtocolVersion::V4);
			Client.Connect(RemoteEndpoint);

			Elysium::Core::byte Data[1024];
			Data[0] = 0x37;
			Data[1] = 0x37;
			Data[2] = 0x37;
			Data[3] = 0x37;

			Client.Write(Data, 4);

			const size_t BytesRead = Client.Read(Data, 1024);

			Client.Close();
		}
	};
}