
#include <iostream>
#include "AppControll.h"

int main()
{
	AppControll app;
	app.Construct();
	std::cout << "Server going to start" << std::endl;
	app.Start();	
	return 0;
}
