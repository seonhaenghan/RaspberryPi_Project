#include "tcpServer.h"
#include <thread>
#include <unistd.h>
#include <queue>

std::queue<char> queBuff;    //vector 선언 

void threadfunc(tcpServer *echoServer)
{
    char recvBuff[BUFSIZ];
    int recvlen; 

    while (echoServer->waitAccept() > 0)
    {   // f1 == 임의로 넣은 값  나중에 바꿔도 된다. 
        echoServer->setClientState(true);
        while((recvlen = echoServer->recvData(recvBuff, sizeof(recvBuff))) > 0)
        {
            recvBuff[recvlen +1] = '\0'; 
            echoServer->sendData(recvBuff, recvlen);
            //  memset(recvBuff, 0, sizeof(recvBuff));
            for(int i = 0; i < recvlen; i++)
            {
                queBuff.push(recvBuff[i]); 
            }
            printf("recevied Data : %s\n", recvBuff);
        }
        echoServer->closeSocket(echoServer->getClientSocket());
        echoServer->setClientState(false);

        printf("close client socket\n");
    }    
}

int main ()
{
    char inBuff[BUFSIZ];

    tcpServer echoServer(5100);
    std::thread f1(threadfunc, &echoServer); // 함수 이름은 주소 f1(주소 값)
    int counter = 0; 
    while(1)
    {
        if(!queBuff.empty()) // 비어있으면 true 
        {
            printf("%c\n", queBuff.front());
            queBuff.pop();
        }

        sprintf(inBuff, "%d", counter++);
        echoServer.sendData(inBuff, strlen(inBuff));
        sleep(1); 
        // memset(inBuff, 0, sizeof(inBuff)); 
        // fgets(inBuff, sizeof(inBuff), stdin);
        // if(echoServer.getClientSocket() > 0)
        // echoServer.sendData(inBuff, sizeof(inBuff));
    }

    f1.join(); // 스레드가 끝나기 전까지 다음 라인으로 안내려간다. 

    echoServer.closeSocket(echoServer.getServerSocket());
    return 0; 
}