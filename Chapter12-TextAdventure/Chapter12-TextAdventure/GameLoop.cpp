#include "GameLoop.h"
#include <iostream>
#include <sstream>

using namespace std;

Game::Game()
	: m_moveNorthOption(Room::JoiningDirections::North, PlayerOptions::GoNorth, "Go North")
	, m_moveEastOption(Room::JoiningDirections::East, PlayerOptions::GoEast, "Go East")
	, m_moveSouthOption(Room::JoiningDirections::South, PlayerOptions::GoSouth, "Go South")
	, m_moveWestOption(Room::JoiningDirections::West, PlayerOptions::GoWest, "Go West")
	, m_quitOption("Quit")
{
	m_options[0] = dynamic_cast<Option*>(&m_moveNorthOption);
	m_options[1] = dynamic_cast<Option*>(&m_moveEastOption);
	m_options[2] = dynamic_cast<Option*>(&m_moveSouthOption);
	m_options[3] = dynamic_cast<Option*>(&m_moveWestOption);
	m_options[4] = dynamic_cast<Option*>(&m_quitOption);
}

void Game::InitializeRooms()
{
	// Room 0 heads North to Room 1
	m_rooms[0].AddRoom(Room::JoiningDirections::North, &(m_rooms[1]));

	// Room 1 heads East to Room 2, South to Room 0 and West to Room 3
	m_rooms[1].AddRoom(Room::JoiningDirections::East, &(m_rooms[2]));
	m_rooms[1].AddRoom(Room::JoiningDirections::South, &(m_rooms[0]));
	m_rooms[1].AddRoom(Room::JoiningDirections::West, &(m_rooms[3]));

	// Room 2 heads West to Room 1
	m_rooms[2].AddRoom(Room::JoiningDirections::West, &(m_rooms[1]));

	// Room 3 heads East to Room 1
	m_rooms[3].AddRoom(Room::JoiningDirections::East, &(m_rooms[1]));

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
	for (unsigned int i = 0; i < m_numberOfOptions; ++i)
	{
		Option* option = m_options[i];
		const unsigned int chosenOption = i + 1;
		cout << chosenOption << ": " << option->GetOutputText() << endl << endl;

		std::ostringstream chosenOptionString;
		chosenOptionString << chosenOption;
		option->SetOptionText(chosenOptionString.str());
	}
}

void Game::GetPlayerInput(string& playerInput) const
{
	cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(string& playerInput)
{
	PlayerOptions chosenOption = PlayerOptions::None;

	for (unsigned int i = 0; i < m_numberOfOptions; ++i)
	{
		Option* option = m_options[i];
		bool handled = option->Evaluate(playerInput, m_player);
		if (handled == true)
		{
			chosenOption = option->GetChosenOption();
			break;
		}
	}

	if (chosenOption == PlayerOptions::None)
	{
		cout << "I do not recognise that option, try again!" << endl << endl;
	}

	return chosenOption;
}

void Game::RunGame()
{
	string literalString{ "This is a string!" };
	string copiedString{ literalString };
	copiedString.shrink_to_fit();
	copiedString.clear();
	InitializeRooms();

	WelcomePlayer();

	bool shouldEnd = false;
	while (shouldEnd == false)
	{
		GivePlayerOptions();

		string playerInput;
		GetPlayerInput(playerInput);

		PlayerOptions selectedOption = EvaluateInput(playerInput);
		shouldEnd = selectedOption == PlayerOptions::Quit;
	}
}