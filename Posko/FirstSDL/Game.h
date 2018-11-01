#pragma once
#include <vector>

class Window;
class Player;
class Ball;

class Game
{
public:

	void Construct();
	void Destruct();

	void Start();
	void Stop();

	void ChangePosition(bool up, int amount, int player);
	void ballMovement(int direction);
	void resetBallposition();
	   	 
private:

	bool _gameIsRunning = false;

	std::vector<Player*> _players;
	
	Window* _gameWindow = nullptr;
	void InitPlayer(Player* player);

	Ball* _ball = nullptr;
};
