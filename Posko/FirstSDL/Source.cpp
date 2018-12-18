#pragma once
#include "Game.h"
#include "heap_monitor.h"

int main(int argc, char* argv[]) {
	
	initHeapMonitor();

	try
	{
		Game game;
		game.Construct();
		game.Start();
		game.Destruct();

	} catch (std::exception)
	{
	}
	
	return 0;
}
