#pragma once
#include <string>


class Socket
{

private:
		
	int _port;
	int _sockfd;
	int _newsockfd;
	
public:

	Socket(int port);

	void Consturct();
	void Destruct();

	void SendToClients(std::string data);
	std::string ReadFromClient();

};
