#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point() : x(0), y(0)
    {
        cout << "Point()" << endl;
    }
    Point(int a, int b) : x(a), y(b)
    {
        cout << "Point(int, int)" << endl;
    }

    Point(const Point &rhs) : x(rhs.x), y(rhs.y)
    {
        cout << "Point(const Point& rhs)" << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
};

/*
int main()
{
    // 복사 생성자는 언제 호출되는가?
    // 1. 객체를 만들 때 자신과 동일한 타입으로 초기화되는 경우 호출

    Point p1;     //Ponit
    Point p2(p1); // Point(const Point&)

    Point p3 = p1; // Point(const Point&)

    Point p4{p1};
    Point p5 = {p1};
}
*/

// void foo(Point p)
// 1) 복사본을 위한 추가적인 메모리 사용
// 2) 복사 생성자, 소멸자 함수 호출에 따른 오버헤드가 있다.

/*
void foo(Point p) //Point(const Point&)
{
    //~Point() - foo함수가 끝날 때 p객체가 파괴되면서 호출
}

int main()
{
    Point p1; //Point()
    foo(p1);

    //~Point() - p1객체가 파괴되면서 호출
}
*/

/*
void foo(const Point &p)
{
}

int main()
{
    Point p1; //Point()
    foo(p1);

    //~Point() - p1객체가 파괴되면서 호출
}
*/

// 3. 함수가 객체를 값으로 변환할 때

Point p;
Point &foo()
{
    return p;
    // 이 순간 반황용 임시 객체가 생성
    // p를 복사해서 만들기 떄문에, 복사 생성자가 호출
}

int main()
{
    foo();
    // 리턴 값으로 돌아온 객체는 p가 아니라 반환용 임시 객체가 전달
    // 반환용 임시객체는 함수 호출문장 끝에서 파괴
    cout << "end main" << endl;
}