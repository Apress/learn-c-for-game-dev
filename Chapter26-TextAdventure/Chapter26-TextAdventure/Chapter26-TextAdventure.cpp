// Chapter26-TextAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameLoop.h"
#include <thread>

void RunGameThread(Game& game)
{
	game.RunGame();
}

int32_t _tmain(int32_t argc, _TCHAR* argv[])
{
	new SerializationManager();

	Game game;
	std::thread gameThread{ RunGameThread, std::ref{ game } };
	assert(gameThread.joinable());
	while (!game.HasFinished())
	{
		// Stick a breakpoint below to see that this code
		// is running at the same time as RunGame!
		int32_t x = 0;
	}
	gameThread.join();

	delete SerializationManager::GetSingletonPtr();

	return 0;
}

