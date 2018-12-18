#include "Ball.h"
#include "Rectangle.h"
#include "Math.h"

Ball::Ball()
{

}

Ball::~Ball()
{
	Destruct();
}

void Ball::Construct()
{
	_reprezentation = new Rectangle();
	_reprezentation->Construct();
}

void Ball::Destruct()
{
	delete _reprezentation;
}

void Ball::setX(int x)
{
	Renderable::setX(x);
	_reprezentation->setX(x);
}

void Ball::setY(int y)
{
	Renderable::setY(y);
	_reprezentation->setY(y);
}

void Ball::setW(int w)
{
	Renderable::setW(w);
	_reprezentation->setW(w);
}

void Ball::setH(int h)
{
	Renderable::setH(h);
	_reprezentation->setH(h);
}

void Ball::setUp(bool up)
{
	this->up = up;
}

void Ball::setDown(bool down)
{
	this->down = down;
}

void Ball::setLeft(bool left)
{
	this->left = left;
}

void Ball::setRight(bool right)
{
	this->right = right;
}

bool Ball::getUp()
{
	return this->up;
}

bool Ball::getDown()
{
	return this->down;
}

bool Ball::getLeft()
{
	return this->left;
}

bool Ball::getRight()
{
	return this->right;
}

void Ball::SetRenderer(SDL_Renderer * renderer)
{
	Renderable::SetRenderer(renderer);
	_reprezentation->SetRenderer(renderer);
}

void Ball::SetName(std::string name)
{
	_reprezentation->SetName("Reprezentation of " + name);
}

void Ball::SetRandomColor()
{
	vec4 color;
	color.x = 150+ rand() % 100;
	color.y = 150+ rand() % 100;
	color.z = 150+ rand() % 100;
	color.x = 150+ rand() % 100;
	
	_reprezentation->SetColor(color);
}

void Ball::Draw()
{
	_reprezentation->Draw();
}

void Ball::Update()
{

}

