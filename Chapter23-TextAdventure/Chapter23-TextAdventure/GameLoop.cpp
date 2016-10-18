#include "GameLoop.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include "EvaluateVisitor.h"
#include "EventManager.h"
#include "SDBMHash.h"

using namespace std;

namespace
{
	constexpr char* const QuitEventString = "QuitEvent";
	constexpr int QuitEventStringLength =
#ifndef constexpr
		constexpr_strlen(QuitEventString);
#else
		9;
#endif
	constexpr int QuitEvent = SDBMCalculator<QuitEventStringLength>::CalculateValue(QuitEventString);
}

Game::Game()
: m_attackDragonOption{ CreateOption(PlayerOptions::AttackEnemy) }
, m_attackOrcOption{ CreateOption(PlayerOptions::AttackEnemy) }
, m_moveNorthOption{ CreateOption(PlayerOptions::GoNorth) }
, m_moveEastOption{ CreateOption(PlayerOptions::GoEast) }
, m_moveSouthOption{ CreateOption(PlayerOptions::GoSouth) }
, m_moveWestOption{ CreateOption(PlayerOptions::GoWest) }
, m_openSwordChest{ CreateOption(PlayerOptions::OpenChest) }
, m_quitOption{ CreateOption(PlayerOptions::Quit) }
, m_swordChest{ &m_sword }
{
	static_cast<OpenChestOption*>(m_openSwordChest.get())->SetChest(&m_swordChest);

	m_enemies.emplace_back(CreateEnemy(EnemyType::Dragon));
	static_cast<AttackEnemyOption*>(m_attackDragonOption.get())->SetEnemy(m_enemies[0]);

	m_enemies.emplace_back(CreateEnemy(EnemyType::Orc));
	static_cast<AttackEnemyOption*>(m_attackOrcOption.get())->SetEnemy(m_enemies[1]);

	static_cast<QuitOption*>(m_quitOption.get())->AddObserver(this);
}

Game::~Game()
{
	static_cast<QuitOption*>(m_quitOption.get())->RemoveObserver(this);
}

void Game::InitializeRooms()
{
	for (auto& roomPointer : m_rooms)
	{
		roomPointer.reset(new Room());
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

void Game::WelcomePlayer()
{
	cout << "Welcome to Text Adventure!" << endl << endl;
	cout << "What is your name?" << endl << endl;

	string name;
	cin >> name;
	m_player.SetName(name);

	cout << endl << "Hello " << m_player.GetName() << endl;
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
	unsigned int playerInputChoice{ 0 };
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

void Game::RunGame()
{
	new EventManager();

	RegisterEvent(QuitEvent);
	AttachEvent(QuitEvent, this);

	InitializeRooms();

	WelcomePlayer();

	bool playerWon = false;
	while (m_playerQuit == false && playerWon == false)
	{
		GivePlayerOptions();

		stringstream playerInputStream;
		GetPlayerInput(playerInputStream);

		EvaluateInput(playerInputStream);

		for (auto& enemy : m_enemies)
		{
			playerWon = enemy->IsAlive() == false;
		}
	}

	if (playerWon == true)
	{
		cout << "Congratulations, you rid the dungeon of monsters!" << endl;
		cout << "Type goodbye to end" << endl;
		std::string input;
		cin >> input;
	}

	DetachEvent(QuitEvent, this);
	delete EventManager::GetSingletonPtr();
}

void Game::OnQuit()
{
	m_playerQuit = true;
}