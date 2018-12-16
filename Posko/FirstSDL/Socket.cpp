﻿#include "Socket.h"
#include "Game.h"
#include <iostream>

#define SERVER "frios2.fri.uniza.sk" //127.0.0.1
#define PORT 12356  //123456

using namespace std;

void Socket::Contruct()
{
	if (_socket.connect(SERVER, PORT) != sf::TcpSocket::Done)
	{
		cout << "Failed to connect on socket" << endl;
	} else
	{
		cout << "Connected on server" << endl;
	}

	_thread = std::thread(&Socket::ReadFromServer, this);



}

void Socket::Destruct()
{

}

void Socket::SendToServer(std::string data)
{
	if (_socket.send(data.c_str(), data.length()+1) != sf::TcpSocket::Done)
	{
		cout << "Failded to send" << endl;
	} else
	{
		cout << "Odoslane serveru: " << data << endl;
	}
}

void Socket::ReadFromServer()
{
	char data[256];
	size_t recieveddata = 0;
	cout << "Server is going to read from client" << endl;
	while (true)
	{
		
		//cout << "Client connected, his adress " << _socket.getRemoteAddress() << endl;
		if (_socket.receive(data, 255, recieveddata) == sf::Socket::Done)
		{
			cout << "Client poslal: " << string(data) << endl;
			//_reactor->RecieveMessage(string(data));
		}
	}
}


void Socket::SetNetworkReciever(NetworkReciever* reciever)
{
	_reactor = reciever;
}

