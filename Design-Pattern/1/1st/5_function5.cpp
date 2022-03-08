#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}

//gcd 함수를 double에 대해서 사용할 수 없도록 하고 싶다
// 의도적으로 함수읠 선언부만 제공합니다.
//double gcd(double a, double b); // 핵심: 선언만 한다.

// c++ delete function
//함수를 삭제하는 문법
// 컴파일 오류가 발생
double gcd(double a, double b) = delete;

int main()
{
    cout << gcd(2, 10) << endl;
    cout << gcd(2.2, 4.3) << endl;
    //double이 int로 암묵적인 형변환되서 동작함
    //동작하면 안되는 코드입니다
}