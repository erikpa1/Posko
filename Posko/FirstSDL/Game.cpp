#include <iostream>
#include "stdlib.h"
#include "Game.h"
#include "Window.h"
#include "Player.h"

#define MOVEMENT 10
#define	STARTOFWINDOW 0



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

	_players[0]->SetName("Player1");
	_players[1]->SetName("Player2");
	
	this->InitPlayer(_players[0]);
	this->InitPlayer(_players[1]);

	_gameWindow->AddChildren(_players[0]);
	_gameWindow->AddChildren(_players[1]);
		
	_players[0]->setY(0);	
	_players[1]->setY(_gameWindow->getW() - _players[1]->getW());

	
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

<<<<<<< HEAD
void Game::InitPlayer(Player* player)
{	
	player->Construct();
	player->setW(5);
	player->setH(10);
	player->setX(_gameWindow->getH() / 2 - player->getH() / 2);
=======
void Game::changePosition(bool up, int amount, int playerChoose)
{
	auto helper = _players[0];

	if(up)
	{
		if ((helper->getX() + helper->getH() + MOVEMENT) < _gameWindow->getH())
		{
			helper->setX(helper->getX() + MOVEMENT);
		}
	}
	else
	{
		if ((helper->getX() - MOVEMENT) > STARTOFWINDOW)
		{
			helper->setX(helper->getX() - MOVEMENT);
		}
	}
}

void Game::InitPlayer(Player** player)
{
	*player = new Player();
	(*player)->Construct();
	(*player)->setW(5);
	(*player)->setH(10);
	(*player)->setX(_gameWindow->getH() / 2 - (*player)->getH() / 2);
>>>>>>> 4716e5cbf4d68d04e6ba267abe9eda6ec390d6d8
}
