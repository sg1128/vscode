#include <iostream>
using namespace std;
void star(int n);

int main()
{
    int n = 0;
    cin >> n;

    int k = n / 3;

    if (n % 3 != 0 || k % 2 == 0)
    {
        cout << "error!" << endl;
    }
    else
    {
        star(n);
    }
}

void star(int n)
{
    for (int i = 0; i < n;   i++)
    {
        for (int j = 0, k; j < n; j++)
        {
            for (k = n / 3; k >= 1; k /= 3)
            {
                if (i / k % 3 == 1 && j / k % 3 == 1)
                {
                    cout << " ";
                    break;
                }
            }
            if (!k)
                cout << "*";
        }
        cout << endl;
    }
}