/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_LDAP_LDAPMESSAGETYPE
#define ELYSIUM_COMMUNICATION_SERVICE_LDAP_LDAPMESSAGETYPE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Service::LDAP
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class LDAPMessageType : Elysium::Core::uint32_t
#elif defined(__ANDROID__)
	enum class LDAPMessageType
#else
#error "undefined os"
#endif
	{
		BindRequest = 0,
		BindResponse = 1,
		UnBindRequest = 2,
		SearchREquest = 3,
		SearchResultEntry = 4,
		SearchResultDone = 5,
		ModifyRequest = 6,
		ModifyResponse = 7,
		AddRequest = 8,
		AddResponse = 9,
		DeleteRequest = 10,
		DeleteResponse = 11,
		ModifyDNRequest = 12,
		ModifyDNResponse = 13,
		CompareRequest = 14,
		CompareResponse = 15,
		AbandonRequest = 16,

		SearchResultReference = 19,

		ExtendedRequest = 23,
		ExtendedResponse = 24,
};
}
#endif
