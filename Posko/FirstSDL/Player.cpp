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

void Player::Draw()
{
	_reprezentation->Draw();
}

void Player::Update()
{

}
