﻿#include <iostream>
#include "stdlib.h"
#include "Game.h"
#include "Window.h"
#include "Player.h"
#include "Ball.h"


#define PLAYER_MOVEMENT 10
#define BALL_MOVEMENT 2
#define	STARTOFWINDOW 0

//ball movement directions
#define UPRIGHT 0
#define DOWNRIGHT 1
#define RIGHT 2
#define UPLEFT 3
#define DOWNLEFT 4
#define LEFT 5

void Game::Construct()
{
	_gameWindow = new Window();
	_gameWindow->Construct();
	_gameWindow->SetName("Game canvas");
	_gameIsRunning = true;

	std::cout << "Window width: " << _gameWindow->getW() << std::endl;
	std::cout << "Window height: " << _gameWindow->getH() << std::endl;

	_players.push_back(new Player());
	_players.push_back(new Player());

	_players[0]->Construct();
	_players[1]->Construct();

	_players[0]->SetName("Player1");
	_players[1]->SetName("Player2");

	InitPlayer(_players[0]);
	InitPlayer(_players[1]);

	_ball = new Ball();
	_ball->Construct();
	_ball->SetName("Game ball");
	_ball->setW(10);
	_ball->setH(10);

	_ball->setX(_gameWindow->getH() / 2 - _ball->getH() / 2);
	_ball->setY(_gameWindow->getW() / 2 - _ball->getW() / 2);

	_gameWindow->AddChildren(_players[0]);
	_gameWindow->AddChildren(_players[1]);
	_gameWindow->AddChildren(_ball);
	_gameWindow->AddEventRecievers(this);
		
	_players[0]->setX(0);	
	_players[1]->setX(_gameWindow->getW() - _players[1]->getW());


}

void Game::Destruct()
{
	_gameWindow->Destruct();
	_gameWindow = nullptr;
}

void Game::Start()
{
	if (_gameWindow != nullptr)
	{
		while (_gameIsRunning)
		{
			_gameWindow->Update();
			_gameWindow->Draw();						
		}
	} else
	{
		std::cout << "Window je null" << std::endl;
	}
	
}

void Game::Stop()
{

}

void Game::RecieveEvent(SDL_Event event)
{
	std::cout << "Game prijala " << event.type << endl;
	
	if (event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_UP:
			ChangePosition(true, 10, 0);
			break;

			case SDLK_DOWN:
			ChangePosition(false, 10, 0);
			break;			
		}
	}

	
}

void Game::InitPlayer(Player* player)
{	
	player->setW(20);
	player->setH(70);
	player->setY(_gameWindow->getH() / 2 - player->getH() / 2);
}

void Game::ChangePosition(bool up, int amount, int playerChoose)
{
	auto helper = _players[0];

	if(up)
	{
		if ((helper->getY() - PLAYER_MOVEMENT) >= STARTOFWINDOW)
		{
			helper->setY(helper->getY() - PLAYER_MOVEMENT);
		}
	}
	else
	{
		if ((helper->getY() + helper->getH() + PLAYER_MOVEMENT) <= _gameWindow->getH())
		{
			helper->setY(helper->getY() + PLAYER_MOVEMENT);
		}
	}
}
