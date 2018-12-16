#include "AppControll.h"
#include "Ball.h"
#include "Player.h"
//#include "WindowsServer/WindowsServer/Socket.h"
#include "Socket.h"

#define PLAYER_MOVEMENT 20
#define BALL_MOVEMENT 1
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
	_socket = new Socket(12356);
	_socket->Construct();
	_socket->SetReactor(this);

	_players.push_back(new Player());
	_players.push_back(new Player());
	_ball = new Ball();
        //_ball->setUp(true); //testovacie ucely
        
	_players[0]->Construct();
	_players[1]->Construct();

	_players[0]->SetName("Player1");
	_players[1]->SetName("Player2");

	InitPlayer(_players[0],0); 
	InitPlayer(_players[1],1);

	ResetBallPosition();
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
            cout << "----------------------------------------" << endl;
            Update();		
            cout << "Pozicia Lopticky" << endl;
            _ball->PrintYourSelf();
            cout << "pozicia laveho hraca" << endl;
            _players[0]->PrintYourSelf();
            cout << "pozicia praveho hraca" << endl;
            _players[1]->PrintYourSelf();	               	
		
	}
}

void AppControll::InitPlayer(Player * player, int number)
{
    player->setW(20);
    player->setH(70);
    player->setY(_h / 2 - player->getH() / 2);
    
    if (number == 0) {
        player->setX(0);
    } else {
        player->setX(_w - player->getW());
    }        
}

void AppControll::SendToClient()
{
	cout << "Sending to clients" << endl;
}

void AppControll::ReadFromClient()
{
	cout << "Reading from clinets:" << endl;
	cout << "Client has written: " << endl;
}

void AppControll::Update()
{
    cout << "Updating states" << endl;
    UpdateBallPosition();
    DetectCollision();
	_socket->SendToClients("B;" + to_string(_ball->getX()) + ";" + to_string(_ball->getY()) + ";");
	string message = "P;" + to_string(_players[0]->getX()) + ";" + to_string(_players[0]->getY()) + ";";
	message += "P;" + to_string(_players[1]->getX()) + ";" + to_string(_players[1]->getY()) + ";";	
	_socket->SendToClients(message);
		
	std::this_thread::sleep_for(chrono::microseconds(500));
}

void AppControll::ResetBallPosition()
{
	this->playersTurn = rand() % 2;
	if(playersTurn == 0)
	{
		_ball->setLeft(true);
	}
	else
	{
		_ball->setLeft(false);
	}
    _ball->setX(_w / 2);
    _ball->setY(_h / 2);
	
}

void AppControll::UpdateBallPosition()
{
	srand(time(NULL));
	int randomAngle = rand() % 3;

    if (_ball->getUp())
    {	
		_ball->setY(_ball->getY() - BALL_MOVEMENT);// randomAngle);
    } else {
        _ball->setY(_ball->getY() + BALL_MOVEMENT);
    }
    
    if (_ball->getLeft())
    {
        _ball->setX(_ball->getX() - BALL_MOVEMENT);
    } else {
        _ball->setX(_ball->getX() + BALL_MOVEMENT);
    }    
}

void AppControll::DetectCollision()
{
	string messageToClient = "";
    
    if (_ball->getX() - BALL_MOVEMENT <= _players[0]->getX() + _players[0]->getW() &&
    _ball->getY() > _players[0]->getY() && _ball->getY() < _players[0]->getY()+_players[0]->getH())
    {
		//hit by left player
        _ball->setLeft(false);
		cout << "Hit by Left player" << endl;
    } else  if (_ball->getX() + _ball->getW() + BALL_MOVEMENT >= _players[1]->getX() &&
        _ball->getY() > _players[1]->getY() && _ball->getY() <= _players[1]->getY() + _players[1]->getH())
    {
        //hit by right player
        _ball->setLeft(true);
		cout << "Hit by Right player" << endl;
    } else if (_ball->getX() - BALL_MOVEMENT <= STARTOFWINDOW)
    {
        //hit by left wall
        _score_right += 1;
		messageToClient = "R1";
        UpdateScoreOnClients();
        ResetBallPosition();
        cout << "Hit by Left wall" << endl;
    } else if (_ball->getX() + _ball->getW() + BALL_MOVEMENT >= _w)
    {
        //hit by right wall
        _score_left += 1;
		messageToClient = "R0";
        UpdateScoreOnClients();
        ResetBallPosition();
        cout << "Hit by Right wall" << endl;
    } else if (_ball->getY() <= STARTOFWINDOW)
    {
        //hit by top wall
        _ball->setUp(false);
        _ball->setDown(true);
        cout << "Hit by Top wall" << endl;
    }else if (_ball->getY() > _h)
    {
        //hit by bottom wall
        _ball->setUp(true);
        _ball->setDown(false);
        cout << "Hit by Bottom wall" << endl;
    }

	if (messageToClient != "")
	{
		_socket->SendToClients(messageToClient);
	}

}

void AppControll::UpdatePlayer(bool up, int amount, int playerChoose)
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
		if ((helper->getY() + helper->getH() + PLAYER_MOVEMENT) <= _h)
		{
			helper->setY(helper->getY() + PLAYER_MOVEMENT);
		}            	
	}       
    
}

void AppControll::UpdateScoreOnClients()
{
    
}

void AppControll::RecieveMessage(std::string message)
{
	cout << "Message recieved " << message << endl;

	
	int player = message.at(0) - 48;
	bool direction = false;

	if (message.at(1) == '1')
	{
		cout << "Player is going up" << endl;
		direction = true;
	}

	cout << "Player number " << player << endl;

	this->UpdatePlayer(direction, PLAYER_MOVEMENT+10, player);

}

