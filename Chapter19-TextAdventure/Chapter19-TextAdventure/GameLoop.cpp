#include "GameLoop.h"
#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

Game::Game()
	: m_attackDragonOption(&m_dragon, "Attack Dragon")
	, m_attackOrcOption(&m_orc, "Attack Orc")
	, m_moveNorthOption(Room::JoiningDirections::North, PlayerOptions::GoNorth, "Go North")
	, m_moveEastOption(Room::JoiningDirections::East, PlayerOptions::GoEast, "Go East")
	, m_moveSouthOption(Room::JoiningDirections::South, PlayerOptions::GoSouth, "Go South")
	, m_moveWestOption(Room::JoiningDirections::West, PlayerOptions::GoWest, "Go West")
	, m_openSwordChest(&m_swordChest, "Open Chest")
	, m_quitOption("Quit")
	, m_swordChest(&m_sword)
	, m_dragon(Enemy::EnemyType::Dragon)
	, m_orc(Enemy::EnemyType::Orc)
{
	
}

void Game::InitializeRooms()
{
	// Room 0 heads North to Room 1
	m_rooms[0].AddRoom(Room::JoiningDirections::North, &(m_rooms[1]));
	m_rooms[0].AddStaticOption(&m_moveNorthOption);
	m_rooms[0].AddStaticOption(&m_quitOption);
	m_rooms[0].AddDynamicOption(&m_openSwordChest);

	// Room 1 heads East to Room 2, South to Room 0 and West to Room 3
	m_rooms[1].AddRoom(Room::JoiningDirections::East, &(m_rooms[2]));
	m_rooms[1].AddStaticOption(&m_moveEastOption);
	m_rooms[1].AddRoom(Room::JoiningDirections::South, &(m_rooms[0]));
	m_rooms[1].AddStaticOption(&m_moveSouthOption);
	m_rooms[1].AddRoom(Room::JoiningDirections::West, &(m_rooms[3]));
	m_rooms[1].AddStaticOption(&m_moveWestOption);
	m_rooms[1].AddStaticOption(&m_quitOption);

	// Room 2 heads West to Room 1
	m_rooms[2].AddRoom(Room::JoiningDirections::West, &(m_rooms[1]));
	m_rooms[2].AddStaticOption(&m_moveWestOption);
	m_rooms[2].AddStaticOption(&m_quitOption);
	m_rooms[2].AddDynamicOption(&m_attackDragonOption);

	// Room 3 heads East to Room 1
	m_rooms[3].AddRoom(Room::JoiningDirections::East, &(m_rooms[1]));
	m_rooms[3].AddStaticOption(&m_moveEastOption);
	m_rooms[3].AddStaticOption(&m_quitOption);
	m_rooms[3].AddDynamicOption(&m_attackOrcOption);

	m_player.SetCurrentRoom(&(m_rooms[0]));
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

PlayerOptions Game::EvaluateInput(stringstream& playerInputStream)
{
	PlayerOptions chosenOption = PlayerOptions::None;
	unsigned int playerInputChoice{ 0 };
	playerInputStream >> playerInputChoice;

	try
	{
		Option* option = m_player.GetCurrentRoom()->EvaluateInput(playerInputChoice);
		option->Evaluate(m_player);
		chosenOption = option->GetChosenOption();
	}
	catch (const std::out_of_range&)
	{
		cout << "I do not recognize that option, try again!" << endl << endl;
	}

	return chosenOption;
}

void Game::RunGame()
{
	InitializeRooms();

	WelcomePlayer();

	bool playerWon = false;
	bool playerQuit = false;
	while (playerQuit == false && playerWon == false)
	{
		GivePlayerOptions();

		stringstream playerInputStream;
		GetPlayerInput(playerInputStream);

		PlayerOptions selectedOption = EvaluateInput(playerInputStream);
		playerQuit = selectedOption == PlayerOptions::Quit;

		playerWon = m_dragon.IsAlive() == false && m_orc.IsAlive() == false;
	}

	if (playerWon == true)
	{
		cout << "Congratulations, you rid the dungeon of monsters!" << endl;
		cout << "Type goodbye to end" << endl;
		std::string input;
		cin >> input;
	}
}