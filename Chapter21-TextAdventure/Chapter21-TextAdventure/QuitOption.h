#pragma once

#include "Option.h"
#include "PlayerOptions.h"
#include <iostream>

class QuitOption
	: public Option
{
private:
	bool m_shouldQuit;

public:
	QuitOption(const std::string& outputText)
		: Option(PlayerOptions::Quit, outputText)
		, m_shouldQuit(false)
	{

	}

	bool ShouldQuit() const { return m_shouldQuit; }
	virtual void Evaluate(Player& player);
};