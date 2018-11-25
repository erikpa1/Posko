#pragma once
#include <vector>

class Socket;
class Player;
class Ball;

class AppControll
{

private:

	//Web connection
	Socket * _socket;

	//Player part
	Ball * _ball;
	std::vector<Player*> _players;


public:

	void Construct();
	void Destruct();
	void Start();


};
