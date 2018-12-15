#pragma once
#include <string>

class Socket
{
public:
	Socket(int port);
	~Socket();

	void Construct();
	void Destruct();
	void SendToClients(std::string data);
	std::string ReadFromClient();
};

