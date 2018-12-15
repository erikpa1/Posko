#include "Socket.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>

using namespace std;

Socket::Socket(int port)
{
	_port = 123456;
}

void Socket::Consturct()
{
	socklen_t cli_len;	
	struct sockaddr_in serv_addr, cli_addr;
	
	bzero((char*)&serv_addr, sizeof(serv_addr)); 
		serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(_port);

	_sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (_sockfd < 0)
	{
		cout << "Failed to initialize socket" << endl;
	} else
	{
		cout << "Server initialized socket" << endl;
	}

	cout << "Going to initialize server" << endl;
	if (bind(_sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
	{
		cout << "Server failed to bind adress" << endl;
	} else
	{
		cout << "Adress initialized" << endl;
	}

	listen(_sockfd, 5); 
	cli_len = sizeof(cli_addr);

	cout << "Going to accept" << endl;
	_newsockfd = accept(_sockfd, (struct sockaddr*)&cli_addr, &cli_len);
	if (_newsockfd < 0)
	{
		cout << "ERROR on accept" << endl;
	} else
	{
		cout << "Socket accepted" << endl;
	}
}

void Socket::Destruct()
{
	close(_newsockfd);
	close(_sockfd);
}

void Socket::SendToClients(std::string data)
{	
	int ret = write(_newsockfd, data.c_str(), data.length());
	if (ret < 0)
	{
		perror("Error writing to socket");
	}
}

std::string Socket::ReadFromClient()
{
	std::string clientMessage;	
	char buffer[256];
	
	int ret = read(_newsockfd, buffer, 256);
	if (ret < 0)
	{
		perror("Error reading from socket");
	}

	clientMessage = buffer;
	
	return clientMessage;
}
