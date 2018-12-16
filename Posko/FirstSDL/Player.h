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

	void setX(int x) override;
	void setY(int y) override;
	void setW(int w) override;
	void setH(int h) override;
	void SetRenderer(SDL_Renderer* renderer) override;
	void SetName(std::string name) override;
	void SetRandomColor();

	void Draw() override;

	void Update() override;

private:

	Rectangle* _reprezentation = nullptr;




};
