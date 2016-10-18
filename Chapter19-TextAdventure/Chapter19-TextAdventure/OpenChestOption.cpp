#include "OpenChestOption.h"
#include "Item.h"
#include "Player.h"
#include <iostream>

void OpenChestOption::Evaluate(Player& player)
{
	if (m_chest->IsOpen() == false)
	{
		const Item* item = m_chest->Open();
		player.AddItem(item);

		std::cout << "You picked up a " << item->GetName() << " from the chest!" << std::endl << std::endl;
	}
}