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
