#include <iostream>
using namespace std;
#include "Stack.h"

Stack s1(200);
int main()
{
    Stack s2(100);

    s1.push(120);
    s1.push(301);
    s2.push(140);
    s2.push(123);

    cout << s1.pop() << ", " << s1.pop() << endl;
    cout << s2.pop() << ", " << s2.pop() << endl;

    // g++ -c Stack.cpp -std=c++11
    // g++ -c main.cpp -std=c++11
    // g++ main.o Stack.o
    // ./a.out
}
