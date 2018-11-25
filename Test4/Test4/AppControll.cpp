#include "AppControll.h"
#include "Socket.h"
#include "Ball.h"
#include "Player.h"

void AppControll::Construct()
{
	_socket = new Socket(123456);
	_socket->Consturct();
	_players.push_back(new Player());
	_players.push_back(new Player());
	_ball = new Ball();	
}

void AppControll::Destruct()
{
	_socket->Destruct();
	delete _socket;
	_socket = nullptr;
}

void AppControll::Start()
{
	   
}
