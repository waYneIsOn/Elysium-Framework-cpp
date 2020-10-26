/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_IPV4HEADER
#define ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_IPV4HEADER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

#ifndef ELYSIUM_CORE_BYTE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Byte.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_INTERNETPROTOCOLNUMBER
#include "InternetProtocolNumber.hpp"
#endif

namespace Elysium::Communication::Protocol::InternetLayer
{
	class ELYSIUM_COMMUNICATION_API IPv4Header final
	{
	public:
		IPv4Header();
		IPv4Header(const IPv4Header& Source) = delete;
		IPv4Header(IPv4Header&& Right) noexcept = delete;
		~IPv4Header();

		IPv4Header& operator=(const IPv4Header& Source) = delete;
		IPv4Header& operator=(IPv4Header&& Right) noexcept = delete;
		
		static constexpr Elysium::Core::uint8_t MINIMUMHEADERSIZE = 20;
		static constexpr Elysium::Core::uint8_t MAXIMUMHEADERSIZE = 60;
		static constexpr Elysium::Core::uint16_t MAXIMUMPACKETSIZE = 65535;

		const Elysium::Core::uint8_t GetVersion() const;

		const Elysium::Core::uint8_t GetHeaderLength() const;

		const Elysium::Core::uint8_t GetDifferentiatedServicesCodePoint() const;

		const Elysium::Core::uint8_t GetExplicitCongestionNotification() const;

		const Elysium::Core::uint16_t GetTotalLength() const;

		const Elysium::Core::uint16_t GetIdentification() const;

		const bool GetReservedFlag() const;

		const bool GetDontFragmentFlag() const;

		const bool GetMoreFragmentsFlag() const;

		const Elysium::Core::uint16_t GetFragmentOffset() const;

		const Elysium::Core::uint8_t GetTimeToLive() const;

		const InternetProtocolNumber GetProtocol() const;

		const Elysium::Core::uint16_t GetChecksum() const;

		const Elysium::Core::uint16_t GetSourceIPAddress() const;

		const Elysium::Core::uint16_t GetDestrinationIPAddress() const;
	private:
		Elysium::Core::byte _Data[MINIMUMHEADERSIZE];

		//const Elysium::Core::uint16_t ComputeChecksum(const Elysium::Core::byte* Buffer, size_t Length);
		//void ValidateChecksum(const Elysium::Core::byte* Buffer, size_t Length, const Elysium::Core::uint16_t Checksum);
	};
}
#endif
