#pragma once
#include <string>

class NetworkReciever
{
public:
	virtual void RecieveMessage(std::string message) = 0;
};
