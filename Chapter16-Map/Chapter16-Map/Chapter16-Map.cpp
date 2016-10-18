// Chapter16-Set.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;
using MyMap = map<int, string>;
using MyPair = pair<int, string>;

class TreeNode
{
private:
	int m_value;

	TreeNode* m_pLeft = nullptr;
	TreeNode* m_pRight = nullptr;
public:
	TreeNode(int value)
		: m_value{value}
	{}

	TreeNode* Find(int searchValue)
	{
		TreeNode* pResult = nullptr;

		if (m_value == searchValue)
		{
			pResult = this;
		}
		else if (m_pLeft != nullptr && m_value > searchValue)
		{
			pResult = m_pLeft->Find(searchValue);
		}
		else if (m_pRight != nullptr && m_value < searchValue)
		{
			pResult = m_pRight->Find(searchValue);
		}

		return pResult;
	}
};

void SetIterators(MyMap myMap)
{
	for (const auto& node : myMap)
	{
		cout << "First: " << node.first << " Second: " << node.second << endl;
	}

	cout << endl << endl;

	for (MyMap::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		cout << "First: " << iter->first << " Second: " << iter->second << endl;
	}

	cout << endl << endl;

	for (MyMap::reverse_iterator iter = myMap.rbegin(); iter != myMap.rend(); ++iter)
	{
		cout << "First: " << iter->first << " Second: " << iter->second << endl;
	}

	cout << endl << endl;

	for (MyMap::const_iterator iter = myMap.cbegin(); iter != myMap.cend(); ++iter)
	{
		cout << "First: " << iter->first << " Second: " << iter->second << endl;
	}

	cout << endl << endl;

	for (MyMap::const_reverse_iterator iter = myMap.crbegin(); iter != myMap.crend(); ++iter)
	{
		cout << "First: " << iter->first << " Second: " << iter->second << endl;
	}

	cout << endl << endl;

	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		cout << "First: " << iter->first << " Second: " << iter->second << endl;
	}

	for (auto iter = myMap.cbegin(); iter != myMap.cend(); ++iter)
	{
		cout << "First: " << iter->first << " Second: " << iter->second << endl;
	}

	cout << endl << endl;

	for (MyMap::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		//*iter = 5;
		cout << "First: " << iter->first << " Second: " << iter->second << endl;
	}

	cout << endl << endl;

	for (MyMap::const_iterator iter = myMap.cbegin(); iter != myMap.cend(); ++iter)
	{
		//*iter = 5;
		cout << "First: " << iter->first << " Second: " << iter->second << endl;
	}
}

void FindInSet(MyMap myMap)
{
	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		if (iter->first == 2)
		{
			cout << "Found: " << iter->second << endl;
		}
	}

	for (auto& pair : myMap)
	{
		if (pair.first == 2)
		{
			cout << "Found: " << pair.second << endl;
		}
	}

	MyMap::iterator found = myMap.find(2);
	if (found != myMap.end())
	{
		cout << "Found First: " << found->first << " Second: " << found->second << endl;
	}
}

#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	MyMap myMap = { { 2, "Two" }, { 1, "One" }, { 0, "Zero" } };
	myMap.emplace( 3, "Three" );
	MyPair node{ 4, "Four" };
	myMap.insert(node);

	SetIterators(myMap);
	FindInSet(myMap);

	return 0;
}

