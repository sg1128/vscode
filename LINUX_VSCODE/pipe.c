#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAXLINE 100

int main(){
    int n, length, fd[2];
    int pid;
    char message[MAXLINE],line[MAXLINE];

    pipe(fd);

    if((pid=fork())==0){
        close(fd[0]);
        sprintf(message, "Hello from PID %d\n", getpid());//getpid는 자기자신의 프로세스를 나타낸다
        length = strlen(message) + 1;
        sleep(3);
        write(fd[1], message, length);
    }else{
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        printf("[%d]%s",getpid(), line);
    }
    exit(0);
}