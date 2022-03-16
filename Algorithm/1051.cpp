#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char vertex[4];

    char **arr = new char *[N];
    for (int i = 0; i < N; i++)
        arr[i] = new char[M];

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    if (N <= 50 && M <= 50)
    {
        vertex[0] = arr[0][0];
        vertex[1] = arr[0][M - 1];
        vertex[2] = arr[N - 1][0];
        vertex[3] = arr[N - 1][M - 1];

        for (int ver = 0; ver < 4; ver++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                }
            }
        }
    }
    else
        cout << "error!" << endl;
}

/* 꼭짓점을 다 찾는다
    그다음에 그 꼭짓점과 같은 숫자들을 찾아서 그 위치를 저장한다
    만약에 위치가 4개가 되지않으면 1을 출력한다
    그 위치가 정사각형의 위치가 아니면 1을 출력한다

    한개의 꼭짓점의 숫자에서 가장 큰숫자를 찾고
    4개의 꼭짓점의 숫자에서 가장 큰 숫자를 찾으면 된다.
*/