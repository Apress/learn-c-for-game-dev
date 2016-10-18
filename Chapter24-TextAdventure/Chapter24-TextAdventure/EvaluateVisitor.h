#pragma once

#include "Visitor.h"

class Player;

class EvaluateVisitor
	: public Visitor
{
private:
	Player& m_player;

public:
	EvaluateVisitor(Player& player);

	virtual void OnVisit(Visitable& visitable);
};