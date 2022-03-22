#include <iostream>
using namespace std;

int findBW(int *square[], int N, int r, int c);
int blue = 0, white = 0;

int main()
{
    int N = 0;
    cin >> N;
    int **square = new int *[N];
    for (int i = 0; i < N; i++)
        square[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> square[i][j];

    findBW(square, N, 0, 0); // 함수 호출

    for (int i = 0; i < N; i++)
        delete[] square[N];
    delete[] square;

    cout << white << endl
         << blue << endl;
    return 0;
}

int findBW(int *square[], int N, int r, int c)
{
    int temp = square[r][c];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (square[i + r][j + c] != temp)
            {
                findBW(square, N / 2, r, c);
                findBW(square, N / 2, r + (N / 2), c) +
                    findBW(square, N / 2, r, c + (N / 2)) +
                    findBW(square, N / 2, r + (N / 2), c + (N / 2));
                return 0; // 재귀함수, 4가지 상황
        
            }
        }
    }
    if (temp == 1)
    {
        blue++;
    }
    else
        white++;
    return 0;
}

/*
8
0,0 ~ 7,7 r 0 7
4
0,0~ 3,3 / r 0~3 c 0~3
0,4 ~ 3,7 r 0~3 c 4~7
4,0 ~ 7,3 r 4~7 c 0~3
4,4 ~ 7,7 r4~7 c 4~7

2
4,4 5,5
4,6 5,6
6,4 7,5
6,6, 7,7

1 0
0 1
*/