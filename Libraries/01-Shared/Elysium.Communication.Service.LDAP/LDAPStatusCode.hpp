/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_LDAP_LDAPSTATUSCODE
#define ELYSIUM_COMMUNICATION_SERVICE_LDAP_LDAPSTATUSCODE

#ifndef _STDINT
#include <stdint.h>
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace LDAP
			{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
				enum class LDAPStatusCode : uint32_t
#elif defined(__ANDROID__)
				enum class LDAPStatusCode
#else
#error "undefined os"
#endif
				{
					Success = 0,
					OperationsError = 1,
					ProtocolError = 2,
					TimeLimitExceeded = 3,
					SizeLimitExceeded = 4,
					CompareFalse = 5,
					CompareTrue = 6,
					AuthMethodNotSupported = 7,
					StrongerAuthRequired = 8,
					// 9 is reserved
					Referral = 10,
					AdminLimitExceeded = 11,
					UnavilableCriticalExtension = 12,
					ConfidentialityRequired = 13,
					SaslBindInProgress = 14,
					// 15 ...
					NoSuchAttribute = 16,
					UndefinedAttributeType = 17,
					InappropriateMatching = 18,
					ConstraintViolation = 19,
					AttributeOrValueExists = 20,
					InvalidAttributeSyntax = 21,
					// 22 - 31 unused
					NoSuchObject = 32,
					AliasProblem = 33,
					InvalidDNSyntax = 34,
					// 35 is reserved for undefined IsLeaf
					AliasDereferencingProblem = 36,
					// 37 - 47 unused
					InappropriateAuthentication = 48,
					InvalidCredentials = 49,
					InsufficientAccessRights = 50,
					Busy = 51,
					Unavailable = 52,
					UnwillingToPerform = 53,
					LoopDetect = 54,
					// 55 - 63 unused
					NamingViolation = 64,
					ObjectClassViolation = 65,
					NotAllowedOnNonLeaf = 66,
					NotAllowedOnRDN = 67,
					EntryAlreadyExists = 68,
					ObjectClassModsProhibited = 69,
					// 70 reserved for CLDAP
					AffectsMultipleDSAs = 71,
					// 72 - 79 unused
					Other = 80
				};
			}
		}
	}
}
#endif
