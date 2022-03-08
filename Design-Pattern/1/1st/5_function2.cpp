#include <iostream>
using namespace std;

//C++에서는 파라미터의 타입이나 개수가 다르면
//동일한 이름의 함수를 여러개 만들 수 있습니다
//함수 오버로딩 이라고 부름
//컴파일러가 함수의 파라미터 정보를 통해 이름을 생성
//파라미터의 개수와 타입이 다르면 다른 이름이 생성
//네임 맹글링 이라고 한다
//주의사항
// - 반환 타입은 함수 이름에 영향을 미치지 않는다.
//파라미터가 동일하고 반환 타입이 다른 함수는 오버로딩이 불가능

int square(int x)
{
    return x * x;
}

double square(double x)
{
    return x * x;
}

int main()
{
    cout << square(3) << endl;
    cout << square(2.2) << endl;
}