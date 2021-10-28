#include "FtpServer.hpp"

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPREQUESTMESSAGE
#include "FtpRequestMessage.hpp"
#endif

#ifndef ELYSIUM_COMMUNICATION_SERVICE_FTP_FTPRESPONSESTATUSCODE
#include "FtpResponseStatusCode.hpp"
#endif

Elysium::Communication::Service::Ftp::FtpServer::FtpServer(const Protocol::InternetLayer::InternetProtocolVersion IPVersion)
	: _ControlTransport(Transport::TcpListener(IPVersion)), _ControlProtocol(Protocol::ApplicationLayer::FileTransferProtocol(_ControlTransport)),
	_ShouldStop(false), _AcceptResetEvent(false)
{ }
Elysium::Communication::Service::Ftp::FtpServer::~FtpServer()
{ }

void Elysium::Communication::Service::Ftp::FtpServer::Start(const Elysium::Core::Net::EndPoint & LocalEndPoint, const Elysium::Core::int32_t Backlog)
{
	_ControlTransport.Start(LocalEndPoint, Backlog);
	
	while (!_ShouldStop)
	{
		_AcceptResetEvent.Reset();
		const Elysium::Core::IAsyncResult* AcceptResult = _ControlTransport.BeginAcceptTcpClient(
			Elysium::Core::Delegate<void, const Elysium::Core::IAsyncResult*>::Bind<FtpServer, &FtpServer::TcpClientAcceptCallback>(*this), nullptr);
		_AcceptResetEvent.WaitOne();
		delete AcceptResult;
	}
}

void Elysium::Communication::Service::Ftp::FtpServer::Stop()
{
	_ShouldStop = true;
	_AcceptResetEvent.Set();

	_ControlTransport.Stop();

	// ToDo: EndXYZ(...), disconnect clients gracefully (control and data) etc.
}

void Elysium::Communication::Service::Ftp::FtpServer::TcpClientAcceptCallback(const Elysium::Core::IAsyncResult * Result)
{
	const Elysium::Communication::Transport::TcpClient Client = _ControlTransport.EndAcceptTcpClient(Result);
	_AcceptResetEvent.Set();

	// send welcome message
	// ToDo: begin send
	Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol ClientControlProtocol =
		Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol((Elysium::Communication::Transport::TransportBase&)Client);
	ClientControlProtocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::SendUserCommand), u8" Elysium FTP Server ready...");

	// ToDo: begin receive
	ParseRequestMessage(Client, ClientControlProtocol);
	ParseRequestMessage(Client, ClientControlProtocol);
	ParseRequestMessage(Client, ClientControlProtocol);
	ParseRequestMessage(Client, ClientControlProtocol);
	ParseRequestMessage(Client, ClientControlProtocol);
	ParseRequestMessage(Client, ClientControlProtocol);
}

void Elysium::Communication::Service::Ftp::FtpServer::ParseRequestMessage(const Elysium::Communication::Transport::TcpClient & Client, Elysium::Communication::Protocol::ApplicationLayer::FileTransferProtocol& Protocol)
{
	/*
	5.1.  MINIMUM IMPLEMENTATION
	  In order to make FTP workable without needless error messages, the
	  following minimum implementation is required for all servers:

		 TYPE - ASCII Non-print
		 MODE - Stream
		 STRUCTURE - File, Record
		 COMMANDS - 
			USER, QUIT, PORT,
			TYPE, MODE, STRU,
				for the default values
			RETR, STOR,
			NOOP.

	  The default values for transfer parameters are:
		 TYPE - ASCII Non-print
		 MODE - Stream
		 STRU - File

	  All hosts must accept the above as the standard defaults.
	*/
	const FtpRequestMessage RequestMessage = Protocol.ReadLine();

	switch (RequestMessage.GetCommandType())
	{
	case FtpRequestType::User:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::SendPasswordCommand), u8" Password required for demo.");
		break;
	case FtpRequestType::Pass:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::LoggedInProceed), u8" User demo logged in.");
		break;
	case FtpRequestType::Syst:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::SystemType), u8" UNIX Type: L8");
		break;
	case FtpRequestType::Feat:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::SystemStatus), u8"-Extension supported");
		Protocol.WriteString(u8" PBSZ\r\n");
		Protocol.WriteString(u8" PROT\r\n");
		Protocol.WriteString(u8" MDTM\r\n");
		Protocol.WriteString(u8" MDTM YYYYMMDDHHMMSS;filename\r\n");
		Protocol.WriteString(u8" MFMT\r\n");
		Protocol.WriteString(u8" MFCT\r\n");
		Protocol.WriteString(u8" MFF Create;Modify;\r\n");
		Protocol.WriteString(u8" SIZE\r\n");
		Protocol.WriteString(u8" MLSD\r\n");
		Protocol.WriteString(u8" MLST type*;size*;modify*;perm*;\r\n");
		Protocol.WriteString(u8" CLNT\r\n");
		Protocol.WriteString(u8" UTF8\r\n");
		Protocol.WriteString(u8" AUTH SSL\r\n");
		Protocol.WriteString(u8" AUTH TLS\r\n");
		Protocol.WriteString(u8" OPTS\r\n");
		Protocol.WriteString(u8" STAT\r\n");
		Protocol.WriteString(u8" EPRT\r\n");
		Protocol.WriteString(u8" HELP\r\n");
		Protocol.WriteString(u8" XCRC \"filename\" SP EP\r\n");
		Protocol.WriteString(u8" SITE HELP\r\n");
		Protocol.WriteString(u8" SITE MSG messagetext\r\n");
		Protocol.WriteString(u8" SITE PSWD oldpass newpass\r\n");
		Protocol.WriteString(u8" SITE UZIP filename.zip\r\n");
		Protocol.WriteString(u8" SITE ZIP filename.zip sourcefile1||sourcefile2||sourcefile3||...\r\n");
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::SystemStatus), u8" End");
		break;
	case FtpRequestType::Clnt:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::CommandOK), u8" Noted.");
		break;
	case FtpRequestType::Opts:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::CommandOK), u8" OPTS UTF8 ON");
		break;
	case FtpRequestType::Pwd:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::PathnameCreated), u8" \"/\" is current directory.");
		break;
	case FtpRequestType::Type:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::CommandOK), u8" Type set to I");
		break;
	case FtpRequestType::Pasv:
		//KnownTcpPort.DynamicPortFirst
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::EnteringPassive), u8" Entering Passive Mode (127,0,0,1,9,141)");
		break;
	case FtpRequestType::Mlsd:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::OpeningData), u8" Opening data channel for directory list.");
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::ClosingData), u8" Transfer successful.");
		break;
	case FtpRequestType::Quit:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::CommandOK), u8" Noted.");
		break;
	default:
		Protocol.WriteResponseMessage(static_cast<Elysium::Core::uint32_t>(FtpResponseStatusCode::CommandSyntaxError), u8" Command unknown.");
		break;
	}
}
