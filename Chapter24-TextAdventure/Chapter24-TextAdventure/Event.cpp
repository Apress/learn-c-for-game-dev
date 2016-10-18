#include "Event.h"
#include "EventHandler.h"

#include <cassert>

Event::Event(EventID eventId)
: m_id{eventId}
{

}

void Event::Send()
{
	for (auto& listener : m_listeners)
	{
		if (listener != nullptr)
		{
			listener->HandleEvent(this);
		}
	}
}

void Event::SendToHandler(EventHandler& eventHandler)
{
	auto found = std::find(m_listeners.begin(), m_listeners.end(), &eventHandler);
	if (found != m_listeners.end())
	{
		(*found)->HandleEvent(this);
	}
}

void Event::AttachListener(EventHandler& eventHandler)
{
	m_listeners.push_back(&eventHandler);
}

void Event::DetachListener(EventHandler& eventHandler)
{
	for (EventHandlerListIterator iter = m_listeners.begin();
		iter != m_listeners.end();
		++iter)
	{
		if (&eventHandler == *iter)
		{
			m_listeners.erase(iter);
			break;
		}
	}
}
