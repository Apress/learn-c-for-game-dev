#pragma once

class Visitor;

class Visitable
{
public:
	virtual ~Visitable() {}

	void Visit(Visitor& visitor);
};