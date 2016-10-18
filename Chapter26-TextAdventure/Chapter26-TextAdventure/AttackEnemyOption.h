#pragma once

#include "Option.h"
#include "EnemyBase.h"

class AttackEnemyOption
	: public Option
{
private:
	EnemyBase::Pointer m_enemy;

public:
	AttackEnemyOption(uint32_t serializableId);

	void SetEnemy(EnemyBase::Pointer enemy)
	{
		m_enemy = enemy;
	}

	virtual void Evaluate(Player& player);
};