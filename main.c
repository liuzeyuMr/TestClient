#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include "warp.h"

#define MAXLINE 4096
#define SERV_PORT 6666

//Socket简单大小写转换
int Client_toupper(){

}


int main(int argc, char** argv)
{
    int    sockfd, n;
    char    recvline[MAXLINE], sendline[MAXLINE];
    //memset(sendline,'X',sizeof(sendline));
    struct sockaddr_in    servaddr;

    if( argc != 2){
        printf("usage: ./client <ipaddress>\n");
        exit(0);
    }

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    //servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  ///服务器ip

    if( inet_pton(AF_INET, argv[1], &servaddr.sin_addr)  < 0){
        printf("inet_pton error for %s\n",argv[1]);
        exit(0);
    }
    Connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    while (1){
        fgets(sendline, 4096, stdin);
        //int n=read(sockfd,recvline, sizeof(recvline));
        Write(sockfd, sendline, strlen(sendline));
        printf("write msg to server : %s \n",sendline);
        Read(sockfd,recvline,MAXLINE);
        printf("read msg to server : %s \n",recvline);

    }

    close(sockfd);
    exit(0);
}
