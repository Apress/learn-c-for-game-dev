#pragma once

#include "Option.h"
#include "Enemy.h"

class AttackEnemyOption
	: public Option
{
private:
	Enemy::Pointer m_enemy;

public:
	AttackEnemyOption();

	void SetEnemy(Enemy::Pointer enemy)
	{
		m_enemy = enemy;
	}

	virtual void Evaluate(Player& player);
};