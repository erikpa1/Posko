#include "AppControll.h"
#include "Socket.h"

void AppControll::Construct()
{
	_socket = new Socket(123456);
	_socket->Consturct();
	_socket->Destruct();
}

void AppControll::Destruct()
{
	delete _socket;
}
