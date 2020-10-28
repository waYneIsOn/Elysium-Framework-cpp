/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_ICMPV4HEADER
#define ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_ICMPV4HEADER

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "API.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_PROTOCOL_INTERNETLAYER_ICMPTYPE
#include "IcmpType.hpp"
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

#ifndef ELYSIUM_CORE_BYTE
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Byte.hpp"
#endif

namespace Elysium::Communication::Protocol::InternetLayer
{
	class ELYSIUM_COMMUNICATION_API IcmpV4Header final
	{
	public:
		IcmpV4Header();
		IcmpV4Header(const IcmpV4Header& Source) = delete;
		IcmpV4Header(IcmpV4Header&& Right) noexcept = delete;
		~IcmpV4Header();

		IcmpV4Header& operator=(const IcmpV4Header& Source) = delete;
		IcmpV4Header& operator=(IcmpV4Header&& Right) noexcept = delete;

		static constexpr Elysium::Core::uint8_t HEADERSIZE = 8;
		static constexpr Elysium::Core::uint8_t MAXIMUMPACKETSIZE = 8 + 576;

		const IcmpType GetType() const;

		const Elysium::Core::uint8_t GetCode() const;

		const Elysium::Core::uint16_t GetChecksum() const;

		const Elysium::Core::uint32_t GetRestOfHeader() const;

		void SetType(const IcmpType Value);

		void SetCode(const Elysium::Core::uint8_t Value);

		void SetRestOfHeader(const Elysium::Core::uint32_t Value);

		void ComputeAndSetChecksum(const Elysium::Core::uint8_t NumberOfBytes);
	private:
		Elysium::Core::byte _Data[HEADERSIZE];

		static const bool IsValidCode(const IcmpType Type, const Elysium::Core::uint8_t Code);
	};
}
#endif
