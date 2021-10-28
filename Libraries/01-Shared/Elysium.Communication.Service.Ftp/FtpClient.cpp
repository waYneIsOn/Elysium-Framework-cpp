#include "FtpClient.hpp"

#ifndef ELYSIUM_CORE_CONVERT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/Convert.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_IPADDRESS
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/IPAddress.hpp"
#endif

#ifndef ELYSIUM_CORE_NET_IPENDPOINT
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core.Net/IPEndPoint.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPEXCEPTION
#include "FtpException.hpp"
#endif

#ifndef ELYSIUM_CORE_NOTIMPLEMENTEDEXCEPTION
#include "../../../../Elysium-Core/Libraries/01-Shared/Elysium.Core/NotImplementedException.hpp"
#endif

Elysium::Communication::Service::Ftp::FtpClient::FtpClient(const Protocol::InternetLayer::InternetProtocolVersion IPVersion)
	: _ControlTransport(Transport::TcpClient(IPVersion)), _ControlProtocol(Protocol::ApplicationLayer::FileTransferProtocol(_ControlTransport)),
	_DataTransport(Transport::TcpClient(IPVersion)), _DataProtocol(Protocol::ApplicationLayer::FileTransferProtocol(_DataTransport))
{ }
Elysium::Communication::Service::Ftp::FtpClient::~FtpClient()
{ }

void Elysium::Communication::Service::Ftp::FtpClient::Connect(const FtpEncryption DesiredEncryption, const Elysium::Core::Net::EndPoint & RemoteEndPoint)
{
	_ControlTransport.Connect(RemoteEndPoint);

	if (DesiredEncryption == FtpEncryption::ImplicitTls)
	{	// ToDo
		throw 1;
	}

	// read the welcome message
	Elysium::Communication::Service::Ftp::FtpResponseMessage WelcomeMessage = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.ReadWelcomeMessage());
	if (!WelcomeMessage.GetIsSuccesful())
	{
		throw FtpException(WelcomeMessage);
	}

	if (DesiredEncryption == FtpEncryption::ExplicitTls || DesiredEncryption == FtpEncryption::ExplicitTlsIfAvailable)
	{
		// try to upgrade to tls
		Elysium::Communication::Service::Ftp::FtpResponseMessage AuthTlsResponse = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteAuth(u8"TLS"));
		if (AuthTlsResponse.GetIsSuccesful())
		{	// ToDo
			throw 1;
		}
		else
		{
			// try to at least upgrade to ssl
			Elysium::Communication::Service::Ftp::FtpResponseMessage AuthSslResponse = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteAuth(u8"SSL"));
			if (AuthSslResponse.GetIsSuccesful())
			{	// ToDo
				throw 1;
			}
			else if(DesiredEncryption == FtpEncryption::ExplicitTls)
			{
				throw FtpException(Elysium::Core::String(u8"Server does not support SSL/TLS."));
			}
		}
	}
}
void Elysium::Communication::Service::Ftp::FtpClient::Disconnect()
{
	_ControlProtocol.WriteQuit();
	_ControlTransport.Close();
}

void Elysium::Communication::Service::Ftp::FtpClient::Login(const Elysium::Core::String & Username, const Elysium::Core::String & Password)
{
	Elysium::Communication::Service::Ftp::FtpResponseMessage UserResponse = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteUser(Username));
	if (!UserResponse.GetIsSuccesful())
	{
		throw FtpException(UserResponse);
	}

	Elysium::Communication::Service::Ftp::FtpResponseMessage PassResponse = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WritePass(Password));
	if (!PassResponse.GetIsSuccesful())
	{
		throw FtpException(PassResponse);
	}
	
	// inform the server about the client being used
	Elysium::Communication::Service::Ftp::FtpResponseMessage ClientInfoResponse = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteClnt(Elysium::Core::String(u8"Elysium Ftp Client")));
	if (!ClientInfoResponse.GetIsSuccesful())
	{
		throw FtpException(ClientInfoResponse);
	}
	
	// print root directory
	Elysium::Communication::Service::Ftp::FtpResponseMessage PWDResponse = PrintWorkingDirectory();
	if (!PWDResponse.GetIsSuccesful())
	{
		throw FtpException(PWDResponse);
	}
	
	// set transfer-mode to image/binary
	Elysium::Communication::Service::Ftp::FtpResponseMessage TransferModeResponse = SetTransferMode(FtpTransferMode::ImageBinary);
	if (!TransferModeResponse.GetIsSuccesful())
	{
		throw FtpException(TransferModeResponse);
	}
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::GetHostInformation()
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteHost());
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::GetAccountInformation()
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteAcct());
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::GetAvailableSpace()
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteAvbl());
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::GetSystemType()
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteSyst());
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::GetSystemFeatures()
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteFeat());
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::GetHelp(const Elysium::Core::String & Command)
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteHelp(Command));
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::SetTransferMode(const FtpTransferMode TransferMode)
{
	static const Elysium::Core::String ASCII = Elysium::Core::String(u8"A");
	static const Elysium::Core::String ImageBinary = Elysium::Core::String(u8"I");

	switch (TransferMode)
	{
	case FtpTransferMode::ASCII:
		return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteType(ASCII));
	case FtpTransferMode::ImageBinary:
		return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteType(ImageBinary));
	default:
		throw Elysium::Core::NotImplementedException(Elysium::Core::String(u8"Unhandled FtpTransferMode."));
	}
}

void Elysium::Communication::Service::Ftp::FtpClient::EnterPassiveMode()
{
	Elysium::Communication::Service::Ftp::FtpResponseMessage Response = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WritePasv());
	if (!Response.GetIsSuccesful())
	{
		throw FtpException(Response);
	}

	OpenDataConnection(Response);
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::PrintWorkingDirectory()
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WritePwd());
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::ChangeWorkingDirectory(const Elysium::Core::String & Value)
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteCwd(Value));
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::ChangeToParentDirectory()
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteCdup());
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::MakeDirectory(const Elysium::Core::String & Value)
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteMkd(Value));
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::DeleteDirectory(const Elysium::Core::String & Value)
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteRmd(Value));
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::ListResourceInformation(const Elysium::Core::String& Value)
{
	return _ControlProtocol.WriteList(Value, _DataProtocol);
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::ListNamedDirectoryInformation(const Elysium::Core::String & Value)
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteMlsd(Value, _DataProtocol));
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::ListNamedFileInformation(const Elysium::Core::String & Value)
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteMlst(Value, _DataProtocol));
}

const Elysium::Communication::Service::Ftp::FtpResponseMessage Elysium::Communication::Service::Ftp::FtpClient::ListResourceNames(const Elysium::Core::String & Value)
{
	return Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteNlst(Value, _DataProtocol));
}

void Elysium::Communication::Service::Ftp::FtpClient::DownloadFile(const Elysium::Core::String & Value, Elysium::Core::IO::Stream & TargetStream)
{
	Elysium::Communication::Service::Ftp::FtpResponseMessage ResponseMessage = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteRetr(Value));
	if (!ResponseMessage.GetIsSuccesful())
	{
		throw FtpException(ResponseMessage);
	}

	_DataTransport.GetInputStream().CopyTo(TargetStream);
	//_DataTransport.Close();

	Elysium::Communication::Service::Ftp::FtpResponseMessage ResponseMessage2 = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.ReadLine());
	if (!ResponseMessage2.GetIsSuccesful())
	{
		throw FtpException(ResponseMessage);
	}
}

void Elysium::Communication::Service::Ftp::FtpClient::UploadFile(const Elysium::Core::String & Value, Elysium::Core::IO::Stream & SourceStream)
{
	Elysium::Communication::Service::Ftp::FtpResponseMessage ResponseMessage = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.WriteStor(Value));
	if (!ResponseMessage.GetIsSuccesful())
	{
		throw FtpException(ResponseMessage);
	}

	SourceStream.CopyTo(_DataTransport.GetOutputStream());
	_DataTransport.Close();
	
	Elysium::Communication::Service::Ftp::FtpResponseMessage ResponseMessage2 = Elysium::Communication::Service::Ftp::FtpResponseMessage(_ControlProtocol.ReadLine());
	if (!ResponseMessage2.GetIsSuccesful())
	{
		throw FtpException(ResponseMessage);
	}
}

void Elysium::Communication::Service::Ftp::FtpClient::OpenDataConnection(const FtpResponseMessage & ResponseMessage)
{
	const Elysium::Core::String& Message = ResponseMessage.GetContent();

	const size_t StartIndex = Message.IndexOf('(') + 1;
	const size_t EndIndex = Message.IndexOf(')');
	const Elysium::Core::StringView IpAddresView = Elysium::Core::StringView(&Message[StartIndex], EndIndex - StartIndex - 1);

	size_t StartIndexIpPart = 0;
	size_t EndIndexIpPart = IpAddresView.IndexOf(',', StartIndexIpPart);
	const Elysium::Core::uint8_t IpPart1 = Elysium::Core::Convert::ToInt32(&IpAddresView[StartIndexIpPart], EndIndexIpPart - StartIndexIpPart, 10);

	StartIndexIpPart = EndIndexIpPart + 1;
	EndIndexIpPart = StartIndexIpPart + IpAddresView.IndexOf(',', StartIndexIpPart);
	const Elysium::Core::uint8_t IpPart2 = Elysium::Core::Convert::ToInt32(&IpAddresView[StartIndexIpPart], EndIndexIpPart - StartIndexIpPart, 10);

	StartIndexIpPart = EndIndexIpPart + 1;
	EndIndexIpPart = StartIndexIpPart + IpAddresView.IndexOf(',', StartIndexIpPart);
	const Elysium::Core::uint8_t IpPart3 = Elysium::Core::Convert::ToInt32(&IpAddresView[StartIndexIpPart], EndIndexIpPart - StartIndexIpPart, 10);

	StartIndexIpPart = EndIndexIpPart + 1;
	EndIndexIpPart = StartIndexIpPart + IpAddresView.IndexOf(',', StartIndexIpPart);
	const Elysium::Core::uint8_t IpPart4 = Elysium::Core::Convert::ToInt32(&IpAddresView[StartIndexIpPart], EndIndexIpPart - StartIndexIpPart, 10);

	StartIndexIpPart = EndIndexIpPart + 1;
	EndIndexIpPart = StartIndexIpPart + IpAddresView.IndexOf(',', StartIndexIpPart);
	const Elysium::Core::uint8_t PortPart1 = Elysium::Core::Convert::ToUInt8(&IpAddresView[StartIndexIpPart], 10);

	StartIndexIpPart = EndIndexIpPart + 1;
	EndIndexIpPart = StartIndexIpPart + IpAddresView.IndexOf(',', StartIndexIpPart);
	const Elysium::Core::uint8_t PortPart2 = Elysium::Core::Convert::ToUInt8(&IpAddresView[StartIndexIpPart], 10);

	const Elysium::Core::uint32_t IpAddress = (IpPart1 << 24) + (IpPart2 << 16) + (IpPart3 << 8) + IpPart4;
	const Elysium::Core::uint16_t Port = (PortPart1 << 8) + PortPart2;
	const Elysium::Core::Net::IPAddress RemoteIpAddress = Elysium::Core::Net::IPAddress(IpAddress);
	const Elysium::Core::Net::IPEndPoint RemoteEndPoint = Elysium::Core::Net::IPEndPoint(RemoteIpAddress, Port);

	// no need to disconnect (TcpClient will handle this!)
	_DataTransport.Connect(RemoteEndPoint);
}
