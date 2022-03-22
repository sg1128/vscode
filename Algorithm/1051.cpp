#include <iostream>
using namespace std;

int main()
{
    int N = 0, M = 0;
    int count = 1;
    int res = 1;
    cin >> N >> M;

    char arr[51][51];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    }

    int length = N < M ? N : M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 1; k <= length; k++)
            {
                if (k + i > N || k + j > M)
                    continue;
                if (arr[i][j] == arr[i + k][j] && arr[i + k][j] == arr[i][j + k] && arr[i][j + k] == arr[i + k][j + k])
                {
                    if (res < (k + 1) * (k + 1))
                        res = (k + 1) * (k + 1);
                }
            }
        }
    }

    cout << res << endl;
}
