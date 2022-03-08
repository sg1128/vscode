// #include <iostream>
// using namespace std;

#include <stdio.h>

struct AAA
{
    int a;
    char b;
    double c;
};

struct BBB
{
    char a;
    double b;
    int c;
};

int main()
{
    printf("%ld\n", sizeof(AAA));
    printf("%ld\n", sizeof(BBB));
}