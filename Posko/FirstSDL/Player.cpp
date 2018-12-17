#include "Player.h"
#include "Rectangle.h"
#include "Math.h"

Player::Player()
{

}

Player::~Player()
{
	Destruct();
}

void Player::Construct()
{
	_reprezentation = new Rectangle();
	_reprezentation->Construct();
}

void Player::Destruct()
{
	delete _reprezentation;
	_reprezentation = nullptr;
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

void Player::SetRenderer(SDL_Renderer* renderer)
{
	Renderable::SetRenderer(renderer);
	_reprezentation->SetRenderer(renderer);
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

void Player::SetRandomColor()
{
	vec4 color;
	color.x = 150 + rand() % 100;
	color.y = 150 + rand() % 100;
	color.z = 150 + rand() % 100;
	color.x = 150 + rand() % 100;

	_reprezentation->SetColor(color);
}