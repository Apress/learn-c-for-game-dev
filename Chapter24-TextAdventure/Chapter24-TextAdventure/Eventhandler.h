#pragma once

class Event;

class EventHandler
{
public:
	virtual void HandleEvent(const Event* pEvent) = 0;
};