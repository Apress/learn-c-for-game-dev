#include "OptionFactory.h"
#include "AttackEnemyOption.h"
#include "MoveOption.h"
#include "OpenChestOption.h"
#include "QuitOption.h"
#include "Room.h"
#include <stdarg.h>

Option::Pointer CreateOption(PlayerOptions optionType, const uint32_t serializableId)
{
	Option* newOption = nullptr;
	switch (optionType)
	{
	case PlayerOptions::GoNorth:
		newOption = new MoveOption(Room::JoiningDirections::North, PlayerOptions::GoNorth, "Go North", serializableId);
		break;
	case PlayerOptions::GoEast:
		newOption = new MoveOption(Room::JoiningDirections::East, PlayerOptions::GoEast, "Go East", serializableId);
		break;
	case PlayerOptions::GoSouth:
		newOption = new MoveOption(Room::JoiningDirections::South, PlayerOptions::GoSouth, "Go South", serializableId);
		break;
	case PlayerOptions::GoWest:
		newOption = new MoveOption(Room::JoiningDirections::West, PlayerOptions::GoWest, "Go West", serializableId);
		break;
	case PlayerOptions::OpenChest:
		newOption = new OpenChestOption("Open Chest", serializableId);
		break;
	case PlayerOptions::AttackEnemy:
		newOption = new AttackEnemyOption(serializableId);
		break;
	case PlayerOptions::Quit:
		newOption = new QuitOption("Quit", serializableId);
		break;
	case PlayerOptions::None:
		break;
	default:
		break;
	}

	Option::Pointer pOption;
	if (newOption != nullptr)
	{
		pOption = newOption->GetPointer();
	}
	return pOption;
}