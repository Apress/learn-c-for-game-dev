// Chapter16-Set.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include "stdafx.h"
#include <set>
#include <string>
#include <iostream>

using namespace std;
using MySet = set<int>;

void SetIterators(MySet mySet)
{
	for (MySet::iterator iter = mySet.begin(); iter != mySet.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MySet::reverse_iterator iter = mySet.rbegin(); iter != mySet.rend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MySet::const_iterator iter = mySet.cbegin(); iter != mySet.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MySet::const_reverse_iterator iter = mySet.crbegin(); iter != mySet.crend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (auto iter = mySet.begin(); iter != mySet.end(); ++iter)
	{
		cout << *iter << endl;
	}

	for (auto iter = mySet.cbegin(); iter != mySet.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MySet::iterator iter = mySet.begin(); iter != mySet.end(); ++iter)
	{
		//*iter = 5;
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MySet::const_iterator iter = mySet.cbegin(); iter != mySet.cend(); ++iter)
	{
		//*iter = 5;
		cout << *iter << endl;
	}
}

void FindInSet(MySet mySet)
{
	for (auto iter = mySet.begin(); iter != mySet.end(); ++iter)
	{
		if (*iter == 2)
		{
			cout << "Found: " << *iter << endl;
		}
	}

	for (auto& number : mySet)
	{
		if (number == 2)
		{
			cout << "Found : " << number << endl;
		}
	}

	MySet::iterator found = find(mySet.begin(), mySet.end(), 2);
	if (found != mySet.end())
	{
		cout << "Found : " << *found << endl;
	}
}

#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	MySet mySet = { 2, 1, 0 };
	mySet.emplace(4);
	mySet.insert(3);

	SetIterators(mySet);
	FindInSet(mySet);

	return 0;
}

