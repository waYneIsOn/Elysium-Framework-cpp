#include "stdafx.h"
#include "CppUnitTest.h"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Exception.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/IPEndPoint.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Threading/Thread.hpp"

#include "../../../Libraries/01-Shared/Elysium.Communication.Service.Ftp/FtpClient.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.Ftp/FtpServer.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::Net;
using namespace Elysium::Core::Threading;
using namespace Elysium::Communication::Service::Ftp;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_FtpServer)
	{
	public:
		TEST_CLASS_INITIALIZE(OnClassStart)
		{	// start the server on another thread so our tests can run on the main-thread
			_ServerThread.Start();

			// wait a bit for the server to run
			Thread::Sleep(TimeSpan::FromSeconds(1));
		}
		TEST_CLASS_CLEANUP(OnClassStop)
		{
			// wait a bit for clients to finish up their work (makes for easier debugging)
			Thread::Sleep(TimeSpan::FromSeconds(1));
			_Server.Stop();
		}

		TEST_METHOD(MinimumImplementation)
		{
			_Client.Connect(FtpEncryption::None, _RemoteEndPoint);
			_Client.Login(u8"user", u8"password");

			_Client.Disconnect();
		}
	private:

		inline static IPEndPoint _LocalEndPoint = IPEndPoint(IPAddress::Any(), FtpServer::DefaultFtpControlPort);
		inline static FtpServer _Server = FtpServer(Elysium::Communication::Protocol::InternetLayer::InternetProtocolVersion::V4);

		inline static IPEndPoint _RemoteEndPoint = IPEndPoint(IPAddress::Parse(u8"127.0.0.1"), FtpServer::DefaultFtpControlPort);
		inline static FtpClient _Client = FtpClient(Elysium::Communication::Protocol::InternetLayer::InternetProtocolVersion::V4);

		static void ServerMain()
		{
			const int BLa = Thread::GetCurrentThreadIdX();
			_Server.Start(_LocalEndPoint, 100);
		}

		inline static Thread _ServerThread = Thread(Delegate<void>::CreateDelegate<&Service_FtpServer::ServerMain>());
	};
}
