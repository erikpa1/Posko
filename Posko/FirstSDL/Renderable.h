#pragma once

#include "SDL.h"
#include <vector>
#include <string>
#include <iostream>

class vec4;

class Renderable
{
public:

	virtual void Update() = 0;
	virtual void Construct() = 0;

	virtual void Draw();
	virtual void UpdateEvent(SDL_Event sdlEvent);
	virtual void Destruct();

	virtual int getX();
	virtual int getY();
	virtual int getW();
	virtual int getH();

	virtual void setX(int x);
	virtual void setY(int y);
	virtual void setW(int w);
	virtual void setH(int h);

	virtual void SetName(std::string name);
	virtual void PrintYourSelf(std::vector<std::string> * dataFiller = nullptr);

	virtual void AddChildren(Renderable* children);

	void SetRenderer(SDL_Renderer * renderer);

protected:

	int _x;
	int _y;
	int _w;
	int _h;

	std::string _name;

	SDL_Renderer * _renderer = nullptr;
	std::vector<Renderable*> _children;

	
};

inline void Renderable::Draw()
{
	this->PrintYourSelf();
}

inline void Renderable::UpdateEvent(SDL_Event sdlEvent)
{

}

inline void Renderable::Destruct()
{

}

inline int Renderable::getX()
{
	return 0;
}

inline int Renderable::getY()
{
	return 0;
}

inline int Renderable::getW()
{
	return 0;
}

inline int Renderable::getH()
{
	return 0;
}

inline void Renderable::setX(int x)
{
	_x = x;
}

inline void Renderable::setY(int y)
{
	_y = y;
}

inline void Renderable::setW(int w)
{
	_w = w;
}

inline void Renderable::setH(int h)
{
	_h = h;
}

inline void Renderable::SetName(std::string name)
{
	_name = name;
}

inline void Renderable::PrintYourSelf(std::vector<std::string>* dataFiller)
{
	std::vector<std::string> texts;

	texts.push_back(_name);
	texts.push_back("X: " + std::to_string(_x));
	texts.push_back("Y: " + std::to_string(_y));
	texts.push_back("W: " + std::to_string(_w));
	texts.push_back("H: " + std::to_string(_h));

	if (dataFiller != nullptr)
	{
		for (auto temp : texts)
		{
			dataFiller->push_back(temp);
		}
	} else
	{
		for (auto temp : texts)
		{
			std::cout << temp << std::endl;
		}
	}
}

inline void Renderable::AddChildren(Renderable* children)
{
	_children.push_back(children);
}

inline void Renderable::SetRenderer(SDL_Renderer* renderer)
{
	_renderer = renderer;
}
