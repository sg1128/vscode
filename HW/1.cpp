#include <iostream>
using namespace std;

int main()
{
    cout << "20181498 박선균" << endl;
    char *inputData = new char[8];
    char hamming[12];
    char xordata;

    cout << "해밍코드로 변환시킬 데이터를 입력하시오." << endl;
    cin >> inputData;
    cout << "입력된 데이터: " << inputData << endl;
    hamming[2] = inputData[0];
    hamming[4] = inputData[1];
    hamming[5] = inputData[2];
    hamming[6] = inputData[3];
    hamming[8] = inputData[4];
    hamming[9] = inputData[5];
    hamming[10] = inputData[6];
    hamming[11] = inputData[7];

    hamming[0] = hamming[2] ^ hamming[4] ^ hamming[6] ^ hamming[8] ^ hamming[10];
    hamming[1] = hamming[2] ^ hamming[5] ^ hamming[6] ^ hamming[9] ^ hamming[10];
    hamming[3] = hamming[4] ^ hamming[5] ^ hamming[6] ^ hamming[11] ^ '0';
    hamming[7] = hamming[8] ^ hamming[9] ^ hamming[10] ^ hamming[11] ^ '0';
    cout << "해밍코드: " << hamming << endl;

    delete[] inputData;
}