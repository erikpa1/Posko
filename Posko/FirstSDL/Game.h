#pragma once
#include <vector>
#include "EventReciever.h"
#include <SDL.h>

class Window;
class Player;
class Ball;

class Game : public EventReciever
{
public:

	void Construct();
	void Destruct();
	
	void Start();
	void Stop();

	void RecieveEvent(SDL_Event event) override;


	//Players

	void ChangePosition(bool up, int amount, int player);

	//Ball
	void ballMovement(int direction);
	void detectColision();
	void resetBallPosition();
	   	 
private:

	//simulation state run
	bool _gameIsRunning = false;

	//players vector
	std::vector<Player*> _players;

	//window displayed on desktop
	Window* _gameWindow = nullptr;

	//inicialization of common player attributes
	void InitPlayer(Player* player);

	//game ball
	Ball* _ball = nullptr;

	//game score
	std::pair<int, int> _score = { 0 ,0 };



};
