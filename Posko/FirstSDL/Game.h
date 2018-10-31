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

	std::vector<Player*> _players;
	
	Window* _gameWindow = nullptr;
<<<<<<< HEAD

	void InitPlayer(Player* player);
=======
	Player* _player1 = nullptr;
	Player* _player2 = nullptr;
	std::vector<Player*> _players;
	void InitPlayer(Player** player);
>>>>>>> 4716e5cbf4d68d04e6ba267abe9eda6ec390d6d8


};
