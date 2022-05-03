#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#define BUFFER_SIZE 1024
int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in srvAddr;
    struct sockaddr_in cliAddr;
    char *srvIp = NULL;
    unsigned short srvPort;
    char buffer[BUFFER_SIZE];
    int sentSize, rcvSize;
    unsigned int srvAddrLen, cliAddrLen;
    int ret, i;
    if (argc != 3)
    {
        printf("Usage: %s IP_addr Port\n", argv[0]);
        exit(0);
    }
    srvIp = argv[1];
    srvPort = atoi(argv[2]);
    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0)
    {
        printf("socket() failed\n");
        exit(0);
    }

    memset(&srvAddr, 0, sizeof(srvAddr));
    srvAddr.sin_family = AF_INET;
    srvAddr.sin_addr.s_addr = inet_addr(srvIp);
    srvAddr.sin_port = htons(srvPort);
    printf("Client is running.\n");
    printf("Enter the word to translate into capitals\n");
    while (1)
    {
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        sentSize = sendto(sock, buffer, strlen(buffer) + 1, 0,
                          (struct sockaddr *)&srvAddr, sizeof(srvAddr));
        if (sentSize != strlen(buffer) + 1)
        {
            printf("sendto() sent a different number of bytes than expected\n");
            exit(0);
        }
        if (!strcmp(buffer, "quit"))
            break;
        srvAddrLen = sizeof(srvAddr);
        rcvSize = recvfrom(sock, buffer, BUFFER_SIZE, 0,
                           (struct sockaddr *)&srvAddr, &srvAddrLen);
        srvAddrLen = sizeof(srvAddr);
        rcvSize = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&srvAddr,
                           &srvAddrLen);
        if (rcvSize < 0)
        {
            printf("Error in recvfrom()\n");
            exit(0);
        }
        printf("[Server/%s:%d] %s\n", inet_ntoa(srvAddr.sin_addr),
               ntohs(srvAddr.sin_port), buffer);
        if (!strcmp(buffer, "quit"))
            break;
        for (i = 0; buffer[i] != '\0'; i++)
            buffer[i] = toupper(buffer[i]);
        sentSize = sendto(sock, buffer, strlen(buffer) + 1, 0, (struct sockaddr *)&srvAddr,
                          sizeof(srvAddr));
        if (sentSize != strlen(buffer) + 1)
        {
            printf("sendto() sent a different number of bytes than expected");
            exit(0);
        }
    }
    close(sock);
    printf("UDP Client is Closed.\n");
}