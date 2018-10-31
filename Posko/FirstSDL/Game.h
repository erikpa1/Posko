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

	void changePosition(bool up, int amount, int player);

private:

	bool _gameIsRunning = false;

	Window* _gameWindow = nullptr;
	Player* _player1 = nullptr;
	Player* _player2 = nullptr;
	std::vector<Player*> _players;
	void InitPlayer(Player** player);


};
