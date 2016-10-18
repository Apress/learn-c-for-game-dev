#pragma once

#include "Entity.h"
#include "EnemyFactory.h"
#include <memory>

class Enemy
	: public Entity
{
public:
	using Pointer = std::shared_ptr<Enemy>;
private:
	EnemyType m_type;
	bool m_alive{ true };

public:
	Enemy(EnemyType type)
		: m_type{ type }
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
};