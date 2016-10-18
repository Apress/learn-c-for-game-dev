#include "Car.h"
#include <iostream>

Car::Car()
{
	std::cout << "Car Constructed" << std::endl;
}

Car::~Car()
{
	std::cout << "Car Destructed" << std::endl;
}