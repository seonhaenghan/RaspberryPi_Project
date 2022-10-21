#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define TCP_PORT 5100
// client 는 bind 하지 않고, connect() 요청만 하기에 server 보다 간단하다. 
// program 실행시 argv에 client 정보가 자동으로 argv에 들어감 (os에 의해)
int main(int argc, char **argv)
{
    int ssock;
    struct sockaddr_in servaddr;
    char mesg[BUFSIZ];  // 사용자가 타이핑한 data 전송 

        while(1)
        {
            if(argc < 2){
        printf("Usage : %s IP_ADDRESS\n", argv[0]);
        return -1;
        }

        /* 소켓을 생성 */
        if((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
            perror("socket()");
            return -1;
        }

        /* 소켓이 접속할 주소 지정 */
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;

        /* 문자열을 네트워크 주소로 변경 */
        inet_pton(AF_INET, argv[1], &(servaddr.sin_addr.s_addr));
        servaddr.sin_port = htons(TCP_PORT);    // port num. insert 

        /* 지정한 주소로 접근 */
        // connect() 시 os에 의해 IP와 port번호(OS가 자동으로 만든다.) 전송된다. 
        if(connect(ssock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
            perror("connect()");
            return -1; 
        }
        fgets(mesg, BUFSIZ, stdin);
        // client 접속 종료 
        if(!strncmp(mesg, "exit", 4))
        {
            break;
        }
        if(send(ssock, mesg, BUFSIZ, MSG_DONTWAIT) <= 0){   /* 데이터를 소켓이 씀 */
        // send() == write()
            perror("send()");
            return -1;
        }

        memset(mesg, 0, BUFSIZ);
        if(recv(ssock, mesg, BUFSIZ, 0) <= 0){  /* 데이터를 소켓으로부터 읽음 */
            perror("recv()");
            return -1;
        }
        printf("Received data : %s", mesg);     /* 받을 문자열을 화면에 출력 */

        }

    close(ssock);
    

    return 0; 

}