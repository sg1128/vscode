#include <iostream>
using namespace std;

#if 0
class Test {
 public:
  Test() { cout << "자원 획득" << endl; }
  ~Test() { cout << "자원 반납" << endl; }
};

int main() {
  // Test t;
  Test* t = new Test;
  delete t;
}
#endif

class Base
{
public:
    Base() { cout << "Base()" << endl; }
    virtual ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived()" << endl; }
    virtual ~Derived() { cout << "~Derived()" << endl; }
};

int main()
{
// Derived d;
#if 0
Base()
Derived()
~Derived()
~Base()
#endif

    Base *p = new Derived;
    delete p;
    // 소멸자도 함수 입니다.
    // 일반적인 소멸자는 정적 바인딩 기반으로 동작합니다.
    // 업캐스팅의 기반으로 코드를 작성할 경우, 반드시 소멸자가 가상 소멸자이어야
    // 합니다.

#if 0
Base()
Derived()
~Base()
#endif
}

// 실행 -> \\wsl$
// /home/xxxx/