#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N1, N2, T;
    cin >> N1 >> N2;
    char ant;
    vector<char> group1;
    vector<char> group2;
    vector<char> addgroup;
    char temp;

    for (int i = 0; i < N1; i++)
    {
        cin >> ant;
        group1.push_back(ant);
    }
    for (int i = 0; i < N2; i++)
    {
        cin >> ant;
        group2.push_back(ant);
    }
    cin >> T;

    // 정렬하기
    for (int i = 0; i < N1; i++)
    {
        addgroup.push_back(group1.back());
        group1.pop_back();
    }
    for (int i = 0; i < N2; i++)
    {
        addgroup.push_back(group2[i]);
    }

    int idx;
    //몇초인지
    for (int sec = 0; sec < T; sec++)
    {
        // addgroup을 살피고
        for (int i = 0; i < N1 + N2; i++)
        {
            // 만약 addgroup[i]가 group1의 일원이고 addgroup[i+1]이 group2의 일원이면 위치를 바꾼다..
            for (int j = 0; j < N1; j++)
            {
                for (int k = 0; k < N2; k++)
                {
                    if (addgroup[i] == group1[j] && addgroup[i + 1] == group2[k])
                    {
                        temp = addgroup[i + 1];
                        addgroup[i + 1] = addgroup[i];
                        addgroup[i] = temp;
                        i++; // i++를 하지않으면 끝까지 가는현상
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N1 + N2; i++)
    {
        cout << addgroup[i];
    }
}

/*
    같은 그룹의 개미가 아니면 크로스 해서 지나간다.
    만약 같은 그룹이면 그냥 같이 직진한다.
    그럼 같은 그룹의 개미인지 확인을 해야하는게 가장 중요함.

    addgroup에서 그룹1의 첫번째 개미를 찾고 그룹2의 첫번재 개미를 찾는다
    그다음 자리를 바꾼다.
    그다음 1의 첫번째 개미와 2의 두번째 개미랑 바꾼다. 반대도 적용
    만약 다른 그룹의 개미가 없다 그냥 내비둔다.

    여기서 가장 문제는 바꾸는것이 가장 문제

*/