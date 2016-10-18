#pragma once

#include "Option.h"
#include "Chest.h"

class OpenChestOption
	: public Option
{
private:
	Chest* m_chest;

public:
	OpenChestOption(Chest* chest, const std::string& outputText)
		: m_chest{chest}
		, Option(PlayerOptions::OpenChest, outputText)
	{

	}

	virtual void Evaluate(Player& player);
};