#include <iostream>
using namespace std;

//operator(연산자)
// +, -, =, << ...

class Point
{
private:
    int x;
    int y;

public:
    Point(int a, int b) : x(a), y(b) {}

    Point Add(const Point &rhs)
    {
        return Point(x + rhs.x, y + rhs.y);
    }

    void Print() const
    {
        cout << x << ", " << y << endl;
    }

    // 1. 값을 읽는 함수를 제공
    // int GetX() const { return x; }
    // int GetY() const { return y; }

    // 2. friend로 선언된 함수나 클래스는 private 접근이 가능
    friend Point operator+(const Point &lhs, const Point &rhs);
};

//연산자 오버로딩
// : 연산자를 객체에 대해서 사용할 떄, 약속된 함수가 호출;

Point operator+(const Point &lhs, const Point &rhs)
{
    return Point(lhs.x + rhs.x, lhs.y + rhs.y);
    //return Point(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
}

int main()
{
    Point p1(1, 1);
    Point p2(1, 10);

    Point p3 = p1 + p2;
    // Point p3 = p1.operaror + (p2);
    // Point p3 = operator + (p1,p2);
    // : 위의 형태로 번역
    //Point p3 = p1.Add(p2);

    p3.Print();
}