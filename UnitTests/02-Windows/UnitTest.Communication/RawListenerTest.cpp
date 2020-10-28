#include "stdafx.h"
#include "CppUnitTest.h"

#include "../../../Libraries/01-Shared/Elysium.Communication/BinaryProtocol.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/InternetProtocolNumber.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/IcmpV4Header.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/IPv4Header.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/KnownTcpPort.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/TcpHeader.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/UdpHeader.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.Raw/RawListener.hpp"

#include "../../../Libraries/01-Shared/Elysium.Communication/UdpClient.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/DnsEndPoint.hpp"
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
		TEST_METHOD(RunUntilFtpDataCapture)
		{
			RawListener Listener = RawListener(AddressFamily::InterNetwork);
			Listener.Bind(IPEndPoint(IPAddress::Parse(String("192.168.1.100")), 0));

			byte Buffer[65535];
			bool HasCapturedFtpDataPackage = false;
			int Iter = 0;
			do
			{
				const size_t BytesRead = Listener.Read(&Buffer[0], sizeof(Buffer));
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
			const UdpHeader* Header = (const UdpHeader*)Data;

			const Elysium::Core::uint16_t UdpSourcePort = Header->GetSourcePort();
			const Elysium::Core::uint16_t UdpDestinationPort = Header->GetDestinationPort();
			const Elysium::Core::uint16_t UdpTotalLength = Header->GetTotalLength();
			const Elysium::Core::uint16_t UdpCrcChecksum = Header->GetChecksum();

			return false;
		}

		bool ParseIcmp(const Elysium::Core::byte* Data, const size_t Count)
		{
			const IcmpV4Header* Header = (const IcmpV4Header*)Data;

			const IcmpType Type = Header->GetType();
			const Elysium::Core::uint8_t IcmpCode = Header->GetCode();
			const Elysium::Core::uint16_t IcmpChecksum = Header->GetChecksum();
			const Elysium::Core::uint32_t IcmpRestOfHeader = Header->GetRestOfHeader();

			return false;
		}

		bool ParseFtpControl(const Elysium::Core::byte* Data, const size_t Count)
		{
			Logger::WriteMessage(&Elysium::Core::Text::Encoding::UTF8().GetString(Data, Count)[0]);

			return true;
		}
	};
}