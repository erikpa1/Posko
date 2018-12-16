#pragma once
#include <vector>
#include "EventReciever.h"
#include <SDL.h>
#include "Socket.h"

class Window;
class Player;
class Ball;
class NetworkReciever;

class Game : public EventReciever, NetworkReciever
{
public:

	void Construct();
	void Destruct();
	
	void Start();
	void Stop();
	void RecieveMessage(std::string message) override;

	void RecieveEvent(SDL_Event event) override;


	//Players
	void ChangePosition(bool up, int amount, int player);


	   	 
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

	Socket _socket;



};
