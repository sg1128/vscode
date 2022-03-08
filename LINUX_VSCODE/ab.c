//abc

#include <stdio.h>

int func(int a, int b){
    return a+b;
}

void func1(){
    printf("I am func1\n");
}

void func2(){
    printf("I am func2\n");
}

void func3(){
    printf("I am func3\n");
}

int main(){
    //함수포인터 선언
    int (*pf)(int,int) = func;
    printf("%d\n", (*pf)(8,5));
    printf("%d\n", func(1,2));

    void(*pf2)(void);
    pf2 = func1;
    (*pf2)();
    pf2 = func2;
    (*pf2)();
    pf2 = func3;
    (*pf2)();
}