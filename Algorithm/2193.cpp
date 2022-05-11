/*
1 10 100 101 1000 1001 1010 10000 10001 10010 10100 10101 100000 100001 100010 100100 1
1 2 4 5 8 9 10 16 17 18 20 21
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<long int> list;
    list.push_back(1);
    list.push_back(1);

    int N;
    cin >> N;

    for (int i = 2; i < N; i++)
    {
        list.push_back(list[i - 1] + list[i - 2]);
    }
    cout << list[N - 1] << endl;
}
