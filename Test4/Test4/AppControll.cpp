#include "AppControll.h"
#include "Socket.h"
#include "Ball.h"
#include "Player.h"


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

		ReadFromClinet();
		Update();
		SendToClient();


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
}
