#pragma once

#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	~Car();

	unsigned int	GetNumberOfWheels() const
	{
		return 4;
	}
};