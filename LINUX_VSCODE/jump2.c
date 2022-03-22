#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>
#include <signal.h>
void p1();
void intHandler();
jmp_buf env;
int count = 0;

int main(){
    signal(SIGINT, intHandler);
    if(setjmp(env)!=0){
        printf("%d초 만에 인터럽트로 인해 복귀\n",count);
        exit(0);
    }
    else
        printf("처음 통과\n");
    p1();
}

void p1(){
    while(1){
        printf("루프\n");
        sleep(1);
        count++;
    }   
}

void intHandler(){
    printf("인터럽트\n");
    longjmp(env, count);
}