#pragma once

#include "PlayerOptions.h"
#include <string>

class Player;

class Option
{
protected:
	PlayerOptions	m_chosenOption;
	std::string		m_outputText;
	std::string		m_optionText;

public:
	Option(PlayerOptions chosenOption, const std::string& outputText)
		: m_chosenOption(chosenOption)
		, m_outputText(outputText)
	{

	}

	void Option::SetOptionText(const std::string& optionText)
	{
		m_optionText = optionText;
	}

	const std::string& GetOutputText() const
	{
		return m_outputText;
	}

	PlayerOptions GetChosenOption() const
	{
		return m_chosenOption;
	}

	virtual bool Evaluate(const std::string& optionText, Player& player) = 0;
};