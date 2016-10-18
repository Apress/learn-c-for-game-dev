#include "GameLoop.h"
#include <iostream>

using namespace std;

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
	cout << "1: Go North" << endl << endl;
	cout << "2: Go East" << endl << endl;
	cout << "3: Go South" << endl << endl;
	cout << "4: Go West" << endl << endl;
	cout << "5: Quit" << endl << endl;
}

void Game::GetPlayerInput(string& playerInput) const
{
	cin >> playerInput;
}

PlayerOptions Game::EvaluateInput(string& playerInput) const
{
	PlayerOptions chosenOption = PlayerOptions::None;

	if (playerInput.compare("1") == 0)
	{
		cout << "You have chosen to Go North!" << endl << endl;
		chosenOption = PlayerOptions::GoNorth;
	}
	else if (playerInput.compare("2") == 0)
	{
		cout << "You have chosen to Go East!" << endl << endl;
		chosenOption = PlayerOptions::GoEast;
	}
	else if (playerInput.compare("3") == 0)
	{
		cout << "You have chosen to Go South!" << endl << endl;
		chosenOption = PlayerOptions::GoSouth;
	}
	else if (playerInput.compare("4") == 0)
	{
		cout << "You have chosen to Go West!" << endl << endl;
		chosenOption = PlayerOptions::GoWest;
	}
	else if (playerInput.compare("5") == 0)
	{
		cout << "You have chosen to Quit!" << endl << endl;
		chosenOption = PlayerOptions::Quit;
	}
	else
	{
		cout << "I do not recognise that option, try again!" << endl << endl;
	}

	return chosenOption;
}

void Game::RunGame()
{
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
		if (shouldEnd == false)
		{
			UpdateOnOption(selectedOption);
		}
	}
}

void Game::UpdateOnOption(PlayerOptions selectedOption)
{
	if (selectedOption == PlayerOptions::GoNorth ||
		selectedOption == PlayerOptions::GoEast ||
		selectedOption == PlayerOptions::GoSouth ||
		selectedOption == PlayerOptions::GoWest)
	{
		Room::JoiningDirections directionToMove = Room::JoiningDirections::North;
		switch (selectedOption)
		{
		case PlayerOptions::GoEast:
			{
				directionToMove = Room::JoiningDirections::East;
			}
			break;

		case PlayerOptions::GoSouth:
			{
				directionToMove = Room::JoiningDirections::South;
			}
			break;

		case PlayerOptions::GoWest:
			{
				directionToMove = Room::JoiningDirections::West;
			}
			break;
		}

		const Room* pPlayerCurrentRoom = m_player.GetCurrentRoom();
		const Room* pNewRoom = pPlayerCurrentRoom->GetRoom(directionToMove);
		if (pNewRoom != nullptr)
		{
			m_player.SetCurrentRoom(pNewRoom);
		}
		else
		{
			const char* strDirection = "North";
			switch (selectedOption)
			{
			case PlayerOptions::GoEast:
				{
					strDirection = "East";
				}
				break;

			case PlayerOptions::GoSouth:
				{
					strDirection = "South";
				}
				break;

			case PlayerOptions::GoWest:
				{
					strDirection = "West";
				}
				break;
			}

			cout << "There is no room to the " << strDirection << endl << endl;
		}
	}
}