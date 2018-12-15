#pragma once
#include <string>
#include "SFML/Network.hpp"


class Socket
{
public:

	void Contruct();
	void Destruct();
	void SendToServer(std::string data);
	void SetApp(void * app);

private:

	void * _app;
	sf::TcpSocket _socket;
	
	
};
