﻿#include "Socket.h"
        
#define SERVER "frios2.fri.uniza.sk" //127.0.0.1
#define PORT 12356  //123456

using namespace std;

Socket::Socket(int port)
{
	_port = PORT;
}
 
void Socket::Construct()
{	 
		
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
        
        _myThread = thread(&Socket::ReadFromClient, this);        
        _inited = true;
       
        	
}

void Socket::ReadFromClient()
{      
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
    
    
    while (true)
    {
        char buffer[256];       
        bzero(buffer,256);
        
        int n = read(_newsockfd, buffer, 255);
        
        string message = buffer;        
        _reactor->RecieveMessage(message);
                
    }
        
    
    
}

void Socket::SetReactor(NetworkReactor* reactor)
{
    _reactor = reactor;
}

void Socket::Destruct()
{
	close(_newsockfd);
	close(_sockfd);
}

void Socket::SendToClients(std::string data)
{	
    if (_inited)
    {
        int ret = write(_newsockfd, data.c_str(), data.length());
        if (ret < 0)
        {
            perror("Error writing to socket");
        } else {
            cout << "Server written: " << data << endl;
        }
    }	
}
