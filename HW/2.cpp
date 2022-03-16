#include <iostream>
using namespace std;

int main()
{
    cout << "20181498 박선균" << endl;
    char *hamming = new char[13];
    char *parity = new char[4];

    cout << "해밍코드를 입력하시오." << endl;
    cin >> hamming;
    cout << "입력된 해밍코드: " << hamming << endl;

    parity[0] = hamming[7] ^ hamming[8] ^ hamming[9] ^ hamming[10] ^ hamming[11];
    parity[1] = hamming[3] ^ hamming[4] ^ hamming[5] ^ hamming[6] ^ hamming[11];
    parity[2] = hamming[1] ^ hamming[2] ^ hamming[5] ^ hamming[6] ^ hamming[9] ^ hamming[10] ^ '0';
    parity[3] = hamming[0] ^ hamming[2] ^ hamming[4] ^ hamming[6] ^ hamming[8] ^ hamming[10] ^ '0';

    if (parity[0] == '1' || parity[1] == '1' || parity[3] == '1' || parity[7] == '1')
    {
        int res = 0;
        if (parity[0] == '1')
        {
            res += 8;
        }
        if (parity[1] == '1')
        {
            res += 4;
        }
        if (parity[2] == '1')
        {
            res += 2;
        }
        if (parity[3] == '1')
        {
            res += 1;
        }

        if (hamming[res - 1] == '0')
        {
            hamming[res - 1] = '1';
        }
        else
            hamming[res - 1] = '0';
        cout << res << "번째 비트에 에러 발생. 수정된 코드 : " << hamming << endl;
    }
    else
    {
        cout << "에러 없음" << endl;
    }

    delete[] hamming;
    delete[] parity;
}