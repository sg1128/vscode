#include <iostream>
using namespace std;
#include <string.h>
//C언어에서는 문자여을 다룰 떄,
//char 배열 또는 const char* 를 사용

// int main()
// {
//     char s1[] = "hello";
//     const char *s2 = "hello";

//     if (s1 == s2)
//     {
//     }
//     if (strcmp(s1, s2) == 0)
//     {
//         printf("동일한 문자열 입니다...\n");
//     }
// }

int main()
{
    std::string s1 = "hello";
    std::string s2 = "hello";

    if (s1 == s2)
    {
        printf("동일한 문자열 입니다...\n");
    }

    std::string s3 = s2;
    cout << s1 << ", " << s2 << ", " << s3 << endl;
}