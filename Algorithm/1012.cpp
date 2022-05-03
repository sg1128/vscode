#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int dx[4] = { 0,0,1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int graph[][50], int x, int y)
{
    if(graph[x][y] ==1 ){
        graph[x][y] = 2;
        dfs(graph, x + 1, y);
        dfs(graph, x - 1, y);
        dfs(graph, x , y+1);
        dfs(graph, x  ,y-1);
    }
}

int main()
{
    int T;
    int N, M, K;
    int X, Y;

    cin >> T;
    for (int k = 0; k < T; k++)
    {
        int count=0;
        cin >> M >> N >> K;
        int graph[50][50] = {0,};

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
                    dfs(graph, i, j);
                    count++;
                }
            }
        }
        cout << count << endl;
        memset(graph, 0, sizeof(graph));
    }
}