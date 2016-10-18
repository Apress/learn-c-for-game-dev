// Chapter3-Bitwise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int first = 0x0F;
	unsigned int second = 0x18;
	unsigned int anded = first & second;

	cout << hex << showbase;
	cout << first << endl;
	cout << second << endl;
	cout << anded << endl;

	unsigned int shifted = 0x2 >> 1;
	cout << shifted << endl;

	return 0;
}

