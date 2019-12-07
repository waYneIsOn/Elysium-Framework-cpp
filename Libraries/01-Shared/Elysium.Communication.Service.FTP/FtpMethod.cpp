#include "FtpMethod.hpp"

#ifndef _TYPE_TRAITS_
#include <type_traits>
#endif

const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AbortActiveFileTransfer = Elysium::Communication::Service::FTP::FtpMethod(u"ABOR");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AccountInformation = Elysium::Communication::Service::FTP::FtpMethod(u"ACCT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AuthenticationSecurityData = Elysium::Communication::Service::FTP::FtpMethod(u"ADAT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Allocate = Elysium::Communication::Service::FTP::FtpMethod(u"ALLO");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Append = Elysium::Communication::Service::FTP::FtpMethod(u"APPE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Authenticate = Elysium::Communication::Service::FTP::FtpMethod(u"AUTH");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ClearCommandChannel = Elysium::Communication::Service::FTP::FtpMethod(u"CCC");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ChangeToParentDirectory = Elysium::Communication::Service::FTP::FtpMethod(u"CDUP");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Confidential = Elysium::Communication::Service::FTP::FtpMethod(u"CONF");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ChangeWorkingDirectory = Elysium::Communication::Service::FTP::FtpMethod(u"CWD");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_DeleteFile = Elysium::Communication::Service::FTP::FtpMethod(u"DELE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_PrivacyProtectedChannel = Elysium::Communication::Service::FTP::FtpMethod(u"ENC");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ExtendedAddressAndPort = Elysium::Communication::Service::FTP::FtpMethod(u"EPRT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_EnterExtendedPassiveMode = Elysium::Communication::Service::FTP::FtpMethod(u"EPSV");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_FeatureList = Elysium::Communication::Service::FTP::FtpMethod(u"FEAT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Help = Elysium::Communication::Service::FTP::FtpMethod(u"HELP");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Host = Elysium::Communication::Service::FTP::FtpMethod(u"HOST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_LanguageNegotiation = Elysium::Communication::Service::FTP::FtpMethod(u"LANG");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ListDirectoryInformation = Elysium::Communication::Service::FTP::FtpMethod(u"LIST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_LongAddressAndPort = Elysium::Communication::Service::FTP::FtpMethod(u"LPRT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_EnterLongPassiveMode = Elysium::Communication::Service::FTP::FtpMethod(u"LPSV");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_LastModifiedOfFile = Elysium::Communication::Service::FTP::FtpMethod(u"MDTM");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ModifyCreationTimeOfFile = Elysium::Communication::Service::FTP::FtpMethod(u"MFCT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ModifyFact = Elysium::Communication::Service::FTP::FtpMethod(u"MFF");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ModifyLastModificationTimeOfFile = Elysium::Communication::Service::FTP::FtpMethod(u"MFMT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_IntegrityProtectedCommand = Elysium::Communication::Service::FTP::FtpMethod(u"MIC");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_MakeDirectory = Elysium::Communication::Service::FTP::FtpMethod(u"MKD");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ListContentOfNamedDirectory = Elysium::Communication::Service::FTP::FtpMethod(u"MLSD");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod(u"MLST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_TransferMode = Elysium::Communication::Service::FTP::FtpMethod(u"MODE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ListFilesInDirectory = Elysium::Communication::Service::FTP::FtpMethod(u"NLST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_NoOperation = Elysium::Communication::Service::FTP::FtpMethod(u"NOOP");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SelectFeatureOption = Elysium::Communication::Service::FTP::FtpMethod(u"OPTS");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AuthenticationPassword = Elysium::Communication::Service::FTP::FtpMethod(u"PASS");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_EnterPassiveMode = Elysium::Communication::Service::FTP::FtpMethod(u"PASV");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ProtectionBufferSize = Elysium::Communication::Service::FTP::FtpMethod(u"PBSZ");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Port = Elysium::Communication::Service::FTP::FtpMethod(u"PORT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_DataChannelProtectionLevel = Elysium::Communication::Service::FTP::FtpMethod(u"PROT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_PrintWorkingDirectory = Elysium::Communication::Service::FTP::FtpMethod(u"PWD");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_Disconnect = Elysium::Communication::Service::FTP::FtpMethod(u"QUIT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ReinitializeConnection = Elysium::Communication::Service::FTP::FtpMethod(u"REIN");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_RestartTransferFromSpecifiedPoint = Elysium::Communication::Service::FTP::FtpMethod(u"REST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_RetrieveCopyOfFile = Elysium::Communication::Service::FTP::FtpMethod(u"RETR");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_RemoveDirectory = Elysium::Communication::Service::FTP::FtpMethod(u"RMD");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_RenameFrom = Elysium::Communication::Service::FTP::FtpMethod(u"RNFR");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_RenameTo = Elysium::Communication::Service::FTP::FtpMethod(u"RNTO");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SiteSpecificCommando = Elysium::Communication::Service::FTP::FtpMethod(u"SITE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SizeOfFile = Elysium::Communication::Service::FTP::FtpMethod(u"SIZE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_MountFileStructure = Elysium::Communication::Service::FTP::FtpMethod(u"SMNT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_UseSinglePortPassiveMode = Elysium::Communication::Service::FTP::FtpMethod(u"SPSV");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_CurrentStatus = Elysium::Communication::Service::FTP::FtpMethod(u"STAT");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AcceptDataAndStoreAsFile = Elysium::Communication::Service::FTP::FtpMethod(u"STOR");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_StoreFileUniquely = Elysium::Communication::Service::FTP::FtpMethod(u"STOU");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SetFileTransferStructure = Elysium::Communication::Service::FTP::FtpMethod(u"STRU");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SystemType = Elysium::Communication::Service::FTP::FtpMethod(u"SYST");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SetTransferMode = Elysium::Communication::Service::FTP::FtpMethod(u"TYPE");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_AuthenticationUser = Elysium::Communication::Service::FTP::FtpMethod(u"USER");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ChangeParentOfCurrentWOrkingDirectory = Elysium::Communication::Service::FTP::FtpMethod(u"XCUP");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod(u"XMKD");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod(u"XPWD");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod(u"XRCP");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod(u"XRMD");
//const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_ = Elysium::Communication::Service::FTP::FtpMethod(u"XRSQ");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SendMail = Elysium::Communication::Service::FTP::FtpMethod(u"XSEM");
const Elysium::Communication::Service::FTP::FtpMethod Elysium::Communication::Service::FTP::FtpMethod::_SendToTerminal = Elysium::Communication::Service::FTP::FtpMethod(u"XSEN");

Elysium::Communication::Service::FTP::FtpMethod::FtpMethod(const Elysium::Core::String & Method)
	: _Method(Elysium::Core::String(Method))
{
}
Elysium::Communication::Service::FTP::FtpMethod::FtpMethod(const FtpMethod & Source)
	: _Method(Elysium::Core::String(Source._Method))
{
}
Elysium::Communication::Service::FTP::FtpMethod::FtpMethod(FtpMethod && Right) noexcept
	: _Method(u"")
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
