#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    printf("20181498 박선균\n");
    int fd1, fd2, fd3, n;
    char buf[BUFSIZ];
    if(argc != 4){
        fprintf(stderr, "사용법: %s file1 file2 file3\n",argv[1]);
        exit(1);
    }
    if((fd1=open(argv[1],O_RDONLY))== -1){
        perror(argv[1]);
        exit(2);
    }
    if((fd2=open(argv[2],O_RDONLY))== -1){
        perror(argv[2]);
        exit(2);
    }
    if((fd3=open(argv[3],O_WRONLY | O_CREAT | O_TRUNC, 0644))== -1){
        perror(argv[3]);
        exit(3);
    }
    while ((n=read(fd1,buf,BUFSIZ))>0)
        write(fd3, buf, n);
    while ((n=read(fd2,buf,BUFSIZ))>0)
        write(fd3, buf, n);
    exit(0);
}