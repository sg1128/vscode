#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Standard Template Library
// => C++에서 제공하는 템플릿 기반의 라이브러리
// => 자료구조(컨테이너, 컬렉션)

// 연속된 메모리 형태의 선형적인 자료 구조 <vector>
// 장점: 임의 접근이 빠르다, 단점: 중간 삽입, 삭제가 비용이 생긴다

// 연결 리스트 기반의 선형적인 자료 구조 <list>
// 장점: 중간 삽입, 삭제가 빠르다. 단점: 탐색이 비교적 느리다.

/*
int main()
{
    std::stack<int> s;
    s.push(10);
    s.push(30);

    //C++은 pop() 연산이 분리되어 있습니다
    // - 가장 마지막 요소를 체크하는 함수 : top()
    // - 스택에서 요소를 제거하는 함수    : pop()

    std::cout << s.top() << endl;
    s.pop();
    std::cout << s.top() << endl;
    s.pop();

    std::vector<int> v;
    v.push_back(10);
    v.push_back(15);
    for (int e : v)
    {
        std::cout << e << std::endl;
    }
}
*/

// 탐색
// 1. Tree        => <map>
//  - 탐색: O(logN)
//  - 정렬: O(N)

// 2. Hashtable  => <unordered_map>
//  - 탐색: O(1)
//  - 데이터 저장되는 순서가 다릅니다.
//   => 퀵소트: O(NlogN)

//map => 키-값 쌍으로 이루어진 데이터

#include <map>
int main()
{
    std::map<std::string, std::string> data;
    data["홍길동"] = "010-1234-5678";
    data["이순신"] = "010-1111-2222";

    std::cout << data["홍길동"] << std::endl;
    std::cout << data["이순신"] << std::endl;
}