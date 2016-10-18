// Chapter14-Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include <iostream>

namespace
{
	const unsigned int ARRAY_SIZE = 5;
}

using namespace std;
using MyArray = std::array<int, ARRAY_SIZE>;

void ArrayIterators(MyArray myArray)
{
	for (MyArray::iterator iter = myArray.begin(); iter != myArray.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyArray::iterator iter = myArray.end() - 1; iter != myArray.begin(); --iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyArray::reverse_iterator iter = myArray.rbegin(); iter != myArray.rend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyArray::const_iterator iter = myArray.cbegin(); iter != myArray.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyArray::const_reverse_iterator iter = myArray.crbegin(); iter != myArray.crend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (auto iter = myArray.begin(); iter != myArray.end(); ++iter)
	{
		cout << *iter << endl;
	}

	for (auto iter = myArray.cbegin(); iter != myArray.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyArray::iterator iter = myArray.begin(); iter != myArray.end(); ++iter)
	{
		*iter = 5;
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyArray::const_iterator iter = myArray.cbegin(); iter != myArray.cend(); ++iter)
	{
		//*iter = 5;
		cout << *iter << endl;
	}
}

void FindInArray(MyArray myArray)
{
	for (unsigned int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (myArray[i] == 2)
		{
			cout << "Found: " << myArray[i] << " at position: " << i << endl;
		}
	}

	for (auto iter=myArray.begin(); iter!=myArray.end(); ++iter)
	{
		if (*iter == 2)
		{
			cout << "Found: " << *iter << endl;
		}
	}

	for (auto& number : myArray)
	{
		if (number == 2)
		{
			cout << "Found : " << number << endl;
		}
	}

	MyArray::iterator found = find(myArray.begin(), myArray.end(), 2);
	if (found != myArray.end())
	{
		cout << "Found : " << *found << endl;
	}
}

#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	int oldArray[ARRAY_SIZE] = { 0, 1, 2, 3, 4 };
	std::array<int, ARRAY_SIZE> newArray = { 0, 1, 2, 3, 4 };

	ArrayIterators(newArray);
	FindInArray(newArray);

	return 0;
}

