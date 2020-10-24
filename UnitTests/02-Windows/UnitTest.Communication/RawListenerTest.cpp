#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../Libraries/01-Shared/Elysium.Communication/BinaryProtocol.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/IPProtocolNumber.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication/KnownTcpPort.hpp"
#include "../../../Libraries/01-Shared/Elysium.Communication.Service.Raw/RawListener.hpp"

#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/BitConverter.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/IPEndPoint.hpp"
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Text/UTF8Encoding.hpp"

using namespace Elysium::Communication::Service::Raw;
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
			//Listener.Bind(IPEndPoint(IPAddress::Parse(String("127.0.0.1")), 0));
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
					//break;
				}

				Iter++;
			} while (Iter < 2500);

			Assert::IsTrue(HasCapturedFtpDataPackage);
		}

	private:
		bool ParseIPv4(const Elysium::Core::byte* Data, const size_t Count)
		{
			const Elysium::Core::int32_t IpVersion = Data[0] >> 4;
			if (IpVersion != 4)
			{
				throw 1;
			}
			const Elysium::Core::int16_t IpHeaderLength = (Data[0] & 0x0F) * 4;// * 32 / 8
			const Elysium::Core::int8_t IpPriorityAndTypeOfService = Data[1];
			const Elysium::Core::int16_t IpTotalLength = BitConverter::ToInt16(&Data[2]);
			if (IpTotalLength != Count)
			{
				throw 1;
			}

			const Elysium::Core::int16_t IpIdentification = BitConverter::ToInt16(&Data[4]);
			const Elysium::Core::int32_t IpFlags = Data[6] >> 3;
			const Elysium::Core::int16_t IpFragmentOffset = (Data[6] & 0x1F) | Data[7];

			const Elysium::Core::int8_t IpTimeToLive = Data[8];

			const Elysium::Communication::Protocol::InternetLayer::IPProtocolNumber IpProtocolNumber = static_cast<const Elysium::Communication::Protocol::InternetLayer::IPProtocolNumber>(Data[9]);
			const Elysium::Core::int16_t IpChecksum = BitConverter::ToInt16(&Data[10]);

			const Elysium::Core::uint32_t IpSourceAddress = BitConverter::ToUInt32(&Data[12]);
			const Elysium::Core::uint32_t IpDestinationAddress = BitConverter::ToUInt32(&Data[16]);
			
			if (IpHeaderLength != 20)
			{
				// ToDo: read optional values if there are any
			}

			if (Count < IpTotalLength)
			{
				// ToDo: read more bytes
				throw 1;
			}
			else
			{
				switch (IpProtocolNumber)
				{
				case Elysium::Communication::Protocol::InternetLayer::IPProtocolNumber::Tcp:
					return ParseTcp(&Data[IpHeaderLength], IpTotalLength - IpHeaderLength);
				case Elysium::Communication::Protocol::InternetLayer::IPProtocolNumber::Udp:
					return ParseUdp(&Data[IpHeaderLength]);
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
			const Elysium::Core::uint16_t TcpSourcePort = BitConverter::ToUInt16(&Data[0]);
			const Elysium::Core::uint16_t TcpDestinationPort = BitConverter::ToUInt16(&Data[2]);
			const Elysium::Core::uint32_t TcpSequence = BitConverter::ToUInt32(&Data[4]);
			const Elysium::Core::uint32_t TcpAcknowledge = BitConverter::ToUInt32(&Data[8]);
			
			const Elysium::Core::int32_t TcpHeaderLength = (Data[12] >> 4) * 4;	// * 32 / 8;
			// reserved (3 low bits) "For future use and should be set to zero."
			// flags (9 bit - byte 12 & 13)
			const Elysium::Core::uint16_t TcpWindowSize = BitConverter::ToUInt16(&Data[14]);
			const Elysium::Core::uint16_t TcpChecksum = BitConverter::ToUInt16(&Data[16]);
			const Elysium::Core::uint16_t TcpUrgentPointer = BitConverter::ToUInt16(&Data[18]);

			if (TcpHeaderLength > 20)
			{
				// ToDo: read optional values if there are any
			}

			if (TcpSourcePort == static_cast<Elysium::Core::uint16_t>(Elysium::Communication::KnownTcpPort::FtpControl) || 
				TcpDestinationPort == static_cast<Elysium::Core::uint16_t>(Elysium::Communication::KnownTcpPort::FtpControl))
			{
				return ParseFtpControl(&Data[TcpHeaderLength], Count - TcpHeaderLength);
			}

			return false;
		}

		bool ParseUdp(const Elysium::Core::byte* Data)
		{
			return false;
		}

		bool ParseFtpControl(const Elysium::Core::byte* Data, const size_t Count)
		{
			Logger::WriteMessage(&Elysium::Core::Text::Encoding::UTF8().GetString(Data, Count)[0]);

			return true;
		}
	};
}