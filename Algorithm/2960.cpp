#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int count = 2;
    int h = 1, a = 1;
    int *array = new int[N];

    if (K >= 1 && K < N)
    {
        for (int i = 0; i < N; i++)
        {
            if (count * h > N)
            {
                count++;
                h = 1;
            }
            for (int j = 0; j < i; j++)
            {
                if (count * h == array[j])
                {
                    h++;
                    a = 0;
                }
            }

            if (count * h <= N && a == 1)
            {
                array[i] = count * h;
                h++;
            }
            if (a == 0)
            {
                i--;
            }
            a = 1;
        }
        cout << array[K - 1] << endl;
    }
    else
    {
        cout << "error!" << endl;
    }

    delete[] array;
}

/*
    어떤 수를 입력
    그 수보다 작은 숫자의 배열을 없앰
    시작은 무조건 2로 시작
    만약 2의 배수가 다 끝나면 3의 배수로 ㄱㄱ
    3의 배수가 끝나면 5의 배수 그다음 7의 배수 그다음 11의 배수

*/