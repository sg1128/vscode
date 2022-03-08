#include <stdio.h>

void func(int a){
    printf("%d\n",a);
}

int main(){
    void *pv;
    int a = 0;
    int *pa = &a;
    double b = 1.1;
    double *pb = &b;
    void(*pf)(int) = func;
    pv = pa;
    printf("%d\n", *((int *)pv));

     pv = pb;
    printf("%f\n", *((double *)pv));

    pv = pf;
    void (*pf2)(int) = pv;
    pf2(50);
}