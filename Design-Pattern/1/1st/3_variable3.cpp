#include <iostream>
using namespace std;

//C++함수는 배열을 인자로 전달 받을 때
// decay(부식)를 수행
// 배열의 첫번째 원소의 시작 주소가 전달
// 배열을 전달받는 함수는 반드시 길이에 대한 추가정보를 인자를 통해 전달해야 한다
// void foo(int *x, int n)
// {
//     for (int i = 0; i < n; ++i)
//         cout << x[i];
//     cout << endl;
// }

// void goo(int (*p)[5])
// {
// }

//int*p[3]- 포인터배열
//int(*p)[3] - 배열 포인터
// int main()
// {
//     int z[3][5];
//     //z의 탑입 : int[3][5]
//     goo(z);

//     int y[3] = {1, 2, 3}; //y랑 x는 타입이 정확하게는 다르다
//     foo(y, 3);

//     auto a = y[0];
//     //auto를 사용하면, 우항의 타입과 동일한 타입으로 컴파일 타임에 결정

//     int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //y는 인트가 3개인 배열 x는 인트가 10개인 배열
//     foo(x, 10);
// }

void hoo(int (*p)[3])
{
}

typedef int (*Pointer)[3];
void goo(Pointer p)
{
}

//C++11에서는 typedfe 말고, using을 통해서 타입의 별칭을 만들 수 있다.
//1)가독성이 좋다
//2) typedef 는 템플릿의 문법에서는 사용할 수 없다.
using Pointer2 = int (*)[3];
void xoo(Pointer2 p)
{
}

int main()
{
    int x[2][3];
    hoo(x);
    goo(x);
}