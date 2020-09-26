/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPSTATUSCODE
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPSTATUSCODE

#ifdef _MSC_VER
#pragma once
#endif

#ifndef ELYSIUM_CORE_INTEGER
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Integer.hpp"
#endif

namespace Elysium::Communication::Service::Ftp
{
#if defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)
	enum class FtpStatusCode : Elysium::Core::uint32_t
#elif defined(__ANDROID__)
	enum class FtpStatusCode
#else
#error "undefined os"
#endif
	{
		// specific implementation values
		Undefined = 0,

		// positive preliminary reply
		ActionInitiated = 100,
		RestartMarker = 110,
		ServiceTemporarilyNotAvailable = 120,
		DataAlreadyOpen = 125,
		OpeningData = 150,

		// positive completion reply
		CommandOK = 200,
		CommandExtraneous = 202,
		SystemStatus = 211,
		DirectoryStatus = 212,
		FileStatus = 213,
		HelpMessage = 214,
		SystemType = 215,
		SendUserCommand = 220,
		ClosingControl = 221,
		DataConnectionOpen = 225,
		ClosingData = 226,
		EnteringPassive = 227,
		EnteringLongPassiveMode = 228,
		EnteringExtendedPasstiveMode = 229,
		LoggedInProceed = 230,
		UserLoggedOut = 231,
		LogoutCommandNoted = 232,
		ServerWantsSecureSession = 234,
		FileActionOK = 250,
		PathnameCreated = 257,

		// positive intermediate reply
		CommandAcceptedButRequestOnHold = 300,
		SendPasswordCommand = 331,
		NeedLoginAccount = 332,
		FileCommandPending = 350,

		// transient negative completion reply
		TemporaryError = 400,
		ServiceNotAvailable = 421,
		CantOpenData = 425,
		ConnectionClosed = 426,
		InvalidUsernameOrPassword = 430,
		RequestedHostUInavailable = 434,
		ActionNotTakenFileUnavailableOrBusy = 450,
		ActionAbortedLocalProcessingError = 451,
		ActionNotTakenInsufficientSpace = 452,

		// permanent negative completion reply
		CommandSyntaxError = 500,
		ArgumentSyntaxError = 501,
		CommandNotImplemented = 502,
		BadCommandSequence = 503,
		CommandNotImplementedForThatParameter = 504,
		NotLoggedIn = 530,
		AccountNeeded = 532,
		SslRequired = 534,
		ActionNotTakenFileUnavailable = 550,
		ActionAbortedUnknownPageType = 551,
		FileActionAborted = 552,
		ActionNotTakenFilenameNotAllowed = 553,

		// protected reply
		IntegrityProtected = 631,
		ConfidentialityAndIntegrityProtected = 632,
		CondifentialityProtected = 633,
	};
}
#endif
