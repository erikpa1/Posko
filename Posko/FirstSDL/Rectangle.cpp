#include "Rectangle.h"
#include "Math.h"

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::Construct()
{
	_source = new SDL_Rect();
	_destination = new SDL_Rect();
	_surface = SDL_CreateRGBSurface(0, 10, 10, 1, 150, 150, 150, 255);
	_texture = SDL_CreateTextureFromSurface(_renderer, _surface);
	_color = new vec4();
	
}

void Rectangle::Destruct()
{
	delete _color;
	delete _source;
	delete _destination;
	delete _surface;
	SDL_DestroyTexture(_texture);
}

void Rectangle::Update()
{

}

void Rectangle::Draw()
{
	Renderable::Draw();
	SDL_RenderCopy(_renderer, _texture, _source, _destination);
}

void Rectangle::setX(int x)
{
	Renderable::setX(x);
	_source->x = x;
	_destination->x = x;
}

void Rectangle::setY(int y)
{
	Renderable::setY(y);
	_source->y = y;
	_destination->y = y;
}

void Rectangle::setW(int w)
{
	Renderable::setW(w);
	_source->w = w;
	_destination->w = w;
}

void Rectangle::setH(int h)
{
	Renderable::setH(h);
	_source->h = h;
	_destination->h = h;
}

void Rectangle::SetColor(const vec4& color)
{
	_color->x = color.x;
	_color->y = color.y;
	_color->z = color.z;
	_color->w = color.w;
}
