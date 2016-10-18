#include "MoveOption.h"
#include <iostream>
#include "Player.h"

void MoveOption::Evaluate(Player& player)
{
	const Room::Pointer pPlayerCurrentRoom = player.GetCurrentRoom();
	Room::Pointer pNewRoom = pPlayerCurrentRoom->GetRoom(m_directionToMove);
	if (pNewRoom != nullptr)
	{
		player.SetCurrentRoom(pNewRoom);
		std::cout << "You have chosen to " << m_outputText << std::endl << std::endl;
	}
	else
	{
		const char8_t* strDirection = "North";
		switch (m_chosenOption)
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

		std::cout << "There is no room to the " << strDirection << std::endl << std::endl;
	}
}