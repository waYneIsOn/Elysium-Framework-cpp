#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication/BinaryProtocol.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/InternetProtocolNumber.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/KnownTcpPort.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/UdpClient.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/IPv4Header.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/TcpHeader.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.Raw/RawListener.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/IPEndPoint.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/UTF8Encoding.hpp"

using namespace Elysium::Communication::Protocol::InternetLayer;
using namespace Elysium::Communication::Protocol::TransportLayer;
using namespace Elysium::Communication::Service::Raw;
using namespace Elysium::Communication::Transport;
using namespace Elysium::Core;
using namespace Elysium::Core::Net;
using namespace Elysium::Core::Net::Sockets;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestCommunication
{
	TEST_CLASS(Service_RawListener)
	{
	public:
		TEST_METHOD(GetIcmpError)
		{
			Assert::Fail();
			/*
			IPEndPoint RemoteEndpoint = IPEndPoint(IPAddress::Parse(String("192.168.1.1")), 1337);

			Elysium::Core::byte Data[1024];
			Data[0] = 0x37;
			Data[1] = 0x37;
			Data[2] = 0x37;
			Data[3] = 0x37;

			RawListener Listener = RawListener(AddressFamily::InterNetwork);
			Listener.Bind(IPEndPoint(IPAddress::Parse(String("192.168.1.100")), 0));

			UdpClient Client = UdpClient(InternetProtocolVersion::V4);
			Client.Connect(RemoteEndpoint);
			Client.Write(Data, 4);
			Client.Close();

			byte Buffer[65536];
			int Iter = 0;
			do
			{
				const size_t BytesRead = Listener.Read(&Buffer[0], 65536);
				ParseIPv4(&Buffer[0], BytesRead);

				Iter++;
			} while (Iter < 2500);
			*/
			/*
			InternetProtocolv4 Ip = InternetProtocolv4(Listener);
			UserDatagramProtocol Udp = UserDatagramProtocol(Client, Ip, 65500, RemoteEndpoint.GetPort());
			Udp.WriteApplicationData(nullptr, 0);
			*/
			//TransmissionControlProtocol Tcp = TransmissionControlProtocol(Client, Ip, 27015, 80);
			//Tcp.WriteSynchronize();
		}

		TEST_METHOD(RunUntilFtpDataCapture)
		{
			RawListener Listener = RawListener(AddressFamily::InterNetwork);
			Listener.Bind(IPEndPoint(IPAddress::Parse(String("192.168.1.100")), 0));

			byte Buffer[65536];
			bool HasCapturedFtpDataPackage = false;
			int Iter = 0;
			do
			{
				const size_t BytesRead = Listener.Read(&Buffer[0], 65536);
				HasCapturedFtpDataPackage = ParseIPv4(&Buffer[0], BytesRead);
				if (HasCapturedFtpDataPackage)
				{
					break;
				}

				Iter++;
			} while (Iter < 2500);

			Assert::IsTrue(HasCapturedFtpDataPackage);
		}

	private:
		bool ParseIPv4(const Elysium::Core::byte* Data, const size_t Count)
		{
			const IPv4Header* Header = (const IPv4Header*)Data;

			const Elysium::Core::uint8_t IpVersion = Header->GetVersion();
			if (IpVersion != 4)
			{
				throw 1;
			}

			const Elysium::Core::uint8_t IpHeaderLength = Header->GetHeaderLength() * 4;
			if (IpHeaderLength > IPv4Header::MINIMUMHEADERSIZE)
			{
				// ToDo: read optional values if there are any
			}

			const Elysium::Core::uint16_t IpTotalLength = Header->GetTotalLength();
			if (Count < IpTotalLength)
			{	// we haven't received the whole ipv4-packet yet
				throw 1;
			}
			else
			{
				const Elysium::Communication::Protocol::InternetLayer::InternetProtocolNumber IpNumber = Header->GetProtocol();
				switch (IpNumber)
				{
				case Elysium::Communication::Protocol::InternetLayer::InternetProtocolNumber::Icmp:
					return ParseIcmp(&Data[IpHeaderLength], IpTotalLength - IpHeaderLength);
				case Elysium::Communication::Protocol::InternetLayer::InternetProtocolNumber::Tcp:
					return ParseTcp(&Data[IpHeaderLength], IpTotalLength - IpHeaderLength);
				case Elysium::Communication::Protocol::InternetLayer::InternetProtocolNumber::Udp:
					return ParseUdp(&Data[IpHeaderLength], IpTotalLength - IpHeaderLength);
				default:
					return false;
				}
			}
		}

		bool ParseIPv6(const Elysium::Core::byte* Data, const size_t Count)
		{
			throw 1;
		}

		bool ParseTcp(const Elysium::Core::byte* Data, const size_t Count)
		{
			const TcpHeader* Header = (const TcpHeader*)Data;

			const Elysium::Core::int32_t TcpHeaderLength = Header->GetHeaderLength() * 4;
			if (TcpHeaderLength > TcpHeader::MINIMUMHEADERSIZE)
			{
				// ToDo: read optional values if there are any
			}

			const Elysium::Core::uint16_t TcpSourcePort = Header->GetSourcePort();
			const Elysium::Core::uint16_t TcpDestinationPort = Header->GetDestinationPort();
			if (TcpSourcePort == static_cast<Elysium::Core::uint16_t>(Elysium::Communication::KnownTcpPort::FtpControl) || 
				TcpDestinationPort == static_cast<Elysium::Core::uint16_t>(Elysium::Communication::KnownTcpPort::FtpControl))
			{
				return ParseFtpControl(&Data[TcpHeaderLength], Count - TcpHeaderLength);
			}

			return false;
		}

		bool ParseUdp(const Elysium::Core::byte* Data, const size_t Count)
		{
			const Elysium::Core::uint16_t UdpSourcePort = BitConverter::ToUInt16(&Data[0]);
			const Elysium::Core::uint16_t UdpDestinationPort = BitConverter::ToUInt16(&Data[2]);
			const Elysium::Core::uint16_t UdpTotalLength = BitConverter::ToUInt16(&Data[4]);
			const Elysium::Core::uint16_t UdpCrcChecksum = BitConverter::ToUInt16(&Data[6]);

			return false;
		}

		bool ParseIcmp(const Elysium::Core::byte* Data, const size_t Count)
		{
			const Elysium::Core::uint8_t* IcmpType = &Data[0];
			const Elysium::Core::uint8_t* IcmpCode = &Data[1];
			const Elysium::Core::uint16_t* IcmpChecksum = (const Elysium::Core::uint16_t*)&Data[2];
			const Elysium::Core::uint32_t* IcmpRestOfHeader = (const Elysium::Core::uint32_t*)&Data[4];

			return false;
		}

		bool ParseFtpControl(const Elysium::Core::byte* Data, const size_t Count)
		{
			Logger::WriteMessage(&Elysium::Core::Text::Encoding::UTF8().GetString(Data, Count)[0]);

			return true;
		}
	};
}