#pragma once
#include <string>

class NetworkReactor
{
public:
    
    virtual void RecieveMessage(std::string message) = 0;
    virtual void ClientConnected() = 0;

	

};
