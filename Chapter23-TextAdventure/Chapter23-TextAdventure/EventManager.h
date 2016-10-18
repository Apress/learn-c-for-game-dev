#pragma once

#include "Singleton.h"
#include "Event.h"
#include <cassert>
#include <unordered_map>

class EventManager
	: public Singleton<EventManager>
{
	friend void SendEvent(EventID eventId);

	template <typename T>
	friend void SendEventToHandler(EventID eventId, T* eventHandler);

	friend bool RegisterEvent(EventID eventId);

	template <typename T>
	friend void AttachEvent(EventID eventId, T* eventHandler);

	template <typename T>
	friend void DetachEvent(EventID eventId, T* eventHandler);

private:
	using EventMap = std::unordered_map<EventID, Event*>;
	using EventMapIterator  = EventMap::iterator;

	EventMap m_eventMap;

	void SendEvent(EventID eventId);

	void SendEventToHandler(EventID eventId, EventHandler& eventHandler);
	bool RegisterEvent(EventID eventId);

	void AttachEvent(EventID eventId, EventHandler& eventHandler);

	void DetachEvent(EventID eventId, EventHandler& eventHandler);

public:
	virtual ~EventManager();
};

inline void SendEvent(EventID eventId)
{
	EventManager* pEventManager = EventManager::GetSingletonPtr();
	assert(pEventManager);
	if (pEventManager)
	{
		pEventManager->SendEvent(eventId);
	}
}

template <typename T>
inline void SendEventToHandler(EventID eventId, T* eventHandler)
{
	static_assert(std::is_base_of<EventHandler, T>::value, "Class provided is not derived from EventHandler");

	EventManager* pEventManager = EventManager::GetSingletonPtr();
	assert(pEventManager);
	if (pEventManager)
	{
		pEventManager->SendEventToHandler(eventId, *static_cast<EventHandler*>(eventHandler));
	}
}

inline bool RegisterEvent(EventID eventId)
{
	bool added = false;

	EventManager* pEventManager = EventManager::GetSingletonPtr();
	assert(pEventManager);
	if (pEventManager)
	{
		added = pEventManager->RegisterEvent(eventId);
	}

	return added;
}

template <typename T>
inline void AttachEvent(EventID eventId, T* eventHandler)
{
	static_assert(std::is_base_of<EventHandler, T>::value, "Class provided is not derived from EventHandler");

	EventManager* pEventManager = EventManager::GetSingletonPtr();
	assert(pEventManager);
	if (pEventManager)
	{
		pEventManager->AttachEvent(eventId, *static_cast<EventHandler*>(eventHandler));
	}
}

template <typename T>
inline void DetachEvent(EventID eventId, T* eventHandler)
{
	static_assert(std::is_base_of<EventHandler, T>::value, "Class provided is not derived from EventHandler");

	EventManager* pEventManager = EventManager::GetSingletonPtr();
	assert(pEventManager);
	if (pEventManager)
	{
		pEventManager->DetachEvent(eventId, *static_cast<EventHandler*>(eventHandler));
	}
}
