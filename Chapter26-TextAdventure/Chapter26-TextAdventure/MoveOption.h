#pragma once

#include "Option.h"
#include "Room.h"

class Player;

class MoveOption
	:	public Option
{
private:
	Room::JoiningDirections m_directionToMove;

public:
	MoveOption(Room::JoiningDirections joiningDirection, PlayerOptions chosenOption, const std::string& outputText, const uint32_t serializableId)
		: Option(chosenOption, outputText, serializableId)
		, m_directionToMove(joiningDirection)
	{

	}

	virtual void Evaluate(Player& player);
};