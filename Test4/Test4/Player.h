#pragma once
#include "Renderable.h"

class Rectangle;
class Socket;

class Player : public Renderable
{
public:

	Player();
	~Player();

	void Construct() override;
	void Destruct() override;

	void setX(int x) override;
	void setY(int y) override;
	void setW(int w) override;
	void setH(int h) override;	
	void SetName(std::string name) override;

	void SetSocket(Socket * socket);
	void UpdateNetworkAlternative();

	void Draw() override;

	void Update() override;

private:

	Socket * _socket = nullptr;



};
