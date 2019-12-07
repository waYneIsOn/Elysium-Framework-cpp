/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_AUTHENTICATIONHEADERVALUE
#define ELYSIUM_COMMUNICATION_SERVICE_HTTP_HEADERS_AUTHENTICATIONHEADERVALUE

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace Http
			{
				namespace Headers
				{
					class ELYSIUM_COMMUNICATION_API AuthenticationHeaderValue final
					{
					public:
						AuthenticationHeaderValue(const Elysium::Core::String& Scheme);
						AuthenticationHeaderValue(const Elysium::Core::String& Scheme, const Elysium::Core::String& Parameter);
						AuthenticationHeaderValue(const AuthenticationHeaderValue& Value) = delete;
						AuthenticationHeaderValue(AuthenticationHeaderValue&& Right) noexcept = delete;
						~AuthenticationHeaderValue();

						AuthenticationHeaderValue& operator=(const AuthenticationHeaderValue& Source) = delete;
						AuthenticationHeaderValue& operator=(AuthenticationHeaderValue&& Right) noexcept = delete;

						// relational operators
						bool operator==(const AuthenticationHeaderValue& Other);
						bool operator!=(const AuthenticationHeaderValue& Other);

						const Elysium::Core::String& GetScheme() const;
						const Elysium::Core::String& GetParameter() const;

						void SetScheme(const Elysium::Core::String& Value);
						void SetParameter(const Elysium::Core::String& Value);
					private:
						Elysium::Core::String _Scheme;
						Elysium::Core::String _Parameter;
					};
				}
			}
		}
	}
}
#endif
