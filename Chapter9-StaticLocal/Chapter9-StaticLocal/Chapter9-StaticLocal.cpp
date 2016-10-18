// Chapter9-StaticLocal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "extern.h"

int globalVariable = 0;

namespace
{
	const unsigned int MAX_LOOPS = 10;
}

class StaticCounter
{
private:
	static int m_counter;

public:
	void IncrementCounter()
	{
		++m_counter;
	}
	
	void Print()
	{
		std::cout << m_counter << std::endl;
		int* address = &m_counter;
	}
};

class StaticCounterMethod
{
private:
	static int m_counter;

public:
	static void IncrementCounter()
	{
		++m_counter;
	}

	static void Print()
	{
		std::cout << m_counter << std::endl;
		int* address = &m_counter;
	}
};

class ConstantExample
{
	friend class ConstantExampleFriend;

private:
	int	m_counter;
	mutable int m_countGets;

	int GetCounter() const;

public:
	ConstantExample() : m_counter(0), m_countGets(0) {}
	void IncrementCounter();
};

inline int ConstantExample::GetCounter() const
{
	++m_countGets;
	return m_counter;
}

inline void ConstantExample::IncrementCounter()
{
	++m_counter;
}

class ConstantExampleFriend
{
public:
	int GetCounter(const ConstantExample& constantExample)
	{
		return constantExample.GetCounter();
	}
};

int StaticCounter::m_counter = 0;
int StaticCounterMethod::m_counter = 0;

void NomralLocalVariable()
{
	int x = 0;
	std::cout << x++ << std::endl;
}

void StaticLocalVariable()
{
	static int x = 0;
	std::cout << x++ << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ConstantExample example;
	ConstantExampleFriend exampleFriend;
	int count = exampleFriend.GetCounter(example);

	unsigned int arrayOfValues[MAX_LOOPS];
	for (unsigned int i = 0; i < MAX_LOOPS; ++i)
	{
		arrayOfValues[i] = i;
		IncrementGlobalCounters();
		std::cout << globalVariable << std::endl;
	}

	const char* const	NAME = "Bruce Sutherland";
	const char*			BOOK = "Learn C++ Game Development";
	char* const			YEAR = "2014";

	YEAR[0] = '3';

	NomralLocalVariable();
	NomralLocalVariable();

	StaticLocalVariable();
	StaticLocalVariable();

	StaticCounterMethod::Print();
	StaticCounterMethod::IncrementCounter();
	StaticCounterMethod::Print();

	StaticCounterMethod::Print();
	StaticCounterMethod::IncrementCounter();
	StaticCounterMethod::Print();

	return 0;
}

