/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPSTATUSCODE
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPSTATUSCODE

#ifndef _STDINT
#include <stdint.h>
#endif

namespace Elysium
{
	namespace Communication
	{
		namespace Service
		{
			namespace FTP
			{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
				enum class FtpStatusCode : uint32_t
#elif defined(__ANDROID__)
				enum class FtpStatusCode
#else
#error "undefined os"
#endif
				{
					// specific implementation values
					Undefined = 0,

					// positive preliminary reply
					RestartMarker = 110,
					ServiceTemporarilyNotAvailable = 120,
					DataAlreadyOpen = 125,
					OpeningData = 150,

					// positive completion reply
					CommandOK = 200,
					CommandExtraneous = 202,
					DirectoryStatus = 212,
					FileStatus = 213,
					SystemType = 215,
					SendUserCommand = 220,
					ClosingControl = 221,
					ClosingData = 226,
					EnteringPassive = 227,
					LoggedInProceed = 230,
					ServerWantsSecureSession = 234,
					FileActionOK = 250,
					PathnameCreated = 257,

					// positive intermediate reply
					SendPasswordCommand = 331,
					NeedLoginAccount = 332,
					FileCommandPending = 350,

					// transient negative completion reply
					ServiceNotAvailable = 421,
					CantOpenData = 425,
					ConnectionClosed = 426,
					ActionNotTakenFileUnavailableOrBusy = 450,
					ActionAbortedLocalProcessingError = 451,
					ActionNotTakenInsufficientSpace = 452,

					// permanent negative completion reply
					CommandSyntaxError = 500,
					ArgumentSyntaxError = 501,
					CommandNotImplemented = 502,
					BadCommandSequence = 503,
					NotLoggedIn = 530,
					AccountNeeded = 532,
					ActionNotTakenFileUnavailable = 550,
					ActionAbortedUnknownPageType = 551,
					FileActionAborted = 552,
					ActionNotTakenFilenameNotAllowed = 553,

					// protected reply
				};
			}
		}
	}
}
#endif
