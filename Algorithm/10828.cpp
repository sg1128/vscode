#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void push(int, int[]);
void pop(int[]);
void top(int[]);
void size();
bool empty();

int count = -1;

int main()
{
    int N;
    int x;
    cin >> N;
    string *input = new string[N];
    int *output = new int[N];
    if (N >= 1 && N <= 10000)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> input[i];
            if (input[i].compare("push") == 0)
            {
                cin >> x;
                push(x, output);
            }
            else if (input[i].compare("pop") == 0)
            {
                pop(output);
            }
            else if (input[i].compare("top") == 0)
            {
                top(output);
            }
            else if (input[i].compare("size") == 0)
            {
                size();
            }
            else if (input[i].compare("empty") == 0)
            {
                if (empty())
                {
                    cout << "1" << endl;
                }
                else
                    cout << "0" << endl;
            }
        }
    }

    else
    {
        cout << "error!" << endl;
    }

    delete[] input;
    delete[] output;
    return 0;
}

void push(int x, int output[])
{
    output[++count] = x;
}
void pop(int output[])
{
    if (empty())
    {
        cout << "-1" << endl;
    }
    else
        cout << output[count--] << endl;
}
void top(int output[])
{
    if (empty())
    {
        cout << "-1" << endl;
    }
    else
        cout << output[count] << endl;
}
void size()
{
    cout << count + 1 << endl;
}
bool empty()
{
    return (count < 0);
}

/*
배열 2개를 만들고 1개는 넣고 빼는 용도
나머지는 그 값을 넣는 용도 (pop, top, size, empty)
*/