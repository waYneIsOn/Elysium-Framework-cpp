#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.Ftp/FtpClient.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/FileStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/MemoryStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.IO/GZipStream.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/DnsEndPoint.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Security.Cryptography.Algorithms/MD5.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/Encoding.hpp"

using namespace Elysium::Core;
using namespace Elysium::Core::IO;
using namespace Elysium::Core::IO::Compression;
using namespace Elysium::Core::Net;
using namespace Elysium::Core::Net::Sockets;
using namespace Elysium::Core::Security::Cryptography;
using namespace Elysium::Core::Text;
using namespace Elysium::Communication::Service::Ftp;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_FtpClient)
	{
	public:
		TEST_METHOD(Connect)
		{
			FtpClient Client = FtpClient();
			Client.Connect(FtpEncryption::None, DnsEndPoint(String("demo.wftpserver.com"), 21, AddressFamily::InterNetwork));
			Client.Login("demo", "demo");

			const FtpResponseMessage SystemFeaturesResponse = Client.GetSystemFeatures();
			const FtpResponseMessage SystemInformationResponse = Client.GetSystemInformation();

			Client.EnterPassiveMode();
			const FtpResponseMessage ResourceInformationResponse = Client.ListResourceInformation("/");






			const FtpResponseMessage PrintRootDirectoryResponse = Client.PrintWorkingDirectory();



			const FtpResponseMessage ChangeDirectoryResponse = Client.ChangeWorkingDirectory("download");
			const FtpResponseMessage ChangeToParentDirectoryResponse = Client.ChangeToParentDirectory();

			Client.Disconnect();
		}
	};
}