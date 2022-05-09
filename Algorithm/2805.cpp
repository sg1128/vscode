#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    vector<int> treeH;
    int tH;
    int meter = 0;
    int count = 0;
    int res = 0;
    cin >> N >> M;
    for (int k = 0; k < N; k++)
    {
        cin >> tH;
        treeH.push_back(tH);
        if(res < tH)
        {
            res = tH;
        }
    }

    int i = 0;
    int HighTree = res;

    while (1)
    {
        if (treeH[i] == HighTree)
        {
            treeH[i] -= 1;
            meter += 1;
        }
        i++;
        if(i==N)
        {
            count++;
            i = 0;
            HighTree -= 1;
        }
        if (meter >= M)
        {
            break;
        }
    }
    cout << res - count << endl;
}