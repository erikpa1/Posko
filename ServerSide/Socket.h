#pragma once
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <thread>

class NetworkReactor;

class Socket {
private:

    int _port;
    int _sockfd;
    int _newsockfd;
    NetworkReactor * _reactor;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;
    bool _isconnected = false;
    
    std::thread _myThread;    
    bool _inited = false;
    bool _disconnectRequest = false;
    
public:

    Socket(int port);

    bool IsConnected();
    bool GetDisconnectReqeust();
    
    void Construct();
    void Destruct();
    void SetReactor(NetworkReactor * reactor);
    void ReadFromClient();

    void SendToClients(std::string data);
    void FillSocket(char * data, std::string message, int size);

};
