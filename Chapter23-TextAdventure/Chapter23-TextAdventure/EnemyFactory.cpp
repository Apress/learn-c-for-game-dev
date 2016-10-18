#include "EnemyFactory.h"
#include "Enemy.h"
#include <cassert>

Enemy* CreateEnemy(EnemyType enemyType)
{
	Enemy* pEnemy = nullptr;
	switch (enemyType)
	{
	case EnemyType::Dragon:
		pEnemy = new Enemy(EnemyType::Dragon);
		break;
	case EnemyType::Orc:
		pEnemy = new Enemy(EnemyType::Orc);
		break;
	default:
		assert(false); // Unknown enemy type
		break;
	}
	return pEnemy;
}