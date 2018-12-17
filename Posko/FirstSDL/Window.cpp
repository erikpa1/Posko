#include "Window.h"
#include "SDL.h"
#include <ostream>
#include <iostream>


Window::Window()
{
}

void Window::Construct()
{
	_isRunning = true;

	_backgroundColor.x = 0;
	_backgroundColor.y = 0;
	_backgroundColor.z = 0;
	_backgroundColor.w = 255;

	_x = 500;
	_y = 500;
	_w = 1000;
	_h = 500;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Failed to load SDL" << std::endl;
	}

	_window = SDL_CreateWindow("Pong", _x, _y, _w, _h, SDL_WINDOW_RESIZABLE);
	_renderer = SDL_CreateRenderer(_window, -1, 0);

}

void Window::Destruct()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);	
	SDL_Quit();	
}


Window::~Window()
{
	Destruct();
}

void Window::Update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		
		
		switch(event.type)
		{
			
		}
		for (auto temp : _recievers)
		{
			temp->RecieveEvent(event);
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

	SDL_SetRenderDrawColor(_renderer, _backgroundColor.x, _backgroundColor.y, _backgroundColor.z, _backgroundColor.w);
	SDL_RenderClear(_renderer);
	
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

void Window::SetWindowTitle(std::string name)
{
	SDL_SetWindowTitle(_window, name.c_str());
}

void Window::AddEventRecievers(EventReciever * reciever)
{
	_recievers.push_back(reciever);
}

void Window::AddChildren(Renderable* children)
{
	Renderable::AddChildren(children);
	children->SetRenderer(_renderer);
}


