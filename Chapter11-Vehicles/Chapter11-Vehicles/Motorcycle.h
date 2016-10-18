#pragma once

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle();
	~Motorcycle();

	virtual unsigned int GetNumberOfWheels() const
	{
		return 2;
	}
};

Motorcycle::Motorcycle()
{
	std::cout << "Motorcycle Constructed" << std::endl;
}

Motorcycle::~Motorcycle()
{
	std::cout << "Motorcycle Destructed" << std::endl;
}