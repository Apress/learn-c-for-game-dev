#pragma once

#include "AttackEnemyOption.h"
#include "Chest.h"
#include "Enemy.h"
#include "MoveOption.h"
#include "OpenChestOption.h"
#include "Player.h"
#include "PlayerOptions.h"
#include "QuitOption.h"
#include "Room.h"
#include "Sword.h"
#include <array>
#include <map>

class Game
{
private:
	static const unsigned int m_numberOfRooms = 4;
	using Rooms = std::array<Room, m_numberOfRooms>;
	Rooms m_rooms;

	Player m_player;

	AttackEnemyOption	m_attackDragonOption;
	AttackEnemyOption	m_attackOrcOption;
	MoveOption			m_moveNorthOption;
	MoveOption			m_moveEastOption;
	MoveOption			m_moveSouthOption;
	MoveOption			m_moveWestOption;
	OpenChestOption		m_openSwordChest;
	QuitOption			m_quitOption;

	Sword			m_sword;
	Chest			m_swordChest;

	Enemy			m_dragon;
	Enemy			m_orc;

	void InitializeRooms();
	void WelcomePlayer();
	void GivePlayerOptions() const;
	void GetPlayerInput(std::stringstream& playerInput) const;
	PlayerOptions EvaluateInput(std::stringstream& playerInput);
public:
	Game();

	void RunGame();
};