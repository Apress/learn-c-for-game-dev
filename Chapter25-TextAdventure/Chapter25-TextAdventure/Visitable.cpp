#include "Visitable.h"
#include "Visitor.h"

void Visitable::Visit(Visitor& visitor)
{
	visitor.OnVisit(*this);
}