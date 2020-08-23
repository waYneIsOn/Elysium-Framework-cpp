#include "FtpMethod.hpp"

#ifndef _TYPE_TRAITS_
#include <type_traits>
#endif

const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AbortActiveFileTransfer = Elysium::Communication::Service::FTP::FtpMethod("ABOR");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AccountInformation = Elysium::Communication::Service::FTP::FtpMethod("ACCT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AuthenticationSecurityData = Elysium::Communication::Service::FTP::FtpMethod("ADAT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Allocate = Elysium::Communication::Service::FTP::FtpMethod("ALLO");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Append = Elysium::Communication::Service::FTP::FtpMethod("APPE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Authenticate = Elysium::Communication::Service::FTP::FtpMethod("AUTH");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ClearCommandChannel = Elysium::Communication::Service::FTP::FtpMethod("CCC");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ChangeToParentDirectory = Elysium::Communication::Service::FTP::FtpMethod("CDUP");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Confidential = Elysium::Communication::Service::FTP::FtpMethod("CONF");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ChangeWorkingDirectory = Elysium::Communication::Service::FTP::FtpMethod("CWD");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_DeleteFile = Elysium::Communication::Service::FTP::FtpMethod("DELE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_PrivacyProtectedChannel = Elysium::Communication::Service::FTP::FtpMethod("ENC");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ExtendedAddressAndPort = Elysium::Communication::Service::FTP::FtpMethod("EPRT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_EnterExtendedPassiveMode = Elysium::Communication::Service::FTP::FtpMethod("EPSV");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_FeatureList = Elysium::Communication::Service::FTP::FtpMethod("FEAT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Help = Elysium::Communication::Service::FTP::FtpMethod("HELP");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Host = Elysium::Communication::Service::FTP::FtpMethod("HOST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_LanguageNegotiation = Elysium::Communication::Service::FTP::FtpMethod("LANG");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ListDirectoryInformation = Elysium::Communication::Service::FTP::FtpMethod("LIST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_LongAddressAndPort = Elysium::Communication::Service::FTP::FtpMethod("LPRT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_EnterLongPassiveMode = Elysium::Communication::Service::FTP::FtpMethod("LPSV");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_LastModifiedOfFile = Elysium::Communication::Service::FTP::FtpMethod("MDTM");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ModifyCreationTimeOfFile = Elysium::Communication::Service::FTP::FtpMethod("MFCT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ModifyFact = Elysium::Communication::Service::FTP::FtpMethod("MFF");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ModifyLastModificationTimeOfFile = Elysium::Communication::Service::FTP::FtpMethod("MFMT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_IntegrityProtectedCommand = Elysium::Communication::Service::FTP::FtpMethod("MIC");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_MakeDirectory = Elysium::Communication::Service::FTP::FtpMethod("MKD");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ListContentOfNamedDirectory = Elysium::Communication::Service::FTP::FtpMethod("MLSD");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod("MLST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_TransferMode = Elysium::Communication::Service::FTP::FtpMethod("MODE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ListFilesInDirectory = Elysium::Communication::Service::FTP::FtpMethod("NLST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_NoOperation = Elysium::Communication::Service::FTP::FtpMethod("NOOP");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SelectFeatureOption = Elysium::Communication::Service::FTP::FtpMethod("OPTS");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AuthenticationPassword = Elysium::Communication::Service::FTP::FtpMethod("PASS");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_EnterPassiveMode = Elysium::Communication::Service::FTP::FtpMethod("PASV");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ProtectionBufferSize = Elysium::Communication::Service::FTP::FtpMethod("PBSZ");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Port = Elysium::Communication::Service::FTP::FtpMethod("PORT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_DataChannelProtectionLevel = Elysium::Communication::Service::FTP::FtpMethod("PROT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_PrintWorkingDirectory = Elysium::Communication::Service::FTP::FtpMethod("PWD");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Disconnect = Elysium::Communication::Service::FTP::FtpMethod("QUIT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ReinitializeConnection = Elysium::Communication::Service::FTP::FtpMethod("REIN");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_RestartTransferFromSpecifiedPoint = Elysium::Communication::Service::FTP::FtpMethod("REST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_RetrieveCopyOfFile = Elysium::Communication::Service::FTP::FtpMethod("RETR");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_RemoveDirectory = Elysium::Communication::Service::FTP::FtpMethod("RMD");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_RenameFrom = Elysium::Communication::Service::FTP::FtpMethod("RNFR");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_RenameTo = Elysium::Communication::Service::FTP::FtpMethod("RNTO");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SiteSpecificCommando = Elysium::Communication::Service::FTP::FtpMethod("SITE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SizeOfFile = Elysium::Communication::Service::FTP::FtpMethod("SIZE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_MountFileStructure = Elysium::Communication::Service::FTP::FtpMethod("SMNT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_UseSinglePortPassiveMode = Elysium::Communication::Service::FTP::FtpMethod("SPSV");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_CurrentStatus = Elysium::Communication::Service::FTP::FtpMethod("STAT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AcceptDataAndStoreAsFile = Elysium::Communication::Service::FTP::FtpMethod("STOR");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_StoreFileUniquely = Elysium::Communication::Service::FTP::FtpMethod("STOU");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SetFileTransferStructure = Elysium::Communication::Service::FTP::FtpMethod("STRU");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SystemType = Elysium::Communication::Service::FTP::FtpMethod("SYST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SetTransferMode = Elysium::Communication::Service::FTP::FtpMethod("TYPE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AuthenticationUser = Elysium::Communication::Service::FTP::FtpMethod("USER");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ChangeParentOfCurrentWOrkingDirectory = Elysium::Communication::Service::FTP::FtpMethod("XCUP");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod("XMKD");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod("XPWD");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod("XRCP");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod("XRMD");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod("XRSQ");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SendMail = Elysium::Communication::Service::FTP::FtpMethod("XSEM");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SendToTerminal = Elysium::Communication::Service::FTP::FtpMethod("XSEN");

Elysium::Communication::Service::FTP::FtpMethod::FtpMethod(const Elysium::Core::String & Method)
	: _Method(Elysium::Core::String(Method))
{
}
Elysium::Communication::Service::FTP::FtpMethod::FtpMethod(const FtpMethod & Source)
	: _Method(Elysium::Core::String(Source._Method))
{
}
Elysium::Communication::Service::FTP::FtpMethod::FtpMethod(FtpMethod && Right) noexcept
	: _Method("")
{
	*this = std::move(Right);
}
Elysium::Communication::Service::FTP::FtpMethod::~FtpMethod()
{
}

Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::operator=(const FtpMethod & Source)
{
	if (this != &Source)
	{
		_Method = Elysium::Core::String(Source._Method);
	}
	return *this;
}
Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::operator=(FtpMethod && Right) noexcept
{
	if (this != &Right)
	{
		_Method = std::move(Right._Method);
	}
	return *this;
}

const Elysium::Core::String & Elysium::Communication::Service::FTP::FtpMethod::GetMethod() const
{
	return _Method;
}

const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::AbortActiveFileTransfer()
{
	return _AbortActiveFileTransfer;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::AccountInformation()
{
	return _AccountInformation;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::AuthenticationSecurityData()
{
	return _AuthenticationSecurityData;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::Allocate()
{
	return _Allocate;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::Append()
{
	return _Append;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::Authenticate()
{
	return _Authenticate;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ClearCommandChannel()
{
	return _ClearCommandChannel;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ChangeToParentDirectory()
{
	return _ChangeToParentDirectory;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::Confidential()
{
	return _Confidential;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ChangeWorkingDirectory()
{
	return _ChangeWorkingDirectory;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::DeleteFile()
{
	return _DeleteFile;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::PrivacyProtectedChannel()
{
	return _PrivacyProtectedChannel;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ExtendedAddressAndPort()
{
	return _ExtendedAddressAndPort;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::EnterExtendedPassiveMode()
{
	return _EnterExtendedPassiveMode;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::FeatureList()
{
	return _FeatureList;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::Help()
{
	return _Help;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::Host()
{
	return _Host;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::LanguageNegotiation()
{
	return _LanguageNegotiation;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ListDirectoryInformation()
{
	return _ListDirectoryInformation;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::LongAddressAndPort()
{
	return _LongAddressAndPort;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::EnterLongPassiveMode()
{
	return _EnterLongPassiveMode;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::LastModifiedOfFile()
{
	return _LastModifiedOfFile;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ModifyCreationTimeOfFile()
{
	return _ModifyCreationTimeOfFile;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ModifyFact()
{
	return _ModifyFact;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ModifyLastModificationTimeOfFile()
{
	return _ModifyLastModificationTimeOfFile;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::IntegrityProtectedCommand()
{
	return _IntegrityProtectedCommand;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::MakeDirectory()
{
	return _MakeDirectory;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ListContentOfNamedDirectory()
{
	return _ListContentOfNamedDirectory;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::TransferMode()
{
	return _TransferMode;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ListFilesInDirectory()
{
	return _ListFilesInDirectory;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::NoOperation()
{
	return _NoOperation;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::SelectFeatureOption()
{
	return _SelectFeatureOption;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::AuthenticationPassword()
{
	return _AuthenticationPassword;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::EnterPassiveMode()
{
	return _EnterPassiveMode;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ProtectionBufferSize()
{
	return _ProtectionBufferSize;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::Port()
{
	return _Port;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::DataChannelProtectionLevel()
{
	return _DataChannelProtectionLevel;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::PrintWorkingDirectory()
{
	return _PrintWorkingDirectory;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::Disconnect()
{
	return _Disconnect;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ReinitializeConnection()
{
	return _ReinitializeConnection;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::RestartTransferFromSpecifiedPoint()
{
	return _RestartTransferFromSpecifiedPoint;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::RetrieveCopyOfFile()
{
	return _RetrieveCopyOfFile;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::RemoveDirectory()
{
	return _RemoveDirectory;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::RenameFrom()
{
	return _RenameFrom;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::RenameTo()
{
	return _RenameTo;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::SiteSpecificCommando()
{
	return _SiteSpecificCommando;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::SizeOfFile()
{
	return _SizeOfFile;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::MountFileStructure()
{
	return _MountFileStructure;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::UseSinglePortPassiveMode()
{
	return _UseSinglePortPassiveMode;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::CurrentStatus()
{
	return _CurrentStatus;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::AcceptDataAndStoreAsFile()
{
	return _AcceptDataAndStoreAsFile;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::StoreFileUniquely()
{
	return _StoreFileUniquely;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::SetFileTransferStructure()
{
	return _SetFileTransferStructure;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::SystemType()
{
	return _SystemType;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::SetTransferMode()
{
	return _SetTransferMode;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::AuthenticationUser()
{
	return _AuthenticationUser;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::ChangeParentOfCurrentWOrkingDirectory()
{
	return _ChangeParentOfCurrentWOrkingDirectory;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::SendMail()
{
	return _SendMail;
}
const Elysium::Communication::Service::FTP::FtpMethod & Elysium::Communication::Service::FTP::FtpMethod::SendToTerminal()
{
	return _SendToTerminal;
}
