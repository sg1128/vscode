#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void intHandler();
int count = 10;

int main(){
    signal(SIGINT, intHandler);
    while(1)
        pause();
    printf("실행되지 않음 \n");
}

void intHandler(int signo){
    if (count != 0)
    {
        count--;
        printf("니가 가진 전재산을 내놔라\n");
    }
    else if(count == 0)
    {
        printf("미안\n");
        exit(0);
    }
    /*printf("인터럽트 시그널 처리\n");
    printf("시그널 번호: %d\n", signo);
    exit(0); //종료하려면 컨트롤+z 하고 ps 에서 kill -9 번호 한다*/
}