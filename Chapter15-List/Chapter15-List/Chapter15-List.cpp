// Chapter15-List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include "stdafx.h"
#include <list>
#include <iostream>

using namespace std;
using MyList = list<int>;

class ListNode
{
private:
	void* m_Data = nullptr;
	ListNode* m_Last = nullptr;
	ListNode* m_Next = nullptr;

public:
	ListNode(void* data)
	: m_Data{data}
	{

	}

	void* GetData()
	{
		return m_Data;
	}

	void SetLast(ListNode* last)
	{
		m_Last = last;
	}

	ListNode* GetLast()
	{
		return m_Last;
	}

	void SetNext(ListNode* next)
	{
		m_Next = next;
	}

	ListNode* GetNext()
	{
		return m_Next;
	}
};

void ListIterators(MyList myList)
{
	for (MyList::iterator iter = myList.begin(); iter != myList.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyList::reverse_iterator iter = myList.rbegin(); iter != myList.rend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyList::const_iterator iter = myList.cbegin(); iter != myList.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyList::const_reverse_iterator iter = myList.crbegin(); iter != myList.crend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (auto iter = myList.begin(); iter != myList.end(); ++iter)
	{
		cout << *iter << endl;
	}

	for (auto iter = myList.cbegin(); iter != myList.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyList::iterator iter = myList.begin(); iter != myList.end(); ++iter)
	{
		*iter = 5;
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (MyList::const_iterator iter = myList.cbegin(); iter != myList.cend(); ++iter)
	{
		//*iter = 5;
		cout << *iter << endl;
	}
}

void FindInVector(MyList myList)
{
	for (auto iter = myList.begin(); iter != myList.end(); ++iter)
	{
		if (*iter == 2)
		{
			cout << "Found: " << *iter << endl;
		}
	}

	for (auto& number : myList)
	{
		if (number == 2)
		{
			cout << "Found : " << number << endl;
		}
	}

	MyList::iterator found = find(myList.begin(), myList.end(), 2);
	if (found != myList.end())
	{
		cout << "Found : " << *found << endl;
	}
}

void OurList()
{
	unsigned int firstData = 1;
	ListNode first(&firstData);

	unsigned int secondData = 2;
	ListNode second(&secondData);

	unsigned int thirdData = 3;
	ListNode third(&thirdData);

	first.SetNext(&second);
	second.SetLast(&first);
	second.SetNext(&third);

	third.SetLast(&third);

	for (ListNode* iter = &first; iter != nullptr; iter = iter->GetNext())
	{
		unsigned int* number = static_cast<unsigned int*>(iter->GetData());
		cout << *number << endl;
	}
}

bool Descending(int first, int second)
{
	return first > second;
}

#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	OurList();

	MyList myList = { 0, 1, 2 };
	myList.push_back(3);
	myList.push_back(4);
	MyList::const_iterator iter = myList.cbegin();
	++iter;
	iter = myList.insert(iter, 5);
	myList.erase(iter);

	cout << endl;

	myList.sort(Descending);
	for (auto& value : myList)
	{
		cout << value << endl;
	}

	cout << endl;

	myList.sort();
	for (auto& value : myList)
	{
		cout << value << endl;
	}

	cout << endl;

	ListIterators(myList);
	FindInVector(myList);

	return 0;
}

