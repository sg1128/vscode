#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int N, M, K; 
int graph[51][51];

//4가지 경우
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    // 만약 1이면 0으로 바꿈
    if(graph[x][y] ==1 ){
        graph[x][y] = 0;
        for(int i=0; i<4; ++i)
        {
            int a=dx[i] +x;
            int b=dy[i] + y;
            //a와b가 MN크기를 벗어나지 않고 0보다 크면 다시 dfs돌림
            if(a>=0 && b>=0 && a<M && b<N)
            {
                dfs(a,b);
            }
        }
    }
}

int main()
{
    int T;
    int X, Y;

    cin >> T;
    for (int k = 0; k < T; k++)
    {
        int count=0;
        cin >> M >> N >> K;
        for(int i=0; i<51; i++)
        {
            for (int j = 0; j < 51; j++)
            {
                graph[i][j] = 0;
            }
        }

        for (int i = 0; i < K; i++)
        {
            cin >> X >> Y;
            graph[X][Y] = 1;
        }
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N;j++)
            {
                if(graph[i][j] == 1)
                {
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}