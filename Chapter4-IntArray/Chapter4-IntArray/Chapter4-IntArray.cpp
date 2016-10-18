// Chapter4-IntArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int intArray[5] = { 0, 1, 2, 3, 4 };

	unsigned int index = 0;
	cout << "Index: " << index << endl;
	cout << "Value: " << intArray[index++] << endl;

	cout << "Index: " << index << endl;
	cout << "Value: " << intArray[index++] << endl;

	cout << "Index: " << index << endl;
	cout << "Value: " << intArray[index++] << endl;

	cout << "Index: " << index << endl;
	cout << "Value: " << intArray[index++] << endl;

	cout << "Index: " << index << endl;
	cout << "Value: " << intArray[index++] << endl;
	return 0;
}

