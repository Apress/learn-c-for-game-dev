#include "MoveOption.h"
#include <iostream>
#include "Player.h"

void MoveOption::Evaluate(Player& player)
{
	const Room* pPlayerCurrentRoom = player.GetCurrentRoom();
	Room* pNewRoom = pPlayerCurrentRoom->GetRoom(m_directionToMove);
	if (pNewRoom != nullptr)
	{
		player.SetCurrentRoom(pNewRoom);
		std::cout << "You have chosen to " << m_outputText << std::endl << std::endl;
	}
	else
	{
		const char* strDirection = "North";
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