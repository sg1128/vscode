#include <iostream>
using namespace std;

struct Point
{
    int x, y;
};

// int main()
// {
//     int n1 = 42;
//     int n2(42); // C++초기화 문법, 일반 변수가능

//     cout << n1 << endl
//          << n2 << endl;
//     // () 초기화: 직접 초기화
//     // = 초기화: 복사 초기화

//     Point p = {10, 20};
//     int x[3] = {10, 20, 30};
// }

int main()
{
    int n3 = 3.14; //warning
    cout << n3 << endl;

    //int n4{3.14};
    //데이터 손실이 발생하는 잘못된 초기화에 대해서 컴파일 오류가 발생

    int n1 = {0};
    int x[3] = {1, 2, 3};
    Point p1 = {10, 20};

    int n2{0};
    int x2[3]{1, 2, 3};
    Point p2{10, 20};
}