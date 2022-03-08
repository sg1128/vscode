#include <iostream>
using namespace std;

// 1. 정적 멤버 변수 / 정적 멤버 함수는 객체를 생성하지 않아도 호출하거나 접근이 가능
// => 정적 멤버 함수에서는 오직 정적 멤버 데이터칸 접근이 가능

class Sample
{
    //int data;

    int data = 42; // C++11 부터 허용
    static int cnt;

    static const int data2 = 100;
    // 상수 정적 멤버 데이터는 클래스 내부에서 초기화를 허용합니다.
public:
    //Sample() : data(42) {}
    // static void foo()
    // {
    //     cnt = 0;
    // }
    static void foo();
};

// 정적 멤버 함수를 외부에 분리해서 정의할 때는
// static 키워드를 사용하지 않는다

//static
void Sample::foo()
{
    cnt = 0;
}

int Sample::cnt = 0;

int main()
{
}