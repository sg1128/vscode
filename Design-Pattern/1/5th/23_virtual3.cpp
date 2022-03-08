#include <iostream>
using namespace std;

class A
{
    int a;

public:
    virtual void foo() { cout << "foo" << endl; }
};

class B
{
    int b;

public:
    virtual void goo() { cout << "goo" << endl; }
};

int main()
{
    A aaa;
    B *p = reinterpret_cast<B *>(&aaa);

    p->goo(); //정적바인딩 - goo 동적바인딩 - foo
}