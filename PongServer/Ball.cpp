#include "Ball.h"

Ball::Ball()
{

}

Ball::~Ball()
{
}

void Ball::Construct()
{

}

void Ball::Destruct()
{

}

void Ball::setX(int x)
{
	Renderable::setX(x);

}

void Ball::setY(int y)
{
	Renderable::setY(y);

}

void Ball::setW(int w)
{
	Renderable::setW(w);

}

void Ball::setH(int h)
{
	Renderable::setH(h);
	
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


void Ball::SetName(std::string name)
{
	Renderable::SetName(name);
}

void Ball::Draw()
{

}

void Ball::Update()
{

}

