#pragma once
#include "Renderable.h"
#include <iostream>

using namespace  std;

class Rectangle;

class Ball : public Renderable
{
public:

	Ball();
	~Ball();

	void Construct() override;
	void Destruct() override;

	void setX(int x) override;
	void setY(int y) override;
	void setW(int w) override;
	void setH(int h) override;
	void setUp(bool up);
	void setDown(bool down);
	void setLeft(bool left);
	void setRight(bool right);
	bool getUp();
	bool getDown();
	bool getLeft();
	bool getRight();
	//void SetRenderer(SDL_Renderer* renderer) override;
	void SetName(std::string name) override;

	void Draw() override;
	void Update() override;

private:

	Rectangle* _reprezentation = nullptr;
	//urobil som to inac takze asi ich ani nebude treba a ball bude moct byt iba dalsia instancia hraca
	bool up = true;
	bool down = true;
	bool left = true;
	bool right =  true;
};


