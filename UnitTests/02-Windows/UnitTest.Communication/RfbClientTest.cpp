#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.Rfb/RfbClient.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/FileStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/MemoryStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/GZipStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/IPEndPoint.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Security.Cryptography.Algorithms/MD5.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::IO;
using namespace Elysium::Core::IO::Compression;
using namespace Elysium::Core::Net;
using namespace Elysium::Core::Net::Sockets;
using namespace Elysium::Core::Security::Cryptography;
using namespace Elysium::Core::Text;
using namespace Elysium::Communication::Service::Rfb;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_RfbClient)
	{
	public:
		TEST_METHOD(Bla)
		{
			RfbClient Client = RfbClient(Elysium::Communication::Protocol::InternetLayer::InternetProtocolVersion::V4);
			Client.Connect(IPEndPoint(IPAddress::Parse(u8"127.0.0.1"), RfbClient::DefaultRfbPort));

			Client.Disconnect();
		}
	};
}
