#pragma once


#include <vector>
#include <string>
#include <iostream>
//#include "Socket.h"

class vec4;

class Renderable
{
public:

	virtual void Update() = 0;
	virtual void Construct() = 0;

	virtual void Draw();
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

	//virtual void SetSocket(Socket * socket);
	//virtual void UpdateNetworkAlternative();

protected:

	int _x = 0;
	int _y = 0;
	int _w = 0;
	int _h = 0;

	//Socket * _socket = nullptr;
	std::string _name;
	std::vector<Renderable*> _children;

	
};

inline void Renderable::Draw()
{
	//this->PrintYourSelf();
}



inline void Renderable::Destruct()
{

}

inline int Renderable::getX()
{
	return _x;
}

inline int Renderable::getY()
{
	return _y;
}

inline int Renderable::getW()
{
	return _w;
}

inline int Renderable::getH()
{
	return _h;
}

inline void Renderable::setX(int x)
{
	_x = x;
	//std::cout << _name << " has setted X to: " << _x << std::endl;
}

inline void Renderable::setY(int y)
{
	_y = y;
	//std::cout << _name << " has setted Y to: " << _y << std::endl;
}

inline void Renderable::setW(int w)
{
	_w = w;
	//std::cout << _name << " has setted w to: " << _w << std::endl;
}

inline void Renderable::setH(int h)
{
	_h = h;
	//std::cout << _name << " has setted H to: " << _h << std::endl;
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
/*
inline void Renderable::SetSocket(Socket* socket)
{
	_socket = socket;
}

inline void Renderable::UpdateNetworkAlternative()
{
	std::string messageToSend;		messageToSend += ";";
	messageToSend += _name;
	messageToSend += _x + ";";
	messageToSend += _y + ";";
	messageToSend += _w + ";";
	messageToSend += _h + ";";

	if (_socket != nullptr)
	{
		_socket->SendToClients(messageToSend);
	}

}
*/