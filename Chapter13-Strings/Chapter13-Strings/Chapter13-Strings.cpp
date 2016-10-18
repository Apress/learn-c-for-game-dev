// Chapter13-Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

void StringIterators(string myString)
{
	for (string::iterator iter = myString.begin(); iter != myString.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (string::iterator iter = myString.end()-1; iter != myString.begin(); --iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (string::reverse_iterator iter = myString.rbegin(); iter != myString.rend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (string::const_iterator iter = myString.cbegin(); iter != myString.cend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (string::const_reverse_iterator iter = myString.crbegin(); iter != myString.crend(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (auto iter = myString.begin(); iter != myString.end(); ++iter)
	{
		cout << *iter << endl;
	}

	for (auto iter = myString.cbegin(); iter != myString.cend(); ++iter)
	{
		cout << *iter << endl;
	}
	
	cout << endl << endl;

	for (auto &letter : myString)
	{
		letter = 'a';
		cout << letter << endl;
	}

	cout << endl << endl;

	for (string::iterator iter = myString.begin(); iter != myString.end(); ++iter)
	{
		*iter = 'a';
		cout << *iter << endl;
	}

	cout << endl << endl;

	for (string::const_iterator iter = myString.cbegin(); iter != myString.cend(); ++iter)
	{
		//*iter = 'a';
		cout << *iter << endl;
	}
}

void FindInString(string myString)
{
	size_t found = myString.find("is");
	if (found != string::npos)
	{
		cout << "is found at poisition: " << found << endl;
	}

	found = myString.find("is", found+1);
	if (found != string::npos)
	{
		cout << "is found at poisition: " << found << endl;
	}

	found = myString.rfind("is");
	if (found != string::npos)
	{
		cout << "is found at poisition: " << found << endl;
	}

	found = myString.rfind("is", found-1);
	if (found != string::npos)
	{
		cout << "is found at poisition: " << found << endl;
	}

	found = myString.find_first_of("msg");
	if (found != string::npos)
	{
		cout << "is found at poisition: " << found << endl;
	}
}

#include <sstream>
#include <iomanip>
#include <ios>
void StringStreamExample()
{
	stringstream myStringStream;

	myStringStream << "Hi" << endl;

	cout << "width: " << myStringStream.width() << endl;
	myStringStream << 123 << endl;
	myStringStream << setw(10) << 123 << endl;
	myStringStream << setw(0) << 123 << endl;

	myStringStream << 123.567 << endl;
	myStringStream << setprecision(4) << 123.567 << endl;
	myStringStream << fixed << setprecision(2) << 123.567 << endl;
	myStringStream << defaultfloat << setprecision(0) << 123.567 << endl;

	myStringStream << 110 << endl << showbase;
	myStringStream << hex << 110 << endl;
	myStringStream << oct << 110 << endl;
	myStringStream << dec << 110 << endl << noshowbase;

	string myString = myStringStream.str();
	cout << myString;
}

#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	string myString{ "This is my string!" };
	StringIterators(myString);
	FindInString(myString);
	StringStreamExample();

	return 0;
}

