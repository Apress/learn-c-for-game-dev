// Chapter11-Vehicles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Car.h"
#include "Motorcycle.h"

void PrintNumberOfWheels()
{
	Car	car;
	Motorcycle motorcycle;

	Vehicle* pVehicle = dynamic_cast<Vehicle*>(&car);
	Car* pCar = dynamic_cast<Car*>(pVehicle);
	if (pCar != nullptr)
	{
		std::cout << pCar->GetNumberOfWheels() << std::endl;
	}

	pVehicle = dynamic_cast<Vehicle*>(&motorcycle);
	pCar = dynamic_cast<Car*>(pVehicle);
	if (pCar != nullptr)
	{
		std::cout << pCar->GetNumberOfWheels() << std::endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	PrintNumberOfWheels();

	return 0;
}

