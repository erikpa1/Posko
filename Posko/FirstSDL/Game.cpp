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

	this->InitPlayer(&_player1);
	this->InitPlayer(&_player2);

	_gameWindow->AddChildren(_player1);
	_gameWindow->AddChildren(_player2);

	_player1->SetName("Player1");
	_player2->SetName("Player2");

	_player1->setY(0);	
	_player2->setY(_gameWindow->getW() - _player2->getW());

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
}
