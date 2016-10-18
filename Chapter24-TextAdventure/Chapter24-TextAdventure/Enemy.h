#pragma once

#include "Entity.h"
#include "EnemyFactory.h"
#include "Serializable.h"
#include <memory>

class Enemy
	: public Entity
	, public Serializable
{
public:
	using Pointer = std::shared_ptr<Enemy>;
private:
	EnemyType m_type;
	bool m_alive{ true };

public:
	Enemy(EnemyType type, unsigned int serializableId)
		: m_type{ type }
		, Serializable(serializableId)
	{

	}

	EnemyType GetType() const
	{
		return m_type;
	}

	bool IsAlive() const
	{
		return m_alive;
	}

	void Kill()
	{
		m_alive = false;
	}

	virtual void OnSave(std::ofstream& file)
	{
		file << m_alive;
	}

	virtual void OnLoad(std::ifstream& file)
	{
		file >> m_alive;
	}
};