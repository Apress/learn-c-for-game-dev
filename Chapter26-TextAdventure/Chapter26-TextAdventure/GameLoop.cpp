#include "GameLoop.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <future>
#include <chrono>
#include "EvaluateVisitor.h"
#include "EventManager.h"
#include "SDBMHash.h"
#include "SerializationManager.h"

using namespace std;

namespace
{
	constexpr char8_t* const QuitEventString = "QuitEvent";
	constexpr int32_t QuitEventStringLength =
#ifndef constexpr
		constexpr_strlen(QuitEventString);
#else
		9;
#endif
	constexpr int32_t QuitEvent = SDBMCalculator<QuitEventStringLength>::CalculateValue(QuitEventString);
}

Game::Game()
: m_attackDragonOption{ CreateOption(PlayerOptions::AttackEnemy, SDBMCalculator<18>::CalculateValue("AttackDragonOption")) }
, m_attackOrcOption{ CreateOption(PlayerOptions::AttackEnemy, SDBMCalculator<15>::CalculateValue("AttackOrcOption")) }
, m_moveNorthOption{ CreateOption(PlayerOptions::GoNorth, SDBMCalculator<15>::CalculateValue("MoveNorthOption")) }
, m_moveEastOption{ CreateOption(PlayerOptions::GoEast, SDBMCalculator<14>::CalculateValue("MoveEastOption")) }
, m_moveSouthOption{ CreateOption(PlayerOptions::GoSouth, SDBMCalculator<15>::CalculateValue("MoveSouthOption")) }
, m_moveWestOption{ CreateOption(PlayerOptions::GoWest, SDBMCalculator<14>::CalculateValue("MoveWestOption")) }
, m_openSwordChest{ CreateOption(PlayerOptions::OpenChest, SDBMCalculator<20>::CalculateValue("OpenSwordChestOption")) }
, m_quitOption{ CreateOption(PlayerOptions::Quit, SDBMCalculator<10>::CalculateValue("QuitOption")) }
, m_swordChest{ &m_sword, SDBMCalculator<5>::CalculateValue("Chest") }
{
	static_cast<OpenChestOption*>(m_openSwordChest.get())->SetChest(&m_swordChest);

	m_enemies.emplace_back(CreateEnemy(EnemyType::Dragon, SDBMCalculator<6>::CalculateValue("Dragon")));
	static_cast<AttackEnemyOption*>(m_attackDragonOption.get())->SetEnemy(m_enemies[0]);

	m_enemies.emplace_back(CreateEnemy(EnemyType::Orc, SDBMCalculator<3>::CalculateValue("Orc")));
	static_cast<AttackEnemyOption*>(m_attackOrcOption.get())->SetEnemy(m_enemies[1]);

	static_cast<QuitOption*>(m_quitOption.get())->AddObserver(this);
}

Game::~Game()
{
	static_cast<QuitOption*>(m_quitOption.get())->RemoveObserver(this);
}

void Game::InitializeRooms()
{
	uint32_t count{ 0 };
	for (auto& roomPointer : m_rooms)
	{
		std::stringstream roomId;
		roomId << "Room" << count++;
		Room* pRoom = new Room(SDBMHash(roomId.str()));
		roomPointer = pRoom->GetPointer();
	}

	// Room 0 heads North to Room 1
	m_rooms[0]->AddRoom(Room::JoiningDirections::North, m_rooms[1]);
	m_rooms[0]->AddStaticOption(m_moveNorthOption);
	m_rooms[0]->AddStaticOption(m_quitOption);
	m_rooms[0]->AddDynamicOption(m_openSwordChest);

	// Room 1 heads East to Room 2, South to Room 0 and West to Room 3
	m_rooms[1]->AddRoom(Room::JoiningDirections::East, m_rooms[2]);
	m_rooms[1]->AddStaticOption(m_moveEastOption);
	m_rooms[1]->AddRoom(Room::JoiningDirections::South, m_rooms[0]);
	m_rooms[1]->AddStaticOption(m_moveSouthOption);
	m_rooms[1]->AddRoom(Room::JoiningDirections::West, m_rooms[3]);
	m_rooms[1]->AddStaticOption(m_moveWestOption);
	m_rooms[1]->AddStaticOption(m_quitOption);

	// Room 2 heads West to Room 1
	m_rooms[2]->AddRoom(Room::JoiningDirections::West, m_rooms[1]);
	m_rooms[2]->AddStaticOption(m_moveWestOption);
	m_rooms[2]->AddStaticOption(m_quitOption);
	m_rooms[2]->AddDynamicOption(m_attackDragonOption);

	// Room 3 heads East to Room 1
	m_rooms[3]->AddRoom(Room::JoiningDirections::East, m_rooms[1]);
	m_rooms[3]->AddStaticOption(m_moveEastOption);
	m_rooms[3]->AddStaticOption(m_quitOption);
	m_rooms[3]->AddDynamicOption(m_attackOrcOption);

	m_player.SetCurrentRoom(m_rooms[0]);
}

void Game::WelcomePlayer(const bool loaded)
{
	if (!loaded)
	{
		cout << "Welcome to Text Adventure!" << endl << endl;
		cout << "What is your name?" << endl << endl;

		string name;
		cin >> name;
		m_player.SetName(name);

		cout << endl << "Hello " << m_player.GetName() << endl;
	}
	else
	{
		cout << endl << "Welcome Back " << m_player.GetName() << endl << endl;
	}
}

void Game::GivePlayerOptions() const
{
	cout << "What would you like to do? (Enter a corresponding number)" << endl << endl;

	// Print the options for the room
	m_player.GetCurrentRoom()->PrintOptions();
}

void Game::GetPlayerInput(stringstream& playerInputStream) const
{
	string input;
	cin >> input;
	playerInputStream << input;
}

void Game::EvaluateInput(stringstream& playerInputStream)
{
	PlayerOptions chosenOption = PlayerOptions::None;
	uint32_t playerInputChoice{ 0 };
	playerInputStream >> playerInputChoice;

	try
	{
		Option::Pointer option = m_player.GetCurrentRoom()->EvaluateInput(playerInputChoice);
		EvaluateVisitor evaluator{ m_player };
		option->Visit(evaluator);
	}
	catch (const std::out_of_range&)
	{
		cout << "I do not recognize that option, try again!" << endl << endl;
	}
}

void Game::HandleEvent(const Event* pEvent)
{
}

bool LoadSaveGame()
{
	return SerializationManager::GetSingleton().Load();
}

void Game::RunGame()
{
	InitializeRooms();

	std::packaged_task< bool() > loaderTask{ LoadSaveGame };
	std::thread loaderThread{ std::ref{ loaderTask } };
	auto loaderFuture = loaderTask.get_future();
	while (loaderFuture.wait_for(std::chrono::seconds{ 0 }) != std::future_status::ready)
	{
		// Wait until the future is ready.
		// In a full game you could update a spinning progress icon!
		int32_t x = 0;
	}
	bool userSaveLoaded = loaderFuture.get();
	WelcomePlayer(userSaveLoaded);

	while (!HasFinished())
	{
		GivePlayerOptions();

		stringstream playerInputStream;
		GetPlayerInput(playerInputStream);

		EvaluateInput(playerInputStream);

		bool playerWon = true;
		for (auto& enemy : m_enemies)
		{
			playerWon &= enemy->IsAlive() == false;
		}

		if (playerWon)
		{
			SetPlayerWon();
		}
	}

	if (GetPlayerWon())
	{
		SerializationManager::GetSingleton().ClearSave();
		cout << "Congratulations, you rid the dungeon of monsters!" << endl;
		cout << "Type goodbye to end" << endl;
		std::string input;
		cin >> input;
	}
}

void Game::OnQuit()
{
	SerializationManager::GetSingleton().Save();
	SetPlayerQuit();
}