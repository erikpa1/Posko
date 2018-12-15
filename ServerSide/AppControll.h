#pragma once
#include <vector>
#include <iostream>

class Socket;
class Player;
class Ball;

class AppControll
{

public:

	void Construct();
	void Destruct();
	void Start();
	void InitPlayer(Player * player);

private:
    
	void SendToClient();
	void ReadFromClinet();
	void Update();
        
        void ResetBallPosition();
        void UpdateBallPosition();
        void UpdatePlayer(bool up, int amount, int playerChoose);
        void DetectCollision();
        void UpdateScoreOnClients();
        
        
private:
	int _w = 800;
	int _h = 600;
        int _score_left = 0;
        int _score_right = 0;
        
	Socket * _socket;
	Ball * _ball;

	std::vector<Player*> _players;


};
