#include "Socket.h"

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>


Socket::Socket(int port)
{
	_ipAddress = ipAddres;
	_port = port;
}

void Socket::Consturct()
{
	
	
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	char buffer[256];

	bzero((char*)&serv_addr, sizeof(serv_addr)); 
		serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(atoi(argv[1]));

	_sockfd = socket(AF_INET, SOCK_STREAM, 0); 
		if (_sockfd < 0)
		{
			perror("Error creating socket");
			return 1;
		}

	if (bind(_sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
	{
		perror("Error binding socket address");
		return 2;
	}

	listen(_sockfd, 5); 
		cli_len = sizeof(cli_addr);

	_newsockfd = accept(_sockfd, (struct sockaddr*)&cli_addr, &cli_len); 
		if (_newsockfd < 0)
		{
			perror("ERROR on accept");
			return 3;
		}

	bzero(buffer, 256);
	n = read(_newsockfd, buffer, 255); 
		if (n < 0)
		{
			perror("Error reading from socket");
			
		}
	printf("Here is the message: %s\n", buffer);

		const char* msg = "I got your message";
	n = write(_newsockfd, msg, strlen(msg) + 1); 
		if (n < 0)
		{
			perror("Error writing to socket");
		
		}

	close(_newsockfd);
	close(_sockfd);

	


}

void Socket::Destruct()
{

}

void Socket::SendToClients(std::string data)
{

}
