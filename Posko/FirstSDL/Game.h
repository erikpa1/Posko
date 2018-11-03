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

	//Players
	void ChangePosition(bool up, int amount, int player);

	//Ball
	void ballMovement(int direction);
	void detectColision();
	void resetBallPosition();
	   	 
private:

	bool _gameIsRunning = false;

	std::vector<Player*> _players;
	
	Window* _gameWindow = nullptr;
	void InitPlayer(Player* player);

	Ball* _ball = nullptr;
};
