// Chapter5-TextAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Player
{
	string m_name;
};

void WelcomePlayer(Player& player)
{
	cout << "Welcome to Text Adventure!" << endl << endl;
	cout << "What is your name?" << endl << endl;

	cin >> player.m_name;

	cout << endl << "Hello " << player.m_name << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Player player;
	WelcomePlayer(player);

	return 0;
}

