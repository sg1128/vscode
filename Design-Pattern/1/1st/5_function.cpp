#include <iostream>
using namespace std;

//Default parameter
//  :함수에서 전달되는 인자가 없는 경우, 기본값을 사용
//  > 기본값을 지정할 떄 뒤에서 부터 지정

//함수를 선언과 구헌으로 분리할 때는 선언부에만 기본값을 표ㅎ기
void foo(int a, int b, int c = 5, int d = 20)
{
    cout << a << ", " << b << ", " << c << ", " << d << endl;
}

int main()
{
    foo(10, 20, 30, 40);
    foo(20, 30);
}