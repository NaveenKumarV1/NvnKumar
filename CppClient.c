/*import socket
import sys
HOST='127.0.0.1'
PORT=5005
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM,0)
s.connect((HOST,PORT))
while 1:
        data=raw_input()
        s.send(data,1024)
        data=s.recv(104)
        if (data =="BY"):
               s.close()
        print data;
*/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>

#define PORT_TIME       13              /* "time" (not available on RedHat) */
#define PORT_FTP        5005            /* FTP connection port */
#define SERVER_ADDR     "127.0.0.1" /* localhost */
#define MAXBUF          104

int main()
{   int sockfd;
    struct sockaddr_in dest;
    char buffer[MAXBUF];

    /*---Open socket for streaming---*/
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("Socket");
        exit(errno);
    }

    /*---Initialize server address/port struct---*/
    bzero(&dest, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(PORT_FTP);
    if ( inet_aton(SERVER_ADDR, &dest.sin_addr.s_addr) == 0 )
    {
        perror(SERVER_ADDR);
        exit(errno);
    }

    /*---Connect to server---*/
    if ( connect(sockfd, (struct sockaddr*)&dest, sizeof(dest)) != 0 )
    {
        perror("Connect ");
        exit(errno);
    }

    while(1)
    {
    /*---Get "Hello?"---*/
    bzero(buffer, MAXBUF);
    scanf("%s",buffer);
    send(sockfd, buffer, sizeof(buffer),0);
    bzero(buffer, MAXBUF);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    }
    /*---Clean up---*/
    close(sockfd);
    return 0;
}
