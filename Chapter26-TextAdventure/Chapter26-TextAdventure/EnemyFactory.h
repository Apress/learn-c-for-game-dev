#pragma once

#include "FixedTypes.h"

class EnemyBase;

enum class EnemyType
{
	Dragon,
	Orc,
	Max
};

EnemyBase* CreateEnemy(EnemyType enemyType, const uint32_t serializableId);