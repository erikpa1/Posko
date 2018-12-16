#pragma once
#include <string>
#include "SFML/Network.hpp"
#include "NetworkReciever.h"
#include <thread>


class Socket 
{
public:

	void Contruct();
	void Destruct();
	void SendToServer(std::string data);	
	void SetNetworkReciever(NetworkReciever * reciever);
	void ReadFromServer();
	
private:

	NetworkReciever * _reactor;
	sf::TcpListener _listener;
	sf::TcpSocket _socket;

	std::thread _thread;
	
};
