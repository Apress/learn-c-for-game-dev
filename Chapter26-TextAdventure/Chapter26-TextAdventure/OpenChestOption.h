#pragma once

#include "Option.h"
#include "Chest.h"

class OpenChestOption
	: public Option
{
private:
	Chest* m_chest;

public:
	OpenChestOption(const std::string& outputText, const uint32_t serializableId)
		: Option(PlayerOptions::OpenChest, outputText, serializableId)
	{

	}

	void SetChest(Chest* pChest)
	{
		m_chest = pChest;
	}

	virtual void Evaluate(Player& player);
};