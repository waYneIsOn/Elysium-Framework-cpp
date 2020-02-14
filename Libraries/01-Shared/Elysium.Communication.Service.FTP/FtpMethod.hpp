/*
===========================================================================

Copyright (C) 2017 waYne (CAM)

===========================================================================
*/
#pragma once

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPMETHOD
#define ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPMETHOD

#ifndef ELYSIUM_COMMUNICATION_API
#include "../Elysium.Communication/API.hpp"
#endif

#ifndef ELYSIUM_CORE_STRING
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/String.hpp"
#endif

namespace Elysium::Communication::Service::FTP
{
	class ELYSIUM_COMMUNICATION_API FtpMethod final
	{
	public:
		FtpMethod(const Elysium::Core::String& Method);
		FtpMethod(const FtpMethod& Source);
		FtpMethod(FtpMethod&& Right) noexcept;
		~FtpMethod();

		FtpMethod& operator=(const FtpMethod& Source);
		FtpMethod& operator=(FtpMethod&& Right) noexcept;

		const Elysium::Core::String& GetMethod() const;

		static const FtpMethod& AbortActiveFileTransfer();
		static const FtpMethod& AccountInformation();
		static const FtpMethod& AuthenticationSecurityData();
		static const FtpMethod& Allocate();
		static const FtpMethod& Append();
		static const FtpMethod& Authenticate();
		static const FtpMethod& ClearCommandChannel();
		static const FtpMethod& ChangeToParentDirectory();
		static const FtpMethod& Confidential();
		static const FtpMethod& ChangeWorkingDirectory();
		static const FtpMethod& DeleteFile();
		static const FtpMethod& PrivacyProtectedChannel();
		static const FtpMethod& ExtendedAddressAndPort();
		static const FtpMethod& EnterExtendedPassiveMode();
		static const FtpMethod& FeatureList();
		static const FtpMethod& Help();
		static const FtpMethod& Host();
		static const FtpMethod& LanguageNegotiation();
		static const FtpMethod& ListDirectoryInformation();
		static const FtpMethod& LongAddressAndPort();
		static const FtpMethod& EnterLongPassiveMode();
		static const FtpMethod& LastModifiedOfFile();
		static const FtpMethod& ModifyCreationTimeOfFile();
		static const FtpMethod& ModifyFact();
		static const FtpMethod& ModifyLastModificationTimeOfFile();
		static const FtpMethod& IntegrityProtectedCommand();
		static const FtpMethod& MakeDirectory();
		static const FtpMethod& ListContentOfNamedDirectory();
		//static const FtpMethod& _();	// MLST
		static const FtpMethod& TransferMode();
		static const FtpMethod& ListFilesInDirectory();
		static const FtpMethod& NoOperation();
		static const FtpMethod& SelectFeatureOption();
		static const FtpMethod& AuthenticationPassword();
		static const FtpMethod& EnterPassiveMode();
		static const FtpMethod& ProtectionBufferSize();
		static const FtpMethod& Port();
		static const FtpMethod& DataChannelProtectionLevel();
		static const FtpMethod& PrintWorkingDirectory();
		static const FtpMethod& Disconnect();
		static const FtpMethod& ReinitializeConnection();
		static const FtpMethod& RestartTransferFromSpecifiedPoint();
		static const FtpMethod& RetrieveCopyOfFile();
		static const FtpMethod& RemoveDirectory();
		static const FtpMethod& RenameFrom();
		static const FtpMethod& RenameTo();
		static const FtpMethod& SiteSpecificCommando();
		static const FtpMethod& SizeOfFile();
		static const FtpMethod& MountFileStructure();
		static const FtpMethod& UseSinglePortPassiveMode();
		static const FtpMethod& CurrentStatus();
		static const FtpMethod& AcceptDataAndStoreAsFile();
		static const FtpMethod& StoreFileUniquely();
		static const FtpMethod& SetFileTransferStructure();
		static const FtpMethod& SystemType();
		static const FtpMethod& SetTransferMode();
		static const FtpMethod& AuthenticationUser();
		static const FtpMethod& ChangeParentOfCurrentWOrkingDirectory();
		//static const FtpMethod& _();	//	XMKD
		//static const FtpMethod& _();	//	XPWD
		//static const FtpMethod& _();	//	XRCP
		//static const FtpMethod& _();	//	XRMD
		//static const FtpMethod& _();	//	XRSQ
		static const FtpMethod& SendMail();
		static const FtpMethod& SendToTerminal();
	private:
		Elysium::Core::String _Method;

		static const FtpMethod _AbortActiveFileTransfer;
		static const FtpMethod _AccountInformation;
		static const FtpMethod _AuthenticationSecurityData;
		static const FtpMethod _Allocate;
		static const FtpMethod _Append;
		static const FtpMethod _Authenticate;
		static const FtpMethod _ClearCommandChannel;
		static const FtpMethod _ChangeToParentDirectory;
		static const FtpMethod _Confidential;
		static const FtpMethod _ChangeWorkingDirectory;
		static const FtpMethod _DeleteFile;
		static const FtpMethod _PrivacyProtectedChannel;
		static const FtpMethod _ExtendedAddressAndPort;
		static const FtpMethod _EnterExtendedPassiveMode;
		static const FtpMethod _FeatureList;
		static const FtpMethod _Help;
		static const FtpMethod _Host;
		static const FtpMethod _LanguageNegotiation;
		static const FtpMethod _ListDirectoryInformation;
		static const FtpMethod _LongAddressAndPort;
		static const FtpMethod _EnterLongPassiveMode;
		static const FtpMethod _LastModifiedOfFile;
		static const FtpMethod _ModifyCreationTimeOfFile;
		static const FtpMethod _ModifyFact;
		static const FtpMethod _ModifyLastModificationTimeOfFile;
		static const FtpMethod _IntegrityProtectedCommand;
		static const FtpMethod _MakeDirectory;
		static const FtpMethod _ListContentOfNamedDirectory;
		//static const FtpMethod _;	// MLST
		static const FtpMethod _TransferMode;
		static const FtpMethod _ListFilesInDirectory;
		static const FtpMethod _NoOperation;
		static const FtpMethod _SelectFeatureOption;
		static const FtpMethod _AuthenticationPassword;
		static const FtpMethod _EnterPassiveMode;
		static const FtpMethod _ProtectionBufferSize;
		static const FtpMethod _Port;
		static const FtpMethod _DataChannelProtectionLevel;
		static const FtpMethod _PrintWorkingDirectory;
		static const FtpMethod _Disconnect;
		static const FtpMethod _ReinitializeConnection;
		static const FtpMethod _RestartTransferFromSpecifiedPoint;
		static const FtpMethod _RetrieveCopyOfFile;
		static const FtpMethod _RemoveDirectory;
		static const FtpMethod _RenameFrom;
		static const FtpMethod _RenameTo;
		static const FtpMethod _SiteSpecificCommando;
		static const FtpMethod _SizeOfFile;
		static const FtpMethod _MountFileStructure;
		static const FtpMethod _UseSinglePortPassiveMode;
		static const FtpMethod _CurrentStatus;
		static const FtpMethod _AcceptDataAndStoreAsFile;
		static const FtpMethod _StoreFileUniquely;
		static const FtpMethod _SetFileTransferStructure;
		static const FtpMethod _SystemType;
		static const FtpMethod _SetTransferMode;
		static const FtpMethod _AuthenticationUser;
		static const FtpMethod _ChangeParentOfCurrentWOrkingDirectory;
		//static const FtpMethod _MakeDirectory;	// XMKD
		//static const FtpMethod _PrintCurrentWorkingDirectory;	// XPWD
		//static const FtpMethod _;	// _XRCP
		//static const FtpMethod _RemoveDirectory;	// XRMD
		//static const FtpMethod _;	// XRSQ
		static const FtpMethod _SendMail;
		static const FtpMethod _SendToTerminal;
	};
}
#endif
