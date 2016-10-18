// Chapter3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << 0x0F;

	cout << "Enter your first number: " << endl;
	int number1 = 0;
	cin >> number1;

	cout << "Enter your second number: " << endl;
	int number2 = 0;
	cin >> number2;

	bool result = number1 == number2;
	cout << "It is " << result << " that your first number is equal your second." << endl;
}

