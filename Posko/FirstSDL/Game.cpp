#include <iostream>

#include "Game.h"
#include "Window.h"
#include "Player.h"




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

void Game::InitPlayer(Player* player)
{	
	player->Construct();
	player->setW(5);
	player->setH(10);
	player->setX(_gameWindow->getH() / 2 - player->getH() / 2);
}
