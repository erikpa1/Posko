#pragma once
#include "Game.h"


int main(int argc, char* argv[]) {

	Game game;
	game.Construct();
	game.Start();
	game.Destruct();



	
	return 0;
}
