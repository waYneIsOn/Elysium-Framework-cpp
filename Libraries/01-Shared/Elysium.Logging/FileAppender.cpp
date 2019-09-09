#include "FileAppender.hpp"

Elysium::Logging::Appender::FileAppender::FileAppender(const Elysium::Core::String & FullFilePath)
	: Elysium::Logging::IAppender(),
	_Formats(std::map<Events::LogLevel, Elysium::Core::String>()),
	_DefaultEncoding(Elysium::Core::Text::Encoding::Default()),
	_FileStream(Elysium::Core::IO::FileStream(FullFilePath, Elysium::Core::IO::FileMode::Create, Elysium::Core::IO::FileAccess::Write))
{
	_Formats[Events::LogLevel::Trace] = L"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
	_Formats[Events::LogLevel::Debug] = L"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
	_Formats[Events::LogLevel::Information] = L"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
	_Formats[Events::LogLevel::Warning] = L"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
	_Formats[Events::LogLevel::Error] = L"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
	_Formats[Events::LogLevel::Critical] = L"[{Timestamp} {Level}] {Message} [{Exception}]{NewLine}";
}
Elysium::Logging::Appender::FileAppender::~FileAppender()
{
}

const Elysium::Core::String & Elysium::Logging::Appender::FileAppender::GetTraceFormat() const
{
	return _Formats.at(Events::LogLevel::Trace);
}
const Elysium::Core::String & Elysium::Logging::Appender::FileAppender::GetDebugFormat() const
{
	return _Formats.at(Events::LogLevel::Debug);
}
const Elysium::Core::String & Elysium::Logging::Appender::FileAppender::GetInformationFormat() const
{
	return _Formats.at(Events::LogLevel::Information);
}
const Elysium::Core::String & Elysium::Logging::Appender::FileAppender::GetWarningFormat() const
{
	return _Formats.at(Events::LogLevel::Warning);
}
const Elysium::Core::String & Elysium::Logging::Appender::FileAppender::GetErrorFormat() const
{
	return _Formats.at(Events::LogLevel::Error);
}
const Elysium::Core::String & Elysium::Logging::Appender::FileAppender::GetCriticalFormat() const
{
	return _Formats.at(Events::LogLevel::Critical);
}

void Elysium::Logging::Appender::FileAppender::SetTraceFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Trace] = Format;
}
void Elysium::Logging::Appender::FileAppender::SetDebugFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Debug] = Format;
}
void Elysium::Logging::Appender::FileAppender::SetInformationFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Information] = Format;
}
void Elysium::Logging::Appender::FileAppender::SetWarningFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Warning] = Format;
}
void Elysium::Logging::Appender::FileAppender::SetErrorFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Error] = Format;
}
void Elysium::Logging::Appender::FileAppender::SetCriticalFormat(const Elysium::Core::String & Format)
{
	_Formats[Events::LogLevel::Critical] = Format;
}

void Elysium::Logging::Appender::FileAppender::Write(const Events::LogEvent & Event)
{
	// ToDo: use formatted message
	const Elysium::Core::String& Message = Event.GetMessage();
	const size_t MessageSize = Message.GetLength();

#ifdef UNICODE
	Elysium::Core::Collections::Generic::List<Elysium::Core::byte> OutputBytes = _DefaultEncoding->GetBytes(Message, (size_t)0, MessageSize);
	_FileStream.Write(&OutputBytes[0], OutputBytes.GetCount());
#else
	//std::cout << Event.GetMessage().GetCharArray();
#endif
}
