#include "FileAppender.hpp"

Elysium::Logging::Appender::FileAppender::FileAppender(const Elysium::Core::Utf8String & FullFilePath)
	: Elysium::Logging::IAppender(),
	_Formats(std::map<Events::LogLevel, Elysium::Core::Utf8String>()),
	_Encoding(Elysium::Core::Text::Encoding::Default()),
	_FileStream(Elysium::Core::IO::FileStream(FullFilePath, Elysium::Core::IO::FileMode::Create, Elysium::Core::IO::FileAccess::Write))
{
	_Formats[Events::LogLevel::Trace] = u8"{{ \"Timestamp\": \"{Timestamp}\", \"Level\": {Level}, \"Message\": \"{Message}\", \"Exception\": \"{Exception}\" }}{NewLine}";
	_Formats[Events::LogLevel::Debug] = u8"{{ \"Timestamp\": \"{Timestamp}\", \"Level\": {Level}, \"Message\": \"{Message}\", \"Exception\": \"{Exception}\" }}{NewLine}";
	_Formats[Events::LogLevel::Information] = u8"{{ \"Timestamp\": \"{Timestamp}\", \"Level\": {Level}, \"Message\": \"{Message}\", \"Exception\": \"{Exception}\" }}{NewLine}";
	_Formats[Events::LogLevel::Warning] = u8"{{ \"Timestamp\": \"{Timestamp}\", \"Level\": {Level}, \"Message\": \"{Message}\", \"Exception\": \"{Exception}\" }}{NewLine}";
	_Formats[Events::LogLevel::Error] = u8"{{ \"Timestamp\": \"{Timestamp}\", \"Level\": {Level}, \"Message\": \"{Message}\", \"Exception\": \"{Exception}\" }}{NewLine}";
	_Formats[Events::LogLevel::Critical] = u8"{{ {\"Timestamp\": \"Timestamp}\", \"Level\": {Level}, \"Message\": \"{Message}\", \"Exception\": \"{Exception}\" }}{NewLine}";
}
Elysium::Logging::Appender::FileAppender::~FileAppender()
{
}

const Elysium::Core::Utf8String & Elysium::Logging::Appender::FileAppender::GetTraceFormat() const
{
	return _Formats.at(Events::LogLevel::Trace);
}
const Elysium::Core::Utf8String & Elysium::Logging::Appender::FileAppender::GetDebugFormat() const
{
	return _Formats.at(Events::LogLevel::Debug);
}
const Elysium::Core::Utf8String & Elysium::Logging::Appender::FileAppender::GetInformationFormat() const
{
	return _Formats.at(Events::LogLevel::Information);
}
const Elysium::Core::Utf8String & Elysium::Logging::Appender::FileAppender::GetWarningFormat() const
{
	return _Formats.at(Events::LogLevel::Warning);
}
const Elysium::Core::Utf8String & Elysium::Logging::Appender::FileAppender::GetErrorFormat() const
{
	return _Formats.at(Events::LogLevel::Error);
}
const Elysium::Core::Utf8String & Elysium::Logging::Appender::FileAppender::GetCriticalFormat() const
{
	return _Formats.at(Events::LogLevel::Critical);
}

void Elysium::Logging::Appender::FileAppender::SetTraceFormat(const Elysium::Core::Utf8String & Format)
{
	_Formats[Events::LogLevel::Trace] = Format;
}
void Elysium::Logging::Appender::FileAppender::SetDebugFormat(const Elysium::Core::Utf8String & Format)
{
	_Formats[Events::LogLevel::Debug] = Format;
}
void Elysium::Logging::Appender::FileAppender::SetInformationFormat(const Elysium::Core::Utf8String & Format)
{
	_Formats[Events::LogLevel::Information] = Format;
}
void Elysium::Logging::Appender::FileAppender::SetWarningFormat(const Elysium::Core::Utf8String & Format)
{
	_Formats[Events::LogLevel::Warning] = Format;
}
void Elysium::Logging::Appender::FileAppender::SetErrorFormat(const Elysium::Core::Utf8String & Format)
{
	_Formats[Events::LogLevel::Error] = Format;
}
void Elysium::Logging::Appender::FileAppender::SetCriticalFormat(const Elysium::Core::Utf8String & Format)
{
	_Formats[Events::LogLevel::Critical] = Format;
}

void Elysium::Logging::Appender::FileAppender::Process(const Events::LogEvent & Event)
{
	// ToDo: use formatted message
	throw 1;
	/*
	const Elysium::Core::Utf8String& Message = Event.GetMessage();
	const size_t MessageSize = Message.GetLength();

#ifdef UNICODE
	Elysium::Core::Collections::Template::Array<Elysium::Core::byte> OutputBytes = _Encoding.GetBytes(&Message[0], MessageSize);
	_FileStream.Write(&OutputBytes[0], OutputBytes.GetLength());
#else
	//std::cout << Event.GetMessage().GetCharArray();
#endif
	*/
}
