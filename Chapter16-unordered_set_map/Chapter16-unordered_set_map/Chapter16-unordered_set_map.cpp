// Chapter16-unordered_set_map.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include "stdafx.h"
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;
using MyUnorderedSet = unordered_set<int>;
using MyUnorderedMap = unordered_map<int, string>;
using MyPair = pair<int, string>;

void SetIterators(MyUnorderedSet myUnorderedSet)
{
	for (MyUnorderedSet::iterator iter = myUnorderedSet.begin(); iter != myUnorderedSet.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyUnorderedSet::reverse_iterator iter = myUnorderedSet.rbegin(); iter != myUnorderedSet.rend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyUnorderedSet::const_iterator iter = myUnorderedSet.cbegin(); iter != myUnorderedSet.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyUnorderedSet::const_reverse_iterator iter = myUnorderedSet.crbegin(); iter != myUnorderedSet.crend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (auto iter = myUnorderedSet.begin(); iter != myUnorderedSet.end(); ++iter)
	{
		cout << *iter << endl;
	}

	for (auto iter = myUnorderedSet.cbegin(); iter != myUnorderedSet.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyUnorderedSet::iterator iter = myUnorderedSet.begin(); iter != myUnorderedSet.end(); ++iter)
	{
		//*iter = 5;
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyUnorderedSet::const_iterator iter = myUnorderedSet.cbegin(); iter != myUnorderedSet.cend(); ++iter)
	{
		//*iter = 5;
		cout << *iter << endl;
	}
}

void FindInSet(MyUnorderedSet myUnorderedSet)
{
	for (auto iter = myUnorderedSet.begin(); iter != myUnorderedSet.end(); ++iter)
	{
		if (*iter == 2)
		{
			cout << "Found: " << *iter << endl;
		}
	}

	for (auto& number : myUnorderedSet)
	{
		if (number == 2)
		{
			cout << "Found : " << number << endl;
		}
	}

	MyUnorderedSet::iterator found = myUnorderedSet.find(2);
	if (found != myUnorderedSet.end())
	{
		cout << "Found : " << *found << endl;
	}
}

void ExceptionExample()
{
	if (true)
	{
		throw -1;
	}
}

#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	MyUnorderedSet myUnorderedSet = { 2, 1, 0 };
	myUnorderedSet.emplace(4);
	myUnorderedSet.insert(3);
	
	MyUnorderedMap myUnorderedMap = { { 2, "Two" }, { 1, "One" }, { 0, "Zero" } };
	myUnorderedMap.emplace(3, "Three");
	MyPair node{ 4, "Four" };
	myUnorderedMap.insert(node);


	MyUnorderedSet::iterator found = find(myUnorderedSet.begin(), myUnorderedSet.end(), 2);
	if (found != myUnorderedSet.end())
	{
		cout << "Found : " << *found << endl;
	}

	found = myUnorderedSet.find(2);
	if (found != myUnorderedSet.end())
	{
		cout << "Found : " << *found << endl;
	}

	try
	{
		string& myString = myUnorderedMap.at(5);
		cout << "Found : " << myString << endl;
	}
	catch (const std::out_of_range& outOfRange)
	{
		cout << "Out of range error: " << outOfRange.what() << endl;
	}
	
	string& myString = myUnorderedMap[2];
	cout << "Found : " << myString << endl;

	SetIterators(myUnorderedSet);
	FindInSet(myUnorderedSet);

	try
	{
		ExceptionExample();
	}
	catch (int errorValue)
	{
		cout << "Error: " << errorValue << endl;
	}

	return 0;
}

