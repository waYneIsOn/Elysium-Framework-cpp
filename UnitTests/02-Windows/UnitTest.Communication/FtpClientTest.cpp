#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.Ftp/FtpClient.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.Ftp/FtpException.hpp"

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
		Service_FtpClient()
			: _Client(FtpClient())
		{ }

		TEST_METHOD_INITIALIZE(BeforeEachMethod)
		{
			_Client.Connect(FtpEncryption::None, DnsEndPoint(String("demo.wftpserver.com"), FtpClient::DefaultFtpControlPort, AddressFamily::InterNetwork));
			_Client.Login("demo", "demo");

			const FtpResponseMessage HostInformationResponse = _Client.GetHostInformation();
			const FtpResponseMessage AccountInformationResponse = _Client.GetAccountInformation();
			const FtpResponseMessage AvailableSpaceResponse = _Client.GetAvailableSpace();

			const FtpResponseMessage SystemTypeResponse = _Client.GetSystemType();
			const FtpResponseMessage SystemFeaturesResponse = _Client.GetSystemFeatures();

			const FtpResponseMessage GenericHelpResponse = _Client.GetHelp("");
			const FtpResponseMessage AuthHelpResponse = _Client.GetHelp("AUTH");
		}
		TEST_METHOD_CLEANUP(AfterEachMethod)
		{
			_Client.Disconnect();
		}

		TEST_METHOD(ChangeDirectories)
		{
			const FtpResponseMessage ChangeDirectoryToDownloadResponse = _Client.ChangeWorkingDirectory("/download");
			if (!ChangeDirectoryToDownloadResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}
			const FtpResponseMessage ChangeDirectoryToRootResponse = _Client.ChangeWorkingDirectory("");
			if (ChangeDirectoryToRootResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			const FtpResponseMessage ChangeToParentDirectoryResponse = _Client.ChangeToParentDirectory();
			if (!ChangeToParentDirectoryResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(ListResourceInformation)
		{
			_Client.EnterPassiveMode();
			const FtpResponseMessage ResourceInformationResponse = _Client.ListResourceInformation("/download");
			if (!ResourceInformationResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			_Client.EnterPassiveMode();
			const FtpResponseMessage NamedDirectoryInformationResponse = _Client.ListNamedDirectoryInformation("/download");
			if (!NamedDirectoryInformationResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			//_Client.EnterPassiveMode();
			const FtpResponseMessage NamedFileInformationResponse = _Client.ListNamedFileInformation("/download/Spring.jpg");
			if (!NamedFileInformationResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			//_Client.EnterPassiveMode();
			const FtpResponseMessage NamedFileInformationResponse2 = _Client.ListNamedFileInformation("/download");
			if (!NamedFileInformationResponse2.GetIsSuccesful())
			{
				Assert::Fail();
			}

			//_Client.EnterPassiveMode();
			const FtpResponseMessage NamedFileInformationResponse3 = _Client.ListNamedFileInformation("/download/NonExistantFile.jpg");
			if (NamedFileInformationResponse3.GetIsSuccesful())
			{
				Assert::Fail();
			}
			
			_Client.EnterPassiveMode();
			const FtpResponseMessage ResourceNamesRootResponse = _Client.ListResourceNames("");
			if (!ResourceNamesRootResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			_Client.EnterPassiveMode();
			const FtpResponseMessage ResourceNamesDownloadResponse = _Client.ListResourceNames("/download");
			if (!ResourceNamesDownloadResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			_Client.EnterPassiveMode();
			const FtpResponseMessage ResourceNamesFileResponse = _Client.ListResourceNames("/download/Spring.jpg");
			if (!ResourceNamesFileResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(DirectoryCRUD)
		{
			const FtpResponseMessage ChangeDirectoryToUploadResponse = _Client.ChangeWorkingDirectory("/upload");
			if (!ChangeDirectoryToUploadResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			const FtpResponseMessage MakeDirectoryResponse = _Client.MakeDirectory("/tmp");
			if (MakeDirectoryResponse.GetIsSuccesful())
			{
				// ToDo: rename (RNFR and RNTO)
				const FtpResponseMessage RemoveDirectoryResponse = _Client.DeleteDirectory("/tmp");
				if (!RemoveDirectoryResponse.GetIsSuccesful())
				{
					Assert::Fail();
				}
			}
			else
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(DownloadFile)
		{
			const FtpResponseMessage ChangeDirectoryToDownloadResponse = _Client.ChangeWorkingDirectory("/download");
			if (!ChangeDirectoryToDownloadResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			const FtpResponseMessage NamedFileInformationResponse = _Client.ListNamedFileInformation("Spring.jpg");
			if (!NamedFileInformationResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			FileStream TargetStream = FileStream(String("Target.jpg"), FileMode::Create, FileAccess::Write);
			try
			{
				_Client.EnterPassiveMode();
				_Client.DownloadFile("NonExistantFile.jpg", TargetStream);
			}
			catch(FtpException&)
			{ }

			_Client.EnterPassiveMode();
			_Client.DownloadFile("Spring.jpg", TargetStream);
		}
		
		TEST_METHOD(UploadFile)
		{
			// execute DownloadFile() so we are sure to have a file we can upload
			DownloadFile();

			const FtpResponseMessage ChangeDirectoryToDownloadResponse = _Client.ChangeWorkingDirectory("/upload");
			if (!ChangeDirectoryToDownloadResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			FileStream SourceStream = FileStream(String("Target.jpg"), FileMode::Open, FileAccess::Read);
			_Client.EnterPassiveMode();
			_Client.UploadFile("Spring.jpg", SourceStream);
		}
	private:
		FtpClient _Client;
	};
}