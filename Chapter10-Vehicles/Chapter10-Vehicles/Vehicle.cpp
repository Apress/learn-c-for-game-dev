#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle()
{
	std::cout << "Vehicle Constructed" << std::endl;
}

Vehicle::~Vehicle()
{
	std::cout << "Vehicle Destructed" << std::endl;
}

unsigned int Vehicle::GetNumberOfWheels() const
{
	return 0;
}