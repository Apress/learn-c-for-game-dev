// Chapter5-ValueParameters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct SumParameters
{
	int		valueA;
	int		valueB;
	int		result;
};

void ReturnSum(SumParameters& params)
{
	params.result = params.valueA + params.valueB;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SumParameters sum;
	sum.valueA = 3;
	sum.valueB = 6;
	sum.result = 0;
	ReturnSum(sum);
	cout << sum.result << endl;

	return 0;
}