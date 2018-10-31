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

	_players[0]->Construct();
	_players[1]->Construct();

	_players[0]->SetName("Player1");
	_players[1]->SetName("Player2");

	InitPlayer(_players[0]);
	InitPlayer(_players[1]);

	_gameWindow->AddChildren(_players[0]);
	_gameWindow->AddChildren(_players[1]);
		
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

			int newPose = (_players[0]->getY() + 1) % _gameWindow->getH();			
			_players[0]->setY(newPose);
						
		}
	} else
	{
		std::cout << "Window je null" << std::endl;
	}
	
}

void Game::Stop()
{

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
