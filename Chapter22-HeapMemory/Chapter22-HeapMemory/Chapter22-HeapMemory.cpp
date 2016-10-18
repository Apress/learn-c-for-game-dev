// Chapter22-HeapMemory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>

class Simple
{
private:
	int variable{ 0 };

public:
	Simple()
	{
		std::cout << "Constructed" << std::endl;
	}

	~Simple()
	{
		std::cout << "Destroyed" << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	using UniqueSimplePtr = std::unique_ptr<Simple>;
	UniqueSimplePtr pSimple1{ new Simple() };
	std::cout << std::hex << std::showbase << reinterpret_cast<int>(pSimple1.get()) << std::endl;

	UniqueSimplePtr pSimple2;
	pSimple2.swap(pSimple1);
	std::cout << reinterpret_cast<int>(pSimple1.get()) << std::endl;
	std::cout << reinterpret_cast<int>(pSimple2.get()) << std::endl;

	using IntSharedPtr = std::shared_ptr<int>;
	IntSharedPtr pIntArray1{ new int[16] };
	IntSharedPtr pIntArray2{ pIntArray1 };

	std::cout << std::endl << reinterpret_cast<int>(pIntArray1.get()) << std::endl;
	std::cout << reinterpret_cast<int>(pIntArray2.get()) << std::endl;

	return 0;
}

