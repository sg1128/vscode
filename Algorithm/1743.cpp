#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int N, M, K;
int graph[101][101];

// 4가지 경우
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y,int cnt)
{
        graph[x][y] = 2;
        for (int i = 0; i < 4; ++i)
        {
            int a = dx[i] + x;
            int b = dy[i] + y;
            // a와b가 MN크기를 벗어나지 않고 0보다 크면 다시 dfs돌림
            if (a >= 1 && b >= 1 && a <= N && b <= M)
            {
                if (graph[a][b] == 1)
                {
                    cnt = max(cnt, dfs(a, b, cnt + 1));
                }
            }
        }
    return cnt;
}

int main()
{
    int cnt = 1;
    int count = 0;
    int x, y;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < K; i++)
    {
        cin >> x >> y;
        graph[x][y] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (graph[i][j] == 1)
            {
                count = max(count, dfs(i, j, cnt));
            }
        }
    }

    cout << count << endl;
}