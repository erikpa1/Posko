#pragma once
#include <vector>
#include <iostream>

class Socket;
class Player;
class Ball;

class AppControll
{

public:

	void Construct();
	void Destruct();
	void Start();
	void InitPlayer(Player * player);

private:
	void SendToClient();
	void ReadFromClinet();
	void Update();


private:
	int _w = 800;
	int _h = 600;

	Socket * _socket;
	Ball * _ball;

	std::vector<Player*> _players;


};
