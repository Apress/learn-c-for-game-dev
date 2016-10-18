#pragma once

#include "Entity.h"

class Room
	: public Entity
{
public:
	enum class JoiningDirections
	{
		North = 0,
		East,
		South,
		West,
		Max
	};

private:
	Room* m_pJoiningRooms[JoiningDirections::Max];

public:
	Room();

	void AddRoom(JoiningDirections direction, Room* pRoom);
	Room* GetRoom(JoiningDirections direction) const;
};