// Chapter4-CStyleString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char cStyleString1[13];
	strcpy(cStyleString1, "CStyle");
	char* cStyleString2 = "String";
	strcat(cStyleString1, cStyleString2);

	cout << cStyleString1 << endl;

	return 0;
}

