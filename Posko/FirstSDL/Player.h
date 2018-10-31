#pragma once
#include "Renderable.h"

class Rectangle;

class Player : public Renderable
{
public:

	Player();
	~Player();

	void Construct() override;
	void Destruct() override;

	void Draw() override;

	void Update() override;

private:

	Rectangle* _reprezentation = nullptr;




};
