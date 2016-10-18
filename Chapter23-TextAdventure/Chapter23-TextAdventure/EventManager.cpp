#include "EventManager.h"

EventManager::~EventManager()
{
	for (EventMapIterator iter = m_eventMap.begin(); iter != m_eventMap.end(); ++iter)
	{
		Event* pEvent = iter->second;
		if (pEvent)
		{
			delete pEvent;
			iter->second = nullptr;
		}
	}

	m_eventMap.clear();
}

void EventManager::SendEvent(EventID eventId)
{
	EventMapIterator result = m_eventMap.find(eventId);
	if (result != m_eventMap.end())
	{
		assert(result->second);
		if (result->second)
		{
			result->second->Send();
		}
	}
}

void EventManager::SendEventToHandler(EventID eventId, EventHandler& eventHandler)
{
	EventMapIterator result = m_eventMap.find(eventId);
	if (result != m_eventMap.end())
	{
		assert(result->second);
		if (result->second)
		{
			result->second->SendToHandler(eventHandler);
		}
	}
}

bool EventManager::RegisterEvent(EventID eventId)
{
	bool added = false;

	EventMapIterator result = m_eventMap.find(eventId);
	if (result == m_eventMap.end())
	{
		Event* pNewEvent = new Event(eventId);

		if (pNewEvent)
		{
			std::pair<EventID, Event*> newEvent(eventId, pNewEvent);
			auto addedIter = m_eventMap.insert(newEvent);
			added = addedIter.second;
		}
	}

	assert(added);
	return added;
}

void EventManager::AttachEvent(EventID eventId, EventHandler& eventHandler)
{
	EventMapIterator result = m_eventMap.find(eventId);
	assert(result != m_eventMap.end());
	if (result != m_eventMap.end())
	{
		assert(result->second);
		result->second->AttachListener(eventHandler);
	}
}

void EventManager::DetachEvent(EventID eventId, EventHandler& eventHandler)
{
	EventMapIterator result = m_eventMap.find(eventId);
	assert(result != m_eventMap.end());
	if (result != m_eventMap.end())
	{
		assert(result->second);
		result->second->DetachListener(eventHandler);
	}
}


