#include "Window.h"
#include "SDL.h"
#include <ostream>
#include <iostream>


Window::Window()
{
}


Window::~Window()
{
}

void Window::Update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		
		
		switch(event.type)
		{
			
		}

		for (auto temp : _children)
		{
			temp->UpdateEvent(event);
		}
	}
	
	for (auto temp : _children)
	{
		temp->Update();
	}
}

void Window::Draw()
{
	SDL_RenderClear(_renderer);
	SDL_SetRenderDrawColor(_renderer, _backgroundColor.x, _backgroundColor.y, _backgroundColor.z, _backgroundColor.w);
	
	if (!_children.empty())
	{
		for (auto temp : _children)
		{
			temp->Draw();
		}
	}		
	SDL_RenderPresent(_renderer);
}

void Window::UpdateEvent(SDL_Event sdlEvent)
{
	
}

void Window::AddChildren(Renderable* children)
{
	Renderable::AddChildren(children);
	children->SetRenderer(_renderer);
}

void Window::Construct()
{
	_isRunning = true;
	
	_backgroundColor.x = 0;
	_backgroundColor.y = 0;
	_backgroundColor.z = 0;
	_backgroundColor.w = 255;

	_w = 800;
	_h = 600;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Failed to load SDL" << std::endl;
	}

	_window = SDL_CreateWindow("Pong", 100, 100, _w, _h, SDL_WINDOW_RESIZABLE);
	_renderer = SDL_CreateRenderer(_window, -1, 0);

}

void Window::Destruct()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();

	delete this;
}
