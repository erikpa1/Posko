#pragma once
#include <vector>

class Window;
class Player;

class Game
{
public:

	void Construct();
	void Destruct();

	void Start();
	void Stop();




private:

	bool _gameIsRunning = false;

	std::vector<Player*> _players;
	
	Window* _gameWindow = nullptr;

	void InitPlayer(Player* player);


};
