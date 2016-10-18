#include "AttackEnemyOption.h"
#include "Enemy.h"
#include "Player.h"
#include <array>
#include <cassert>
#include <iostream>

namespace
{
	std::array<const char*, static_cast<size_t>(EnemyType::Max)> ENEMY_NAMES
	{
		"dragon",
		"orc"
	};
}

AttackEnemyOption::AttackEnemyOption(unsigned int serializableId)
	: Option(PlayerOptions::AttackEnemy, "Attack Enemy", serializableId)
{

}

void AttackEnemyOption::Evaluate(Player& player)
{
	assert(m_enemy);

	const char* enemyName = ENEMY_NAMES[static_cast<unsigned int>(m_enemy->GetType())];
	std::cout << std::endl << "You have chosen to attack the " << enemyName << std::endl << std::endl;

	if (player.HasWeapon())
	{
		if (m_enemy->IsAlive())
		{
			m_enemy->Kill();

			std::cout << "You killed it!" << std::endl << std::endl;
		}
	}
	else
	{
		std::cout << "You need to find a weapon before attacking monsters!" << std::endl << std::endl;
	}
}