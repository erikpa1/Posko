#pragma once
#include "Renderable.h"
#include "Math.h"
#include <vector>


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
	void AddChildren(Renderable* children) override;

private:

	SDL_Window * _window;	
	
	vec4 _backgroundColor;

	bool _isRunning = true;
};

