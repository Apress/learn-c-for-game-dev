// Chapter14-Vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;
using MyVector = vector<int>;

void VectorIterators(MyVector myVector)
{
	for (MyVector::iterator iter = myVector.begin(); iter != myVector.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyVector::iterator iter = myVector.end() - 1; iter != myVector.begin(); --iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyVector::reverse_iterator iter = myVector.rbegin(); iter != myVector.rend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyVector::const_iterator iter = myVector.cbegin(); iter != myVector.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyVector::const_reverse_iterator iter = myVector.crbegin(); iter != myVector.crend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (auto iter = myVector.begin(); iter != myVector.end(); ++iter)
	{
		cout << *iter << endl;
	}

	for (auto iter = myVector.cbegin(); iter != myVector.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyVector::iterator iter = myVector.begin(); iter != myVector.end(); ++iter)
	{
		*iter = 5;
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyVector::const_iterator iter = myVector.cbegin(); iter != myVector.cend(); ++iter)
	{
		//*iter = 5;
		cout << *iter << endl;
	}
}

void FindInVector(MyVector myVector)
{
	for (unsigned int i = 0; i < myVector.size(); ++i)
	{
		if (myVector[i] == 2)
		{
			cout << "Found: " << myVector[i] << " at position: " << i << endl;
		}
	}

	for (auto iter = myVector.begin(); iter != myVector.end(); ++iter)
	{
		if (*iter == 2)
		{
			cout << "Found: " << *iter << endl;
		}
	}

	for (auto& number : myVector)
	{
		if (number == 2)
		{
			cout << "Found : " << number << endl;
		}
	}

	MyVector::iterator found = find(myVector.begin(), myVector.end(), 2);
	if (found != myVector.end())
	{
		cout << "Found : " << *found << endl;
	}
}

bool Descending(int first, int second)
{
	return first > second;
}

#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	MyVector myVector = { 0, 1, 2 };
	myVector.push_back(3);
	myVector.push_back(4);
	MyVector::const_iterator iter = myVector.cbegin() + 1;
	myVector.insert(iter, 5);
	myVector.erase(iter);

	sort(myVector.begin(), myVector.end(), Descending);
	for (auto& value : myVector)
	{
		cout << value << endl;
	}

	cout << endl;

	sort(myVector.begin(), myVector.end());
	for (auto& value : myVector)
	{
		cout << value << endl;
	}

	cout << endl;

	VectorIterators(myVector);
	FindInVector(myVector);

	return 0;
}

