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

	int _w = 800;
	int _h = 600;

public:

	void Construct();
	void Destruct();
	void Start();

	void InitPlayer(Player * player);


};
