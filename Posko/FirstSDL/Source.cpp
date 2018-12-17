#pragma once
#include "Game.h"
#include <iostream>


int main(int argc, char* argv[]) {
	
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
