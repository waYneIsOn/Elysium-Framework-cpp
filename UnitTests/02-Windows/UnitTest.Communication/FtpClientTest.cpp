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
			: _Client(FtpClient(Elysium::Communication::Protocol::InternetLayer::InternetProtocolVersion::V4))
		{ }

		TEST_METHOD_INITIALIZE(BeforeEachMethod)
		{
			_Client.Connect(FtpEncryption::None, DnsEndPoint(String(u8"demo.wftpserver.com"), FtpClient::DefaultFtpControlPort, AddressFamily::InterNetwork));
			_Client.Login(u8"demo", u8"demo");

			const FtpResponseMessage HostInformationResponse = _Client.GetHostInformation();
			const FtpResponseMessage AccountInformationResponse = _Client.GetAccountInformation();
			const FtpResponseMessage AvailableSpaceResponse = _Client.GetAvailableSpace();

			const FtpResponseMessage SystemTypeResponse = _Client.GetSystemType();
			const FtpResponseMessage SystemFeaturesResponse = _Client.GetSystemFeatures();

			const FtpResponseMessage GenericHelpResponse = _Client.GetHelp(u8"");
			const FtpResponseMessage AuthHelpResponse = _Client.GetHelp(u8"AUTH");
		}
		TEST_METHOD_CLEANUP(AfterEachMethod)
		{
			_Client.Disconnect();
		}

		TEST_METHOD(ChangeDirectories)
		{
			const FtpResponseMessage ChangeDirectoryToDownloadResponse = _Client.ChangeWorkingDirectory(u8"/download");
			if (!ChangeDirectoryToDownloadResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}
			const FtpResponseMessage ChangeDirectoryToRootResponse = _Client.ChangeWorkingDirectory(u8"");
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
			const FtpResponseMessage ResourceInformationResponse = _Client.ListResourceInformation(u8"/download");
			if (!ResourceInformationResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			_Client.EnterPassiveMode();
			const FtpResponseMessage NamedDirectoryInformationResponse = _Client.ListNamedDirectoryInformation(u8"/download");
			if (!NamedDirectoryInformationResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			//_Client.EnterPassiveMode();
			const FtpResponseMessage NamedFileInformationResponse = _Client.ListNamedFileInformation(u8"/download/Spring.jpg");
			if (!NamedFileInformationResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			//_Client.EnterPassiveMode();
			const FtpResponseMessage NamedFileInformationResponse2 = _Client.ListNamedFileInformation(u8"/download");
			if (!NamedFileInformationResponse2.GetIsSuccesful())
			{
				Assert::Fail();
			}

			//_Client.EnterPassiveMode();
			const FtpResponseMessage NamedFileInformationResponse3 = _Client.ListNamedFileInformation(u8"/download/NonExistantFile.jpg");
			if (NamedFileInformationResponse3.GetIsSuccesful())
			{
				Assert::Fail();
			}
			
			_Client.EnterPassiveMode();
			const FtpResponseMessage ResourceNamesRootResponse = _Client.ListResourceNames(u8"");
			if (!ResourceNamesRootResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			_Client.EnterPassiveMode();
			const FtpResponseMessage ResourceNamesDownloadResponse = _Client.ListResourceNames(u8"/download");
			if (!ResourceNamesDownloadResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			_Client.EnterPassiveMode();
			const FtpResponseMessage ResourceNamesFileResponse = _Client.ListResourceNames(u8"/download/Spring.jpg");
			if (!ResourceNamesFileResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}
		}

		TEST_METHOD(DirectoryCRUD)
		{
			const FtpResponseMessage ChangeDirectoryToUploadResponse = _Client.ChangeWorkingDirectory(u8"/upload");
			if (!ChangeDirectoryToUploadResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			const FtpResponseMessage MakeDirectoryResponse = _Client.MakeDirectory(u8"/tmp");
			if (MakeDirectoryResponse.GetIsSuccesful())
			{
				// ToDo: rename (RNFR and RNTO)
				const FtpResponseMessage RemoveDirectoryResponse = _Client.DeleteDirectory(u8"/tmp");
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

		TEST_METHOD(TransferFiles)
		{
			const FtpResponseMessage ChangeDirectoryToDownloadResponse = _Client.ChangeWorkingDirectory(u8"/download");
			if (!ChangeDirectoryToDownloadResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			const FtpResponseMessage NamedFileInformationResponse = _Client.ListNamedFileInformation(u8"Spring.jpg");
			if (!NamedFileInformationResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			FileStream TargetStream = FileStream(String(u8"Target.jpg"), FileMode::Create, FileAccess::Write);
			try
			{
				_Client.EnterPassiveMode();
				_Client.DownloadFile(u8"NonExistantFile.jpg", TargetStream);
			}
			catch (FtpException& ex)
			{ }

			try
			{
				_Client.EnterPassiveMode();
				_Client.DownloadFile(u8"Spring.jpg", TargetStream);
			}
			catch (FtpException& ex)
			{ }

			const FtpResponseMessage ChangeDirectoryToUploadResponse = _Client.ChangeWorkingDirectory(u8"/upload");
			if (!ChangeDirectoryToUploadResponse.GetIsSuccesful())
			{
				Assert::Fail();
			}

			FileStream SourceStream = FileStream(String(u8"Target.jpg"), FileMode::Open, FileAccess::Read);
			_Client.EnterPassiveMode();
			_Client.UploadFile(u8"Spring.jpg", SourceStream);
		}
	private:
		FtpClient _Client;
	};
}