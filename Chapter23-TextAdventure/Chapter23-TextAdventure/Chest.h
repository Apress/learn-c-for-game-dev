#pragma once

#include "Entity.h"

class Item;

class Chest
	: public Entity
{
private:
	const Item* m_item;
	bool m_isOpen{ false };

public:
	Chest(const Item* item);
	void Update();

	bool IsOpen() const
	{
		return m_isOpen;
	}

	const Item* Open()
	{
		m_isOpen = true;
		return m_item;
	}
};