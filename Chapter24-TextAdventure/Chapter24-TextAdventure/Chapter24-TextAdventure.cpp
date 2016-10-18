// Chapter24-TextAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameLoop.h"


int _tmain(int argc, _TCHAR* argv[])
{
	new SerializationManager();

	Game game;
	game.RunGame();

	delete SerializationManager::GetSingletonPtr();

	return 0;
}

