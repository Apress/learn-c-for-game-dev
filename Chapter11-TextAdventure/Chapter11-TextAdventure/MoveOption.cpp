#include "MoveOption.h"
#include <iostream>
#include "Player.h"

bool MoveOption::Evaluate(const std::string& optionText, Player& player)
{
	bool handled = false;

	if (m_optionText.compare(optionText) == 0)
	{
		const Room* pPlayerCurrentRoom = player.GetCurrentRoom();
		const Room* pNewRoom = pPlayerCurrentRoom->GetRoom(m_directionToMove);
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

		handled = true;
	}

	return handled;
}