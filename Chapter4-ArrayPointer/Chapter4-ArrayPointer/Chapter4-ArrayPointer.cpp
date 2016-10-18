// Chapter4-ArrayPointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int intArray[5] = { 0, 1, 2, 3, 4 };

	cout << "Value: " << *intArray << endl;
	cout << "Value: " << *(intArray + 1) << endl;
	cout << "Value: " << *(intArray + 2) << endl;
	cout << "Value: " << *(intArray + 3) << endl;
	cout << "Value: " << *(intArray + 4) << endl;
	return 0;
}

