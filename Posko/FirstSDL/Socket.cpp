#include "Socket.h"
#include "Game.h"
#include <iostream>

using namespace std;

void Socket::Contruct()
{
	if (_socket.connect("127.0.0.1", 123456) != sf::TcpSocket::Done)
	{
		cout << "Failed to connect on socket" << endl;
	} else
	{
		cout << "Connected on server" << endl;
	}
}

void Socket::Destruct()
{

}

void Socket::SendToServer(std::string data)
{
	if (_socket.send("Nazdar", 7) != sf::TcpSocket::Done)
	{
		cout << "Failded to send" << endl;
	} else
	{
		cout << "Odoslane serveru" << endl;
	}
}

void Socket::SetApp(void* app)
{
	_app = app;
}
