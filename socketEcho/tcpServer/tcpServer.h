#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class tcpServer
{
private:
    int serverSock_fd;
    int clientSock_fd;
    int portNum;    // 서버에 대한 port 번호 
    bool clientState;

    struct sockaddr_in serv_addr;// 라이브러라에서 제공하는 소켓 구조체
    struct sockaddr_in client_addr;
    socklen_t clnt_addr_size; 

public:
    tcpServer(int port);
    virtual ~tcpServer();
    void createSocket();
    int getClientSocket();
    int getServerSocket();
    int waitAccept(); 
    int recvData(char *recvbuff, size_t size);
    int sendData(char *sendbuff, size_t size);
    void closeSocket(int socket);
    bool getClientState();
    void setClientState(bool state);
};

#endif