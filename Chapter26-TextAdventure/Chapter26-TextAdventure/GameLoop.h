#pragma once

#include "AttackEnemyOption.h"
#include "Chest.h"
#include "EnemyBase.h"
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
#include <mutex>

class Game
	: public EventHandler
	, public QuitObserver
{
private:
	static const uint32_t m_numberOfRooms = 4;
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

	using Enemies = std::vector<EnemyBase::Pointer>;
	Enemies m_enemies;

	std::mutex m_mutex;
	mutable std::unique_lock<std::mutex> m_finishedQueryLock{ m_mutex, std::defer_lock };
	bool m_playerQuit{ false };
	void SetPlayerQuit()
	{
		m_finishedQueryLock.lock();
		m_playerQuit = true;
		m_finishedQueryLock.unlock();
	}

	bool m_playerWon{ false };
	void SetPlayerWon()
	{
		m_finishedQueryLock.lock();
		m_playerWon = true;
		m_finishedQueryLock.unlock();
	}
	
	bool GetPlayerWon()
	{
		m_finishedQueryLock.lock();
		bool playerWon = m_playerWon;
		m_finishedQueryLock.unlock();
		return playerWon;
	}

	void InitializeRooms();
	void WelcomePlayer(const bool loaded);
	void GivePlayerOptions() const;
	void GetPlayerInput(std::stringstream& playerInput) const;
	void EvaluateInput(std::stringstream& playerInput);
public:
	Game();
	virtual ~Game();

	void RunGame();

	virtual void HandleEvent(const Event* pEvent);

	// From QuitObserver
	virtual void OnQuit();

	bool HasFinished() const
	{
		m_finishedQueryLock.lock();
		bool hasFinished = m_playerQuit || m_playerWon;
		m_finishedQueryLock.unlock();
		return hasFinished;
	}
};