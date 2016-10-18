#pragma once

#include "PlayerOptions.h"
#include <string>

class Player;

class Option
{
protected:
	PlayerOptions	m_chosenOption;
	std::string		m_outputText;

public:
	Option(PlayerOptions chosenOption, const std::string& outputText)
		: m_chosenOption(chosenOption)
		, m_outputText(outputText)
	{

	}

	const std::string& GetOutputText() const
	{
		return m_outputText;
	}

	PlayerOptions GetChosenOption() const
	{
		return m_chosenOption;
	}

	virtual void Evaluate(Player& player) = 0;
};