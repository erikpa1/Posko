#include "Player.h"
#include "Socket.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Construct()
{
	
}

void Player::Destruct()
{
	
}

void Player::setX(int x)
{
	Renderable::setX(x);	
}

void Player::setY(int y)
{
	Renderable::setY(y);	
}

void Player::setW(int w)
{
	Renderable::setW(w);	
}

void Player::setH(int h)
{
	Renderable::setH(h);	
}



void Player::SetName(std::string name)
{
	
}

void Player::SetSocket(Socket* socket)
{
	_socket = socket;
}

void Player::UpdateNetworkAlternative()
{
	std::string messageToSend;
	messageToSend += "0";
	messageToSend += ";";
	messageToSend += _name;
	messageToSend += _x+";";
	messageToSend += _y+";";
	messageToSend += _w+";";
	messageToSend += _h+";";

	if (_socket != nullptr)
	{
		_socket->SendToClients(messageToSend);
	}
}

void Player::Draw()
{	
	
}

void Player::Update()
{

}
