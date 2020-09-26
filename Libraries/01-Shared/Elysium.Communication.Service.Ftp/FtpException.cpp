#include "FtpException.hpp"

Elysium::Communication::Service::Ftp::FtpException::FtpException(const FtpResponseMessage & Response)
	: Elysium::Core::Exception(u8"FtpException")
{ }
Elysium::Communication::Service::Ftp::FtpException::~FtpException()
{ }
