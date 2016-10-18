// Chapter22-StackMemory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void function2(int variable1)
{
	int variable2{ variable1 };
}

void function1(int variable)
{
	function2(variable);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int variable{ 0 };
	function1(variable);

	return 0;
}

