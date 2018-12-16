#pragma once
#include <vector>
#include <iostream>
#include "WindowsServer/WindowsServer/NetworkReactor.h"
#include  <stdlib.h>

class Socket;
class Player;
class Ball;

class AppControll : public NetworkReactor
{

public:

	void Construct();
	void Destruct();
	void Start();
	void InitPlayer(Player * player, int number);

private:
    
	void SendToClient();
	void ReadFromClient();
	void Update();
        
    void ResetBallPosition();
    void UpdateBallPosition();
    void UpdatePlayer(bool up, int amount, int playerChoose);
    void DetectCollision();
    void UpdateScoreOnClients();

	void RecieveMessage(std::string message) override;
        
        
private:
	int _w = 800;
	int _h = 600;
        int _score_left = 0;
        int _score_right = 0;
		int playersTurn;

	Socket * _socket;
	Ball * _ball;

	std::vector<Player*> _players;


};
