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

	void ChangePosition(bool up, int amount, int player);
	   	 
private:

	bool _gameIsRunning = false;

	std::vector<Player*> _players;
	
	Window* _gameWindow = nullptr;
	void InitPlayer(Player* player);


};
