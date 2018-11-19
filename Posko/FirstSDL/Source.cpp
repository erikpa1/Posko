#pragma once
#include "Game.h"
#include <iostream>


int main(int argc, char* argv[]) {

	std::string mystring;
	mystring.resize(100);
	std::cout << "My string" << mystring[20];

	Game game;
	game.Construct();
	game.Start();
	game.Destruct();

	

	
	return 0;
}
