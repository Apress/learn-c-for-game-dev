#pragma once

class Visitable;

class Visitor
{
private:
	friend class Visitable;
	virtual void OnVisit(Visitable& visitable) = 0;
};