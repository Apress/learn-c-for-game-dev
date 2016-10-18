#include "EnemyFactory.h"
#include "Enemy.h"
#include <cassert>

Enemy* CreateEnemy(EnemyType enemyType, unsigned int serializableId)
{
	Enemy* pEnemy = nullptr;
	switch (enemyType)
	{
	case EnemyType::Dragon:
		pEnemy = new Enemy(EnemyType::Dragon, serializableId);
		break;
	case EnemyType::Orc:
		pEnemy = new Enemy(EnemyType::Orc, serializableId);
		break;
	default:
		assert(false); // Unknown enemy type
		break;
	}
	return pEnemy;
}