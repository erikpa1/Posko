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

	_gameWindow->AddChildren(_players[0]);
	_gameWindow->AddChildren(_players[1]);
		
	_players[0]->setX(0);	
	_players[1]->setX(_gameWindow->getW() - _players[1]->getW());

	_ball = new Ball();
	_ball->Construct();
	_ball->SetName("Game ball");	
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

void Game::ballMovement(int direction)
{
	switch (direction)
	{
	case UPRIGHT:
		_ball->setY(_ball->getY() - BALL_MOVEMENT);
		_ball->setX(_ball->getX() + BALL_MOVEMENT);
		break;
	case RIGHT:
		_ball->setX(_ball->getX() + BALL_MOVEMENT);
		break;
	case DOWNRIGHT:
		_ball->setY(_ball->getY() + BALL_MOVEMENT);
		_ball->setX(_ball->getX() + BALL_MOVEMENT);
		break;
	case  DOWNLEFT:
		_ball->setY(_ball->getY() + BALL_MOVEMENT);
		_ball->setX(_ball->getX() - BALL_MOVEMENT);
		break;
	case LEFT:
		_ball->setX(_ball->getX() - BALL_MOVEMENT);
		break;
	case UPLEFT:
		_ball->setY(_ball->getY() + BALL_MOVEMENT);
		_ball->setX(_ball->getX() - BALL_MOVEMENT);
		break;
	default:
		break;
	}

}

void Game::detectColision()
{
	//hit by left player
	if (_ball->getX() - BALL_MOVEMENT <= _players[0]->getX() + _players[0]->getW() &&
		_ball->getY() >= _players[0]->getY() && _ball->getY() <= _players[0]->getY()+_players[0]->getH())
	{
		//change direction here
	}
	//hit by right player
	if (_ball->getX() + _ball->getW() + BALL_MOVEMENT >= _players[1]->getX() &&
		_ball->getY() >= _players[1]->getY() && _ball->getY() <= _players[1]->getY() + _players[1]->getH())
	{
		//change direction here
	}
	//hit by left wall
	if (_ball->getX() - BALL_MOVEMENT <= STARTOFWINDOW)
	{
		//add score to right player
		resetBallPosition();
	}
	//hit by right wall
	if (_ball->getX() + _ball->getW() + BALL_MOVEMENT >= _gameWindow->getW())
	{
		//add score to left player
		resetBallPosition();
	}
	//hit by top wall
	if (_ball->getY() <= STARTOFWINDOW)
	{
		//change direction here
	}
	//hit by bottom wall
	if (_ball->getY() >= _gameWindow->getH())
	{
		//change direction here
	}
}



void Game::resetBallPosition()
{
	_ball->setX(_gameWindow->getW() / 2);
	_ball->setY(_gameWindow->getH() / 2);
}
