#pragma once

#include "Option.h"
#include "Chest.h"

class OpenChestOption
	: public Option
{
private:
	Chest* m_chest;

public:
	OpenChestOption(const std::string& outputText)
		: Option(PlayerOptions::OpenChest, outputText)
	{

	}

	void SetChest(Chest* pChest)
	{
		m_chest = pChest;
	}

	virtual void Evaluate(Player& player);
};