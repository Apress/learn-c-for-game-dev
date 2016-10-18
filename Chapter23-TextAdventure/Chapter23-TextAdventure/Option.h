#pragma once

#include "OptionFactory.h"
#include "Visitable.h"
#include <memory>
#include <string>

class Player;

class Option
	: public Visitable
{
public:
	using Pointer = std::shared_ptr<Option>;

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

	virtual void Evaluate(Player& player) = 0;
};