#include <iostream>
using namespace std;

// int square(int a) { return a * a; }
// double square(double b) { return b * b; }
//리턴 타입과 파라미터 타입을 제외하면 구현이 완전히 동일하다
// 사용자가 템플릿을 제공하면 컴파일러가 코드를 컴파일할때 어떤 함수가 필요한지
//조사해서 실제 함수를 생성해 줍니다
// c++은 템플릿, 나머지는 제네릭이라고 부른다.

template <typename T> //typename 대신 class를 사용해도 된다.
T square(T a)
{
    return a * a;
}

int main()
{
    cout << square(3) << endl;
    cout << square(3.14) << endl;
}