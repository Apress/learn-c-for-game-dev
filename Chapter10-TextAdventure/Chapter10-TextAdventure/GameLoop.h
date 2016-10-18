#pragma once

#include "Player.h"
#include "PlayerOptions.h"
#include "Room.h"

class Game
{
private:
	static const unsigned int m_numberOfRooms = 4;
	Room m_rooms[m_numberOfRooms];

	Player m_player;

	void InitializeRooms();
	void WelcomePlayer();
	void GivePlayerOptions() const;
	void GetPlayerInput(std::string& playerInput) const;
	PlayerOptions EvaluateInput(std::string& playerInput) const;
	void UpdateOnOption(PlayerOptions option);
public:

	void RunGame();
};