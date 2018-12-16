#include <iostream>
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

	_gameWindow->AddChildren(_players[0]);
	_gameWindow->AddChildren(_players[1]);
	_gameWindow->AddChildren(_ball);
	_gameWindow->AddEventRecievers(this);
	
	_socket.SetNetworkReciever(this);
	_socket.Contruct();

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

void Game::RecieveMessage(std::string message)
{
	sf::Vector2i position;

	position = ExtractPosition(message);
	if (message.at(0) == 'B')
	{
		_ball->setX(position.x);
		_ball->setY(position.y);
	}
	if (message.at(0) == '0' || message.at(0) == '1')
	{
		int player = message.at(0) == '0' ? 0 : 1;
		_players[player]->setX(position.x);
		_players[player]->setY(position.y);
	}
}

sf::Vector2i Game::ExtractPosition(std::string message)
{
	int x;
	int y;

	int x_textsize = 0;
	int x_lastfoundposition = 0;
	for (int i = 2; i < 5; i++)
	{
		if (message.at(i) == ';')
		{
			x_lastfoundposition = i;
			break;
		}
		else
		{
			x_textsize++;
		}
	}
	int y_textsize = 0;
	int y_lastfoundposition = 0;
	for (int i = x_lastfoundposition + 2; i < 2 + x_lastfoundposition + 3; i++)
	{
		if (message.at(i) == ';')
		{
			y_lastfoundposition = i;
			break;
		}
		else
		{
			y_textsize++;
		}
	}

	string x_final = string(message.substr(2, x_textsize)).c_str();
	string y_final = string(message.substr(x_textsize + 3, y_textsize)).c_str();


	x = stoi(x_final.c_str());
	y = stoi(y_final.c_str());

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
			//ChangePosition(true, 10, 1);
			_socket.SendToServer("11");
			break;
			case SDLK_DOWN:
			//ChangePosition(false, 10, 1);
			_socket.SendToServer("10");
			break;
			case SDLK_w:
			//ChangePosition(true, 10, 0);
			_socket.SendToServer("01");
			break;
			case SDLK_s:
			_socket.SendToServer("00");
			//ChangePosition(false, 10, 0);
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
