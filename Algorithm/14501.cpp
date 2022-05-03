#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int M_res = 0;
    int F_res = 0;

    int **arr = new int *[N];
    for (int i = 0; i < N; i++)
        arr[i] = new int[2];

    int *money = new int[N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
            money[i] = arr[i][1];
        }
    }
    for (int i = 0; i < N; i = i + arr[i][0])
    {
        if (i + arr[i][0] + arr[i + arr[i][0]][0] < N)
        {
            money[i + arr[i][0]] = money[i] + money[i + arr[i][0]];
            if (F_res < money[i + arr[i][0]])
                F_res = money[i + arr[i][0]];
        }
    }

    cout << F_res << endl;

    delete[] money;

    for (int i = 0; i < N; i++)
        delete[] arr[i];

    delete[] arr;
}

/*
    비교

*/
