#include <iostream>
using namespace std;

int main()
{
    cout << "20181498 박선균" << endl;
    char *input = new char[100];
    cout << "비트열을 입력하시오." << endl;
    cin >> input;
    cout << "입력된 비트열: " << input << endl;

    char crc[4] = "000";
    char bit = 0;

    for (int i = 0; i < 6; i++)
    {
        if (input[i] == crc[0])
        {
            bit = '0';
        }
        else
        {
            bit = '1';
        }
        if (bit == crc[1])
        {
            crc[0] = '0';
        }
        else
        {
            crc[0] = '1';
        }
        crc[1] = crc[2];
        crc[2] = bit;
        cout << i << " : " << crc << endl;
    }
    cout << "FCS : " << crc << endl;
    delete[] input;
}