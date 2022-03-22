#include <iostream>
using namespace std;

int main()
{
    int n = 0, m = 0;
    int num1 = 0, num2 = 0;
    int v = 0;
    int res = 10000;
    cin >> n >> m;
    char arr[50][50];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    if (n < 8 || n > 50 || m < 8 || m > 50)
    {
        cout << "error!" << endl;
    }
    else
    { 
        int a = n - 8 + 1;
        int b = m - 8 + 1;
        int c = a * b;
        int k1 = 0, k2 = 0;
        int h1 = 8, h2 = 8;
        for (int z = 0; z < c; z++)
        {
            for (int i = k2; i < h2; i++)
            {
                for (int j = k1; j < h1; j++)
                {
                    if ((i + j) % 2 == 0) //짝수
                    {
                        if (arr[i][j] == 'B')
                            num1++;
                        else if (arr[i][j] == 'W')
                            num2++;
                    }
                    else if ((i + j) % 2 == 1) //홀수
                    {
                        if (arr[i][j] == 'W')
                            num1++;
                        else if (arr[i][j] == 'B')
                            num2++;
                    }
                }
            }
            k1++;
            h1++;
            if (h1 > m)
            {
                k2++;
                h2++;
                k1 = 0;
                h1 = 8;
            }
            if (num1 >= num2)
            {
                if (num2 < res)
                    res = num2;
            }
            else
            {
                if (num1 < res)
                    res = num1;
            }
            num1 = 0, num2 = 0;
        }
        cout << res << endl;
    }
}