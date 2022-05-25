#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>> tomato;
vector<int> singsing_tomato;
int count = 0;
int M, N;

void dfs(int x, int y)
{
    // 만약 1이면 0으로 바꿈
    if (tomato[x][y] == 1)
    {
        tomato[x][y] = 0;
        for (int i = 0; i < 4; ++i)
        {
            int a = dx[i] + x;
            int b = dy[i] + y;
            // a와b가 MN크기를 벗어나지 않고 0보다 크면 다시 dfs돌림
            if (a >= 0 && b >= 0 && a < M && b < N)
            {
                dfs(a, b);
            }
        }
    }
}

int main()
{
    cin >> M >> N;

    for(int i= 0; i<N;i++)
    {
        for(int j=0; j<M; j++)
        {
            int num;
            cin >> num;
            singsing_tomato.push_back(num);
        }
        tomato.push_back(singsing_tomato);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << tomato[i][j]<<  " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(tomato[i][j]==1)
            {
                dfs(i,j);
            }
        }
    }
}