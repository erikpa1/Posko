#pragma once
#include <SDL.h>

class EventReciever
{
public:
	virtual void RecieveEvent(SDL_Event event) = 0;
};