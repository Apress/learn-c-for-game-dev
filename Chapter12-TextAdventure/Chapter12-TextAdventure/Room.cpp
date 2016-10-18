#include "Room.h"

Room::Room()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(JoiningDirections::Max); ++i)
	{
		m_pJoiningRooms[i] = nullptr;
	}
}

void Room::AddRoom(Room::JoiningDirections direction, Room* pRoom)
{
	m_pJoiningRooms[static_cast<unsigned int>(direction)] = pRoom;
}

Room* Room::GetRoom(Room::JoiningDirections direction) const
{
	return m_pJoiningRooms[static_cast<unsigned int>(direction)];
}