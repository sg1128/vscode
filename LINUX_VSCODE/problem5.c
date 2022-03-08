#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>

void intHandler();

int main(void){
    printf("20181498 박선균\n");
    srand((unsigned)time(NULL));
    signal(SIGINT, intHandler);
    while(1){
        printf("프로그램을 종료하려면 Ctrl-C를 눌러 보세요! \n");
        sleep(1);
    }
   
}

void intHandler(int signo){
    int count = rand();
    if(count%2 == 1){
        printf("메롱~!\n");
        printf("또 눌러봐~\n");
    }else{
       printf( "%d 번 시그널 처리!\n", signo);
       exit(0);
    }
}