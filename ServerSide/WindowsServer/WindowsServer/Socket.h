#pragma once
#include <string>
#include <thread>
#include "SFML/Network.hpp"

class Socket
{

public:

	Socket(int port);
	~Socket();

	void Construct();
	void Destruct();
	void SendToClients(std::string data);
	void ReadFromClient();


private:

	sf::TcpSocket _socket;
	sf::TcpListener _listener;
	std::thread _thread;


};

