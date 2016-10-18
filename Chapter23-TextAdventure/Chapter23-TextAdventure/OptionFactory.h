#pragma once

class Option;

enum class PlayerOptions
{
	GoNorth,
	GoEast,
	GoSouth,
	GoWest,
	OpenChest,
	AttackEnemy,
	Quit,
	None
};

Option* CreateOption(PlayerOptions optionType);