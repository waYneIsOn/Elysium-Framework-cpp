#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.Irc/IrcClient.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/DnsEndPoint.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::Net;
using namespace Elysium::Core::Net::Sockets;
using namespace Elysium::Communication::Service::Irc;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_IrcClient)
	{
	public:
		Service_IrcClient()
			: _Client(IrcClient(Elysium::Communication::Protocol::InternetLayer::InternetProtocolVersion::V4))
		{ }

		TEST_METHOD_INITIALIZE(BeforeEachMethod)
		{
			_Client.Connect(DnsEndPoint(String(u8"dreamhack.se.quakenet.org"), 6667, AddressFamily::InterNetwork));
		}
		TEST_METHOD_CLEANUP(AfterEachMethod)
		{
			_Client.Disconnect();
		}

		TEST_METHOD(Bla)
		{
			_Client.Test();
		}
	private:
		IrcClient _Client;
	};
}
