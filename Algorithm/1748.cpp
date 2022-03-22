#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string intLength;
    int res = 0;
    intLength = to_string(N);
    if (N > 0 && N <= 100000000)
    {
        for (int i = 1; i <= N; i *= 10)
        {
            res += N - i;
        }
    }
    else
    {
        cout << "error!" << endl;
    }
    cout << res + intLength.length() << endl;

    return 0;
}