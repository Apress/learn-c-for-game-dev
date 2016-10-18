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
	QuitOption(const std::string& outputText, const uint32_t serializableId)
		: Option(PlayerOptions::Quit, outputText, serializableId)
	{

	}

	virtual void Evaluate(Player& player);
};