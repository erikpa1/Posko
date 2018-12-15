#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int sockfd, n;
	struct sockaddr_in serv_addr;
	struct hostent* server;

	char buffer[256];

	server = gethostbyname("frios2.fri.uniza.sk"); 
	if (server == NULL)
	{
		fprintf(stderr, "Error, no such host\n");
		return 2;
	}

	bzero((char*)&serv_addr, sizeof(serv_addr)); 
	serv_addr.sin_family = AF_INET;
	bcopy(
		(char*)server->h_addr_list[0],
		(char*)&serv_addr.sin_addr.s_addr,
		server->h_length
	);
	serv_addr.sin_port = htons(123456);

	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd < 0)
	{
		perror("Error creating socket");
		return 3;
	}

	if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)  
	{
		 perror("Error connecting to socket");
		 return 4;
	}	

	printf("Please enter a message: "); 
	bzero(buffer,256);
	fgets(buffer, 255, stdin); 

	n = write(sockfd, buffer, strlen(buffer)); 
	if (n < 0)
	{
		 perror("Error writing to socket");
		 return 5;
	}
        printf("Please enter a message: ");

	bzero(buffer,256);
	n = read(sockfd, buffer, 255);
	if (n < 0)
	{
		 perror("Error reading from socket");
		 return 6;
	}

	printf("%s\n",buffer);
	close(sockfd);

	return 0;
}