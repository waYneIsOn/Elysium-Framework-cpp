/*
===========================================================================
Copyright (c) waYne (CAM). All rights reserved.
===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_AUTHENTICATIONHEADERVALUE
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_AUTHENTICATIONHEADERVALUE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

namespace Elysium::Communication::Service::Http::Headers
{
	class ELYSIUM_COMMUNICATION_API AuthenticationHeaderValue final
	{
	public:
		AuthenticationHeaderValue(const Elysium::Core::Utf8String& Scheme);
		AuthenticationHeaderValue(const Elysium::Core::Utf8String& Scheme, const Elysium::Core::Utf8String& Parameter);
		AuthenticationHeaderValue(const AuthenticationHeaderValue& Value) = delete;
		AuthenticationHeaderValue(AuthenticationHeaderValue&& Right) noexcept = delete;
		~AuthenticationHeaderValue();

		AuthenticationHeaderValue& operator=(const AuthenticationHeaderValue& Source) = delete;
		AuthenticationHeaderValue& operator=(AuthenticationHeaderValue&& Right) noexcept = delete;

		// relational operators
		bool operator==(const AuthenticationHeaderValue& Other);
		bool operator!=(const AuthenticationHeaderValue& Other);

		const Elysium::Core::Utf8String& GetScheme() const;
		const Elysium::Core::Utf8String& GetParameter() const;

		void SetScheme(const Elysium::Core::Utf8String& Value);
		void SetParameter(const Elysium::Core::Utf8String& Value);
	private:
		Elysium::Core::Utf8String _Scheme;
		Elysium::Core::Utf8String _Parameter;
	};
}
#endif
