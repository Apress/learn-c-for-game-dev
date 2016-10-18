#include "EvaluateVisitor.h"
#include "Option.h"

EvaluateVisitor::EvaluateVisitor(Player& player)
: m_player{ player }
{

}

void EvaluateVisitor::OnVisit(Visitable& visitable)
{
	Option* pOption = dynamic_cast<Option*>(&visitable);
	if (pOption != nullptr)
	{
		pOption->Evaluate(m_player);
	}
}