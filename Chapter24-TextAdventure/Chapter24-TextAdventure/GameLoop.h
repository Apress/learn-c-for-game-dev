#pragma once

#include "AttackEnemyOption.h"
#include "Chest.h"
#include "Enemy.h"
#include "EventHandler.h"
#include "MoveOption.h"
#include "OpenChestOption.h"
#include "Player.h"
#include "OptionFactory.h"
#include "QuitObserver.h"
#include "QuitOption.h"
#include "Room.h"
#include "Sword.h"
#include <array>
#include <map>

class Game
	: public EventHandler
	, public QuitObserver
{
private:
	static const unsigned int m_numberOfRooms = 4;
	using Rooms = std::array<Room::Pointer, m_numberOfRooms>;
	Rooms m_rooms;

	Player m_player;

	Option::Pointer m_attackDragonOption;
	Option::Pointer m_attackOrcOption;
	Option::Pointer m_moveNorthOption;
	Option::Pointer m_moveEastOption;
	Option::Pointer m_moveSouthOption;
	Option::Pointer m_moveWestOption;
	Option::Pointer m_openSwordChest;
	Option::Pointer m_quitOption;

	Sword m_sword;
	Chest m_swordChest;

	using Enemies = std::vector<Enemy::Pointer>;
	Enemies m_enemies;

	bool m_playerQuit{ false };

	void InitializeRooms();
	void WelcomePlayer(const bool loaded);
	void GivePlayerOptions() const;
	void GetPlayerInput(std::stringstream& playerInput) const;
	void EvaluateInput(std::stringstream& playerInput);
public:
	Game();
	~Game();

	void RunGame();

	virtual void HandleEvent(const Event* pEvent);

	// From QuitObserver
	virtual void OnQuit();
};