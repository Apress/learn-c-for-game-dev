#pragma once

#include <vector>

using EventID = int;

class EventHandler;

class Event
{
private:
	using EventHandlerList = std::vector<EventHandler*>;
	using EventHandlerListIterator = EventHandlerList::iterator;

	EventHandlerList m_listeners;
	EventID m_id;

public:
	explicit Event(EventID eventId);

	void Send();
	void SendToHandler(EventHandler& eventHandler);
	void AttachListener(EventHandler& eventHandler);
	void DetachListener(EventHandler& eventHandler);

	EventID GetID() const { return m_id; }
};
