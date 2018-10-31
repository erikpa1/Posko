#pragma once
#include "Renderable.h"

class vec4;

class Rectangle : public Renderable
{
public:

	Rectangle();
	~Rectangle();

	void Construct() override;
	void Destruct() override;

	void Update() override;
	
	void Draw() override;

	void setX(int x) override;
	void setY(int y) override;
	void setW(int w) override;
	void setH(int h) override;

	void SetColor(const vec4 & color);
	
private:

	SDL_Rect* _source = nullptr;
	SDL_Rect* _destination = nullptr;
	SDL_Texture* _texture = nullptr;
	SDL_Surface* _surface = nullptr;

	vec4 * _color;

};
