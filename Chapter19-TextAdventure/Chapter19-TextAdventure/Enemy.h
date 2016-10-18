#pragma once

#include "Entity.h"

class Enemy
	: public Entity
{
public:
	enum class EnemyType
	{
		Dragon,
		Orc
	};

private:
	EnemyType m_type;
	bool m_alive{ true };

public:
	Enemy(EnemyType type)
		: m_type{ type }
	{

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