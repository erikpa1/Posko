#include "AppControll.h"
#include "Socket.h"
#include "Ball.h"
#include "Player.h"

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


void AppControll::Construct()
{
	_socket = new Socket(123456);
	_socket->Consturct();
	_players.push_back(new Player());
	_players.push_back(new Player());
	_ball = new Ball();

	_players[0]->Construct();
	_players[1]->Construct();

	_players[0]->SetName("Player1");
	_players[1]->SetName("Player2");

	InitPlayer(_players[0]);
	InitPlayer(_players[1]);
}


void AppControll::Destruct()
{
	//_socket->Destruct();
	//delete _socket;
	_socket = nullptr;
}


void AppControll::Start()
{
	while (true)
	{
		cout << "Server started running cycle" << endl;

		//ReadFromClinet();
		Update();
		//SendToClient();


		cout << "Server ended running running cycle" << endl;
	}
}



void AppControll::InitPlayer(Player * player)
{
	player->setW(20);
	player->setH(70);
	player->setY(_h / 2 - player->getH() / 2);
}

void AppControll::SendToClient()
{
	cout << "Sending to clients" << endl;

}

void AppControll::ReadFromClinet()
{
	cout << "Reading from clinets:" << endl;
	cout << "Client has written: " << _socket->ReadFromClient() << endl;
}

void AppControll::Update()
{
    cout << "Updating states" << endl;
    UpdateBallPosition();
    DetectCollision();
           
}

void AppControll::ResetBallPosition()
{
    _ball->setX(_w / 2);
    _ball->setY(_h / 2);
}

void AppControll::UpdateBallPosition()
{
    if (_ball->getUp())
    {
        _ball->setY(_ball->getY() + BALL_MOVEMENT);
    } else {
        _ball->setY(_ball->getY() - BALL_MOVEMENT);
    }
    
    if (_ball->getLeft())
    {
        _ball->setX(_ball->getY() - BALL_MOVEMENT);
    } else {
        _ball->setY(_ball->getY() - BALL_MOVEMENT);
    }    
}

void AppControll::DetectCollision()
{
    //hit by left player
    if (_ball->getX() - BALL_MOVEMENT <= _players[0]->getX() + _players[0]->getW() &&
    _ball->getY() >= _players[0]->getY() && _ball->getY() <= _players[0]->getY()+_players[0]->getH())
    {
        _ball->setRight(true);
        _ball->setLeft(false);
    }
    
    //hit by right player
    if (_ball->getX() + _ball->getW() + BALL_MOVEMENT >= _players[1]->getX() &&
    _ball->getY() >= _players[1]->getY() && _ball->getY() <= _players[1]->getY() + _players[1]->getH())
    {
        _ball->setRight(false);
        _ball->setLeft(true);
    }
    
    //hit by left wall
    if (_ball->getX() - BALL_MOVEMENT <= STARTOFWINDOW)
    {
        _score_right += 1;
        UpdateScoreOnClients();
        ResetBallPosition();
    }
    
    //hit by right wall
    if (_ball->getX() + _ball->getW() + BALL_MOVEMENT >= _h)
    {
        _score_left += 1;
        UpdateScoreOnClients();
        ResetBallPosition();
    }
    
    //hit by top wall
    if (_ball->getY() <= STARTOFWINDOW)
    {
        _ball->setUp(false);
        _ball->setDown(true);
    }
    
    //hit by bottom wall
    if (_ball->getY() >= _h)
    {
        _ball->setUp(true);
        _ball->setDown(false);
    }               
}

void AppControll::UpdatePlayer(bool up, int amount, int playerChoose)
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
            if ((helper->getY() + helper->getH() + PLAYER_MOVEMENT) <= _h)
            {
		helper->setY(helper->getY() + PLAYER_MOVEMENT);
            }	}       
    
}

void AppControll::UpdateScoreOnClients()
{
    
}

