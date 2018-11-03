#pragma once
#include "Renderable.h"
#include "Math.h"
#include <vector>
#include "EventReciever.h"


class Window : public Renderable
{

public:

	Window();
	~Window();

	void Construct() override;
	void Destruct() override;

	void Update() override;
	void Draw() override;
	void UpdateEvent(SDL_Event sdlEvent) override;

	void AddEventRecievers(EventReciever * reciever);
	void AddChildren(Renderable* children) override;
	   	

private:

	SDL_Window * _window;	

	std::vector<EventReciever*> _recievers;

	vec4 _backgroundColor;

	bool _isRunning = true;
};

