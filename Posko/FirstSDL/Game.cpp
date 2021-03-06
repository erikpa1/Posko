﻿#include <iostream>
#include "stdlib.h"
#include "Game.h"
#include "Window.h"
#include "Player.h"
#include "Ball.h"


#define PLAYER_MOVEMENT 10
#define BALL_MOVEMENT 1
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
	_ball->SetName("Gam e ball");
	_ball->setW(10);
	_ball->setH(10);

	_gameWindow->AddChildren(_players[0]);
	_gameWindow->AddChildren(_players[1]);
	_gameWindow->AddChildren(_ball);
	_gameWindow->AddEventRecievers(this);
	
	_socket.SetNetworkReciever(this);
	_socket.Contruct();

}

void Game::Destruct()
{
	delete _gameWindow;
	delete _ball;
	delete _players[0];
	delete _players[1];

	_players.clear();

	_gameWindow = nullptr;
	_ball = nullptr;
	
}

void Game::Start()
{
	if (_gameWindow != nullptr)
	{
		while (_gameIsRunning)
		{
			if (_endreqeusted == true)
			{
				break;
			}

			_gameWindow->Update();
			_gameWindow->Draw();	
			_gameWindow->SetWindowTitle(_score);
		}
	} else
	{
		std::cout << "Window je null" << std::endl;
	}

	std::cout << "Ending" << endl;
	
}

void Game::Stop()
{

}

void Game::RecieveMessage(std::string message)
{
	sf::Vector2i position;

	if (message.at(0) == 'S')
	{
		_score = "Skore je: " + message.substr(1, message.find(";")-1);		
	}
	   
	if (message.find("END") == 0)
	{
		_endreqeusted = true;
		_socket.Stop();
	} else
	{
		if (message.at(0) == 'R')
		{
			_ball->SetRandomColor();
			if (message.at(1) == '0')
			{
				_players[0]->SetRandomColor();
			}
			else
			{
				_players[1]->SetRandomColor();
			}
		}
		if (message.at(0) == 'B')
		{
			position = ExtractPosition(message);
			_ball->setX(position.x);
			_ball->setY(position.y);
		}
		if (message.at(0) == 'P')
		{
			position = ExtractPosition(message);

			_players[0]->setX(position.x);
			_players[0]->setY(position.y);

			int secondPlayer = 0;
			int found = 0;

			for (int i = 0; i < message.length(); i++)
			{
				if (message.at(i) == 'P')
				{
					if (found == 1)
					{
						secondPlayer = i;
					}
					else
					{
						found = 1;
					}
				}
			}

			string newmesasge = message.substr(secondPlayer, message.length() - 1);

			position = ExtractPosition(newmesasge);

			_players[1]->setX(position.x);
			_players[1]->setY(position.y);
		}
	}	
}

sf::Vector2i Game::ExtractPosition(std::string message)
{
	int x;
	int y;

	string tempmessage = message.substr(2, message.length() - 1);

	int delimeter = tempmessage.find(";");
	string string_x = tempmessage.substr(0, delimeter);

	string string_y = tempmessage.substr(delimeter+1, message.length()-1 );
	
	try
	{
		x = stoi(string_x);
		y = stoi(string_y);

	} catch(exception)
	{
		cout << "Doslo k chybe medzi paketmi" << endl;
		x = 0;
		y = 0;
	}
	
	return sf::Vector2i(x, y);

		
}

void Game::RecieveEvent(SDL_Event event)
{
	//std::cout << "Game prijala " << event.type << endl;
	
	if (event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
			case SDLK_UP:			
			_socket.SendToServer("11");
			break;
			case SDLK_DOWN:			
			_socket.SendToServer("10");
			break;			
			case SDLK_ESCAPE:
			_socket.SendToServer("END");
			_endreqeusted = true;
			_socket.Stop();
			cout << "Stop called from my iniciativy" << endl;
			break;
		}

		switch(event.key.keysym.sym)
		{
			case SDLK_w:			
			_socket.SendToServer("01");
			break;
			case SDLK_s:
			_socket.SendToServer("00");			
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
	auto helper = _players[playerChoose];

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
