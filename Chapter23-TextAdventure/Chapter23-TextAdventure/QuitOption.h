#pragma once

#include "Notifier.h"
#include "Option.h"
#include "OptionFactory.h"
#include "QuitObserver.h"
#include <iostream>

class QuitOption
	: public Option
	, public Notifier<QuitObserver>
{
public:
	QuitOption(const std::string& outputText)
		: Option(PlayerOptions::Quit, outputText)
	{

	}

	virtual void Evaluate(Player& player);
};