#include <iostream>
#include <vector>
using namespace std;

// 1.자식 클래스의 공통의 기능을 부모 타입 포인터를 통해 이요하기 위해서는
// 해당 기능이 반드시 부모 클래스에서 비롯되어야 한다

// 2. 부모클래스가 제공하는 함수를 자식 클래스가 오버라이딩 할 경우
//    해당 함수는 반드시 가상이여야 한다.

// 3. 가상 함수가 존재하는 모든 부모 클래스는 반드시 가상 소멸자이여야 한다.

class Shape
{
public:
    virtual ~Shape() {}

    //Shape의 객체를 생성하지 않으면, 아래 함수는 호출되지 않는다.
    // 4.부모입장에서 구현을 제공할 필요가 없고, 자식이 반드시 재정의를 해야한다면
    //   "순수 가상 함수" 이용해야 한다

    // 5. 순수 가상 함수를 1개이상 가지고 있는 클래스는 "추상 클래스"라고 한다.
    //    = 추상클래스는 인스턴스화가 불가능하다.
    virtual void Draw() = 0;

#if 0
    virtual void Draw()
    {
        cout << "Shape Draw" << endl;
    }
#endif
};

class Rect : public Shape
{
public:
    ~Rect() { cout << "~Rect" << endl; }

    // 6. 부모 클래스의 순수 가상 함수를 오버라이딩 해서, 구현 하지 않을 경우
    //    자신도 추상 클래스로 취급받는다.
    void Draw() override
    {
        cout << "Rect draw" << endl;
    }
};

class Circle : public Shape
{
public:
    ~Circle() { cout << "~Circle" << endl; }
    void Draw() override
    {
        cout << "Circle draw" << endl;
    }
};

int main()
{
    vector<Shape *> v;

    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Rect);
    v.push_back(new Circle);

    // for (int i = 0; i < v.size(); ++i) {
    //    v[i]->Draw();
    // }
    for (Shape *p : v)
    {
        p->Draw();
    }

    for (Shape *p : v)
    {
        delete p;
    }
}