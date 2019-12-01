#include "LogManager.hpp"

std::mutex Elysium::Logging::LogManager::_AppenderMutex = std::mutex();

std::map<Elysium::Logging::IAppender*, Elysium::Logging::Filter> Elysium::Logging::LogManager::_AppenderFilterMap = std::map<Elysium::Logging::IAppender*, Elysium::Logging::Filter>();
Elysium::Core::Collections::Template::List<Elysium::Logging::IFlushableAppender*> Elysium::Logging::LogManager::_FlushableAppender = Elysium::Core::Collections::Template::List<Elysium::Logging::IFlushableAppender*>();

Elysium::Logging::LogManager::~LogManager()
{
}

void Elysium::Logging::LogManager::RegisterAppender(IAppender & Appender, Filter& Filter)
{
	_AppenderMutex.lock();
	_AppenderFilterMap.insert_or_assign(&Appender, Filter);

	IFlushableAppender* FlushableAppender = static_cast<IFlushableAppender*>(&Appender);
	if (FlushableAppender != nullptr)
	{
		_FlushableAppender.Add(FlushableAppender);
	}
	_AppenderMutex.unlock();
}
void Elysium::Logging::LogManager::UnregisterAppender(IAppender & Appender)
{
	_AppenderMutex.lock();
	IFlushableAppender* FlushableAppender = static_cast<IFlushableAppender*>(&Appender);
	if (FlushableAppender != nullptr)
	{
		_FlushableAppender.Remove(FlushableAppender);
	}

	_AppenderFilterMap.erase(&Appender);
	_AppenderMutex.unlock();
}

void Elysium::Logging::LogManager::Stop()
{
	_AppenderMutex.lock();
	size_t FlushableAppenderCount = _FlushableAppender.GetCount();
	for (size_t i = 0; i < FlushableAppenderCount; i++)
	{
		_FlushableAppender[i]->Flush();
	}
	_FlushableAppender.Clear();

	_AppenderFilterMap.clear();
	_AppenderMutex.unlock();
}

Elysium::Logging::LogManager::LogManager()
{
}

void Elysium::Logging::LogManager::Forward(const Events::LogEvent & Event)
{
	for (std::map<Elysium::Logging::IAppender*, Elysium::Logging::Filter>::iterator Iterator = _AppenderFilterMap.begin(); Iterator != _AppenderFilterMap.end(); ++Iterator)
	{
		if (Iterator->second.IsInterested(Event))
		{
			Iterator->first->Process(Event);
		}
	}
}
