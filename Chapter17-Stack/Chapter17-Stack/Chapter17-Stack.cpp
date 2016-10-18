// Chapter17-Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include "stdafx.h"
#include <stack>
#include <queue>
#include <string>
#include <iostream>

using namespace std;
using MyStack = stack<int>;
using MyQueue = queue<int>;

#include <array>
int _tmain(int argc, _TCHAR* argv[])
{
	MyStack myStack;
	myStack.emplace(0);
	myStack.emplace(1);
	myStack.emplace(2);

	cout << "Top of the stack: " << myStack.top() << endl;

	myStack.pop();

	cout << "Top of the stack: " << myStack.top() << endl;

	myStack.emplace(2);

	cout << "Top of the stack: " << myStack.top() << endl;
	
	myStack.pop();
	myStack.pop();

	cout << "Top of the stack: " << myStack.top() << endl;

	MyQueue myQueue;
	myQueue.emplace(0);
	myQueue.emplace(1);
	myQueue.emplace(2);

	cout << "Front of the queue: " << myQueue.front() << endl;

	myQueue.pop();

	cout << "Front of the queue: " << myQueue.front() << endl;

	myQueue.emplace(2);

	cout << "Front of the queue: " << myQueue.front() << endl;

	myQueue.pop();
	myQueue.pop();

	cout << "Front of the queue: " << myQueue.front() << endl;

	return 0;
}

