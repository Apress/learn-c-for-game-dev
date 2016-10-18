#pragma once

#include "EntityBase.h"

class AndroidEnemy
	: public EnemyBase
{
public:
	AndroidEnemy(EnemyType type, const uint32_t serializableId)
		: EnemyBase( type , serializableId )
	{
		std::cout << "Created Android Enemy!" << std::endl;
	}
};