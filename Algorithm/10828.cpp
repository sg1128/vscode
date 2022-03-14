#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string *array = new string[N];
    if (N >= 1 && N <= 10000)
    {
        for (int i = 0; i < N; i++)
        {
        }
    }
    else
    {
        cout << "error!" << endl;
    }

    delete[] array;
    return 0;
}

/*
push 1을 입력하면
*/