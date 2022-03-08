#include <iostream>
using namespace std;

//call by value
void inc1(int x)
{
    ++x;
}

//call by reference(pointer)
void inc2(int *x)
{
    ++*x;
}

void inc3(int &x)
{
    ++x;
}

// int main()
// {
//     int n = 10;
//     inc1(n);
//     inc2(&n); //증가
//     inc3(n);  //증가

//     cout << n << endl;
// }

void foo(int *x)
{
    printf("foo: sizeof(%ld)\n", sizeof(x));
}

void goo(int (&x)[5])
{
    printf("goo: sizeof(%ld)\n", sizeof(x));
}

int main()
{
    int x[5];
    printf("main: sizeof(%ld)\n", sizeof(x));

    foo(x);
    goo(x);
}