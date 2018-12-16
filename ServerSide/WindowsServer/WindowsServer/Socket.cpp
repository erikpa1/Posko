#include "Socket.h"
#include "SFML/Network.hpp"
#include "NetworkReactor.h"
#include <iostream>


using namespace std;


Socket::Socket(int port)
{

}


Socket::~Socket()
{
}

void Socket::Construct()
{
	_socket.connect("127.0.0.1", 123456);
	//_socket_sender.connect("127.0.0.1", 123457);
	_thread = std::thread(&Socket::ReadFromClient, this);

}

void Socket::Destruct()
{
}

void Socket::SendToClients(std::string data)
{
	_socket.send(data.c_str(), data.length() + 1);
	//_socket_sender.send(data.c_str(), data.length()+1);
}

void Socket::ReadFromClient()
{
	char data[256];
	size_t recieveddata = 0;
	cout << "Server is going to read from client" << endl;
	while(true)
	{
		cout << "Listening cycle" << endl;
		if (_listener.listen(123456) != sf::Socket::Done)
		{
			//std::cout << "Nieco zleho v listenerovi" << endl;
		} else
		{
			if (_listener.accept(_socket) != sf::Socket::Done)
			{
				cout << "Nieco zleho v acceptovani" << endl;
			}
			else
			{
				while (true)
				{
					cout << "Client connected, his adress " << _socket.getRemoteAddress() << endl;
					if (_socket.receive(data, 255, recieveddata) == sf::Socket::Done)
					{
						cout << "Client poslal: " << string(data) << endl;
						_reactor->RecieveMessage(string(data));
					}
				}								
			}
		}
		_listener.close();	
	}
}

void Socket::SetReactor(NetworkReactor* reactor)
{
	_reactor = reactor;
}
