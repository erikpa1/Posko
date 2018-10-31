#pragma once

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

	Window* _gameWindow = nullptr;
	Player* _player1 = nullptr;
	Player* _player2 = nullptr;

	void InitPlayer(Player** player);


};
