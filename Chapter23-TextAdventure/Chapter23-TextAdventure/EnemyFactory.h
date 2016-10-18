#pragma once

class Enemy;

enum class EnemyType
{
	Dragon,
	Orc,
	Max
};

Enemy* CreateEnemy(EnemyType enemyType);