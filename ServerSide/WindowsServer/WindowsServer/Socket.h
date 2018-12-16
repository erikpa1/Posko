#pragma once
#include <string>
#include <thread>
#include "SFML/Network.hpp"

class NetworkReactor;

class Socket
{

public:

	Socket(int port);
	~Socket();

	void Construct();
	void Destruct();
	void SendToClients(std::string data);
	void ReadFromClient();
	void SetReactor(NetworkReactor * reactor);


private:

	sf::TcpSocket _socket;
	sf::TcpSocket _socket_sender;
	sf::TcpListener _listener;
	std::thread _thread;

	NetworkReactor * _reactor;

};

