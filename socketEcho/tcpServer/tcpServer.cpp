#include "tcpServer.h"

tcpServer::tcpServer(int port)
{
    portNum = port;
    clientState = false;
    // 생성자에서 소켓 생성 함수 불러옴  
    createSocket();
}

tcpServer::~tcpServer()
{
    //소멸자에서 반환 받아야 함 
    close(serverSock_fd);
}

int tcpServer::getClientSocket()    // client socket 정보를 return 한다. 
{
    return clientSock_fd;
}

int tcpServer::getServerSocket()    // Serversocket 정보를 return 한다. 
{
    return serverSock_fd;
}

void tcpServer::createSocket()
{
    if((serverSock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket()\n"); /* 버퍼를 안거치고 바로 화면에 error를 띄움 */
        return ;
    }
    /* 바로 재사용 하기 위해 추가 함 */ 
    int option = 1; 
    setsockopt(serverSock_fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));   /* 해당 discrept를 재사용하겠다. */

    // 주소 구조체에 주소 지정 
    memset(&serv_addr, 0, sizeof(serv_addr)); 
    serv_addr.sin_family = AF_INET;                      // AF_INET >> 인터넷을 사용한다. 
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);       // all Local IP를 할당한다. 
    serv_addr.sin_port = htons(portNum);                // 사용할 포트 지정 5100번 

    /* bind 함수를 사용하여 서버 소켓의 주소 설정 */
    // 내가 설정한 IP와 POrt num.을 os에 알려준다. (Memory를 점유 함)
    if(bind(serverSock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind()");
        return ; 
    }
    // 해당 IP와 Port번호에 들어오는  IP를 8개 까지 수용한다. >> Buffering 하겠다. 
    /* 동시에 접속하는 클라이언트의 처리를 위한 대기 큐를 설정 (8개 까지 Buffer를 만든다.)*/  
    if(listen(serverSock_fd, 8) < 0){
        perror("listen()");
        return ; 
    }
}

int tcpServer::waitAccept()
{
    char mesg[BUFSIZ];// 최대값

    clnt_addr_size = sizeof(client_addr);
    
    clientSock_fd = accept(serverSock_fd, (struct sockaddr *) &client_addr, &clnt_addr_size) ;// client에 대한 IP와 Port 번호까지 들어옴 
    
        /* 클라이언트가 접속하면 접속을 허용하고 클라이언트 소켓 생성 */
        /* 클라이언트가 허용할 때까지 대기중 */
       
        // 해당 정보를 accept() 하면서 연결이 시작 된다. 
    if(clientSock_fd < 0)
    {
        perror("accept() error\n");
        return -1; 
    }

    /*네트워크 주소를 문자열로 변경 */
    inet_ntop(AF_INET, &client_addr.sin_addr, mesg, BUFSIZ);    // 클라이언트에 대한 정보를 문자열로 변경함 (inet_ntop)
    printf("Client is connented : %s\n", mesg); 

    return clientSock_fd;
}

int tcpServer::recvData(char *recvbuff, size_t size)
{
    int len = read(clientSock_fd, recvbuff, size);
    return len;
}

int tcpServer::sendData(char *sendbuff, size_t size)
{
    if(!getClientState()) return -1;

    int len = write(clientSock_fd, sendbuff, size);
    return len;
}

void tcpServer::closeSocket(int socket)
{
    close(socket); 
}

bool tcpServer::getClientState()
{
    return clientState;
}

void tcpServer::setClientState(bool state)
{
    clientState = state; 
}