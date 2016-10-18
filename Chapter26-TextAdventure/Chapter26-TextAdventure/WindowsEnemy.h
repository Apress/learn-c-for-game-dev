#pragma once

#include "EnemyBase.h"

class WindowsEnemy
	: public EnemyBase
{
public:
	WindowsEnemy(EnemyType type, const uint32_t serializableId)
		: EnemyBase(type, serializableId)
	{
		std::cout << "Created Windows Enemy!" << std::endl;
	}
};