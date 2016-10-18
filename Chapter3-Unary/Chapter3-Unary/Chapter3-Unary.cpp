// Chapter3-Unary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int test = 0x0000000F;
	cout << hex << ~test;
	return 0;
}

