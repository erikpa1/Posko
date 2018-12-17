#include "Rectangle.h"
#include "Math.h"

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
	Destruct();
}

void Rectangle::Construct()
{
	_source = new SDL_Rect();
	_color = new vec4();
	_color->x = 255;
	_color->y = 255;
	_color->z = 255;
	_color->w = 255;
	
}

void Rectangle::Destruct()
{
	delete _color;
	delete _source;
	_source = nullptr;
	_color = nullptr;
}

void Rectangle::Update()
{

}

void Rectangle::Draw()
{
	Renderable::Draw();
	SDL_SetRenderDrawColor(_renderer, _color->x, _color->y, _color->z, _color->w);
	SDL_RenderFillRect(_renderer, _source);
	//SDL_RenderPresent(_renderer);
}

void Rectangle::setX(int x)
{
	Renderable::setX(x);
	_source->x = x;	
}

void Rectangle::setY(int y)
{
	Renderable::setY(y);
	_source->y = y;
}

void Rectangle::setW(int w)
{
	Renderable::setW(w);
	_source->w = w;
}

void Rectangle::setH(int h)
{
	Renderable::setH(h);
	_source->h = h;
}

void Rectangle::SetColor(const vec4& color)
{
	_color->x = color.x;
	_color->y = color.y;
	_color->z = color.z;
	_color->w = color.w;
}
