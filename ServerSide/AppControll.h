#pragma once
#include <vector>
#include <iostream>
#include "WindowsServer/WindowsServer/NetworkReactor.h"
#include  <stdlib.h>
#include <string>

class Socket;
class Player;
class Ball;

class AppControll : public NetworkReactor {
public:

    void Construct();
    void Destruct();
    void Start();
    void InitPlayer(Player * player, int number);
    void ClientConnected();
    void RecieveMessage(std::string message) override;

private:

    void SendToClient();
    void ReadFromClient();
    void Update();

    void ResetBallPosition();
    void UpdateBallPosition();
    void UpdatePlayer(bool up, int amount, int playerChoose);
    void DetectCollision();

private:
    
    int _w = 1000;
    int _h = 500;
    int _score_left = 0;
    int _score_right = 0;
    int playersTurn;

    bool _start = false;
       
    int _clientNumber = 0;

    std::string _state = "run";

    Socket * _socket;
    Socket * _socket1;
    
    Ball * _ball;

    std::vector<Player*> _players;


};
