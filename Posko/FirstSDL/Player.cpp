#include "Player.h"
#include "Rectangle.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::Construct()
{
	_reprezentation = new Rectangle();
	_reprezentation->Construct();
}

void Player::Destruct()
{
	_reprezentation->Destruct();
}

void Player::setX(int x)
{
	Renderable::setX(x);
	_reprezentation->setX(x);
}

void Player::setY(int y)
{
	Renderable::setY(y);
	_reprezentation->setY(y);
}

void Player::setW(int w)
{
	Renderable::setW(w);
	_reprezentation->setW(w);
}

void Player::setH(int h)
{
	Renderable::setH(h);
	_reprezentation->setH(h);
}

void Player::SetName(std::string name)
{
	_reprezentation->SetName("Reprezentation of " + name);
}

void Player::Draw()
{	
	_reprezentation->Draw();	
}

void Player::Update()
{

}
