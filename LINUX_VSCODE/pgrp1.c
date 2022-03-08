#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    int pid, gid;
    printf("PAREN: PID = %d GID = %d\n", getpid(), getpgrp());
    pid = fork();
    if(pid==0){
        printf("CHILD: PID = %d GID = %d\n",getpid(),getpgrp());
    }
}