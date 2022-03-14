#include <iostream>
using namespace std;

int main()
{
    int arr[4];
    int res[10001] = {
        0,
    };

    for (int num = 0; num < 10000; num++)
    {
        if (num > 0 && num <= 9)
        {

            res[num + num] = num;
        }
        else if (num >= 10 && num <= 99)
        {
            arr[0] = num / 10;
            arr[1] = num % 10;
            res[num + arr[0] + arr[1]] = num;
        }
        else if (num >= 100 && num <= 999)
        {
            arr[0] = num / 100;
            arr[1] = (num - (arr[0] * 100)) / 10;
            arr[2] = (num - (arr[0] * 100)) % 10;
            res[num + arr[0] + arr[1] + arr[2]] = num;
        }
        else if (num >= 1000 && num <= 9999)
        {
            arr[0] = num / 1000;
            arr[1] = (num - arr[0] * 1000) / 100;
            arr[2] = (num - arr[0] * 1000 - arr[1] * 100) / 10;
            arr[3] = (num - arr[0] * 1000 - arr[1] * 100) % 10;
            if (num + arr[0] + arr[1] + arr[2] + arr[3] <= 10000)
                res[num + arr[0] + arr[1] + arr[2] + arr[3]] = num;
        }
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (res[i] == 0)
            cout << i << endl;
    }
}

/* 1 2 3 4 5 6 7 8 9
    1->2->4->8
    3->6
    5->10
    7
    9

    11~100
    11->13->17->25->32->37->47->58->71->79->95
    12->15->21->24->30->33->39->
*/