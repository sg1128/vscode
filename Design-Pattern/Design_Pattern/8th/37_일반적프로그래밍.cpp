#include <iostream>
using namespace std;

// C++ 표준 라이브러리를 이해하기 위해서는 일반화를 이해해야 합니다.
// C++ = 객체 지향 + 일반화(Generic)

#if 0
char* xstrchr(char* s, char c)
{
    while(*s != '\0' && *s != c)
        s++;

    return *s == c ? s : NULL;
}

int main()
{
    char s[] = "abcdefg";

    char *p = xstrchr(s, 'c');

    if(p)
        cout << *p << endl;
}
#endif

// 1. 검색 구간의 일반화 : 전체 구간에서 부분 구간에 대한 검색이 가능해야 합니다.
// > 검색할 구간의 시작과 검색할 구간의 마지막 다음 위치를 인자로 전달받도록 해야합니다.
// 처음과 마지막다음 위치는 반개구간이라고 합니다.

#if 0
char *xstrchr(char *first, char *last, char value)
{
    while (first != last && *first != value)
        ++first;

    return first == last ? nullptr : first;
}

int main()
{
    char s[] = "abcdefg";

    char *p = xstrchr(s, s + 7, 'd');
    if (p)
        cout << *p << endl;
}
#endif

// 2.검색 대상 타입의 일반화 => Template 도입
// T* 라고 하면, 포인터 타입만 가능합니다. -> T1 = T*

template <typename T1, typename T2>

T1 xfind(T1 first, T1 last, T2 value)
{
    while (first != last && *first != value)
        ++first;

    return first;
}

#include <vector>

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    auto p2 = xfind(v.begin(), v.end(), 3);
    if (p2 != v.end())
        cout << *p2 << endl;

    char s[] = "abcdefg";

    char *p = xfind(s, s + 7, 'e');
    if (p)
        cout << *p << endl;
}