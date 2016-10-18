#pragma once

#include "Entity.h"
#include "EnemyFactory.h"
#include "Serializable.h"
#include <memory>

class iOSEnemy
	: public EnemyBase
{
public:
	iOSEnemy(EnemyType type, const uint32_t serializableId)
		: EnemyBase(type, serializableId)
	{
		std::cout << "Created iOS Enemy!" << std::endl;
	}
};