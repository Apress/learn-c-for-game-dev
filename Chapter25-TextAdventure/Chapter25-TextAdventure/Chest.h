#pragma once

#include "Entity.h"
#include "Serializable.h"

class Item;

class Chest
	: public Entity
	, public Serializable
{
private:
	const Item* m_item;
	bool m_isOpen{ false };

public:
	Chest(const Item* item, unsigned int serializableId);
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

	virtual void OnSave(std::ofstream& file)
	{
		file << m_isOpen;
	}

	virtual void OnLoad(std::ifstream& file)
	{
		file >> m_isOpen;
	}
};