#include "LogManager.hpp"

std::mutex Elysium::Logging::LogManager::_AppenderMutex = std::mutex();
std::mutex Elysium::Logging::LogManager::_FlushableAppenderMutex = std::mutex();

std::map<Elysium::Core::String, Elysium::Logging::Logger*> Elysium::Logging::LogManager::_Logger = std::map<Elysium::Core::String, Elysium::Logging::Logger*>();

Elysium::Core::Collections::Generic::List<Elysium::Logging::IAppender*> Elysium::Logging::LogManager::_Appender = Elysium::Core::Collections::Generic::List<Elysium::Logging::IAppender*>();
Elysium::Core::Collections::Generic::List<Elysium::Logging::IFlushableAppender*> Elysium::Logging::LogManager::_FlushableAppender = Elysium::Core::Collections::Generic::List<Elysium::Logging::IFlushableAppender*>();

Elysium::Logging::LogManager::~LogManager()
{
}

const Elysium::Logging::Logger * Elysium::Logging::LogManager::GetLogger(const Elysium::Core::Reflection::Type & Type)
{
	return GetLogger(Type.GetFullName());
}
const Elysium::Logging::Logger * Elysium::Logging::LogManager::GetLogger(const Elysium::Core::String& Scope)
{
	Logger* Result = nullptr;
	std::map<const Elysium::Core::String, Elysium::Logging::Logger*>::iterator Iterator = _Logger.find(Scope);
	if (Iterator == _Logger.end())
	{
		_Logger.insert({ Elysium::Core::String(Scope), new Logger(Scope) });
		Result = _Logger[Scope];
	}
	else
	{
		Result = Iterator->second;
	}

	return Result;
}

void Elysium::Logging::LogManager::RegisterAppender(IAppender & Appender)
{
	_AppenderMutex.lock();
	_Appender.Add(&Appender);
	_AppenderMutex.unlock();

	IFlushableAppender* FlushableAppender = static_cast<IFlushableAppender*>(&Appender);
	if (FlushableAppender != nullptr)
	{
		_FlushableAppenderMutex.lock();
		_FlushableAppender.Add(FlushableAppender);
		_FlushableAppenderMutex.unlock();
	}
}
void Elysium::Logging::LogManager::UnregisterAppender(IAppender & Appender)
{
	IFlushableAppender* FlushableAppender = static_cast<IFlushableAppender*>(&Appender);
	if (FlushableAppender != nullptr)
	{
		_FlushableAppenderMutex.lock();
		_FlushableAppender.Remove(FlushableAppender);
		_FlushableAppenderMutex.unlock();
	}

	_AppenderMutex.lock();
	_Appender.Remove(&Appender);
	_AppenderMutex.unlock();
}

void Elysium::Logging::LogManager::Stop() 
{
	_FlushableAppenderMutex.lock();
	size_t FlushableAppenderCount = _FlushableAppender.GetCount();
	for (size_t i = 0; i < FlushableAppenderCount; i++)
	{
		_FlushableAppender[i]->Flush();
	}
	_FlushableAppender.Clear();
	_FlushableAppenderMutex.unlock();

	_AppenderMutex.lock();
	_Appender.Clear();
	_AppenderMutex.unlock();
}

Elysium::Logging::LogManager::LogManager()
{
}

void Elysium::Logging::LogManager::Forward(const Events::LogEvent & Event)
{
	size_t AppenderCount = _Appender.GetCount();
	for(size_t i = 0; i < AppenderCount; i++)
	{
		// ToDo: check whether the appender is actually interested in the message
		_Appender[i]->Write(Event);
	}
}
