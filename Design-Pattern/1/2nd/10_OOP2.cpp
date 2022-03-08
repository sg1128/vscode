#include <iostream>
using namespace std;

//Stack을 만들어 봅시다.
// 우선순위 큐 : 스택-LIFO(후위선출), 큐-FIFO(선입선출)...

// 1)전역 변수/함수를 이용한 스택

// int buff[10];
// int idx = 0;

// void push(int v)
// {
//     buff[idx++] = v;
// }

// int pop()
// {
//     return buff[--idx];
// }

// int main()
// {
//     push(10);
//     push(20);

//     cout << pop() << endl;
//     cout << pop() << endl;
// }

// 2)Stack 타입을 설계

// struct Stack
// {
//     int buff[10];
//     int idx;
// };

// void push(Stack *s, int v)
// {
//     s->buff[s->idx++] = v;
// }

// int pop(Stack *s)
// {
//     return s->buff[--s->idx];
// }

// Stack s1;
// int main()
// {
//     Stack s2;

//     //초기화 필요
//     s1.idx = 0;
//     s2.idx = 0;

//     push(&s1, 10);
//     push(&s1, 20);
//     push(&s2, 20);
//     push(&s2, 30);

//     cout << pop(&s1) << endl;
//     cout << pop(&s1) << endl;
//     cout << pop(&s2) << endl;
//     cout << pop(&s2) << endl;
// }

//3) 상태를 나타내는 데이터와 상태를 조작하는 함수를 묶자
//4) 구조체 내부의 데이터를 외부에서 함부로 조작할 수 없도록 정보 은닉이 필요
//  접근 지정자
//  구조체는 접근 지정자를 사용하지 않을 경우
//  기본적으로 public이 된다.
// class -> 기본 접근 지정이 private

// 5)생성자 함수를 도입
// 생성자 함수 이름이 클래스 이름과 동일, 반환 타입을 표기하지 않는다.

// struct Stack
// {
//     //멤버 변수(데이터)
// private:
//     int buff[10];
//     int idx;

//     //멤버 함수
//     //  멤버 데이터에 접근하는 함수
//     //  명시적인 함수 인자로 Stack*을 받을 필요가 없음
// public:
//     Stack()
//     {
//         idx = 0;
//     }

//     void push(int v)
//     {
//         buff[idx++] = v;
//     }

//     int pop()
//     {
//         return buff[--idx];
//     }
// };

// Stack s1;
// int main()
// {
//     Stack s2;

//     s1.push(10);
//     s1.push(30);
//     s2.push(40);
//     s2.push(1);

//     cout << s1.pop() << ", " << s1.pop() << endl;
//     cout << s2.pop() << ", " << s2.pop() << endl;
// }

// 6)사용자가 스택의 크기를 결정할 수 있도록 한다.
// 생성자는 인자를 가져도 되고, 인자를 가지지 않아도 된다.
// 생성자는 오버로딩이 가능하다.
// 7) 더이상 객체를 사용하지 않을 때, 객체가 파괴 되는 시점에 호출되는 함수
//  소멸자 : ~클래스이름()
//  반환 타입을 표기하지 않는다, 인자를 가질수 없다, 객체가 파괴되는 시점에 수행

struct Stack
{
    //멤버 변수(데이터)
private:
    int *buff;
    int idx;

public:
    // Stack()
    // {
    //     cout << "Stack()" << endl;
    //     idx = 0;
    // }

    Stack(int sz = 10)
    {
        idx = 0;
        buff = new int[sz]; // 사용자가 전달한 크기 만큼 버퍼를 할당
    }

    void push(int v)
    {
        buff[idx++] = v;
    }

    int pop()
    {
        return buff[--idx];
    }

    ~Stack()
    {
        delete buff;
    }
};

Stack s1(200);
int main()
{
    Stack s2(100);

    s1.push(1230);
    s1.push(301);
    s2.push(140);
    s2.push(123);

    cout << s1.pop() << ", " << s1.pop() << endl;
    cout << s2.pop() << ", " << s2.pop() << endl;
}