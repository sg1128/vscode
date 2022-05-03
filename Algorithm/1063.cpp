#include <iostream>
#include <string>
using namespace std;

char kingc;
char stonec;
int kingr;
int stoner;

int main()
{
    int move;
    cin >> kingc >> kingr;
    cin >> stonec >> stoner;
    cin >> move;
    string input;

    for (int i = 0; i < move; i++)
    {
        cin >> input;
        if (input.compare("R") == 0)
        {
            kingc = kingc + 1;
            //만약 킹의 위치랑 돌의 위치가 같으면
            if (kingc == stonec && kingr == stoner)
            {
                stonec = stonec + 1;
                // 돌이 체스판을 나가면
                if (stonec > 'H')
                {
                    //원상복귀
                    kingc = kingc - 1;
                    stonec = stonec - 1;
                }
            }
            if (kingc > 'H')
                kingc = kingc - 1;
        }
        else if (input.compare("L") == 0)
        {
            kingc = kingc - 1;

            if (kingc == stonec && kingr == stoner)
            {
                stonec = stonec - 1;
                if (stonec < 'A')
                {
                    kingc = kingc + 1;
                    stonec = stonec + 1;
                }
            }
            if (kingc < 'A')
                kingc = kingc + 1;
        }
        else if (input.compare("B") == 0)
        {
            kingr = kingr - 1;

            if (kingc == stonec && kingr == stoner)
            {
                stoner = stoner - 1;
                if (stoner < 1)
                {
                    kingr = kingr + 1;
                    stoner = stoner + 1;
                }
            }
            if (kingr < 1)
                kingr = kingr + 1;
        }
        else if (input.compare("T") == 0)
        {
            kingr = kingr + 1;

            if (kingc == stonec && kingr == stoner)
            {
                stoner = stoner + 1;
                if (stoner > 8)
                {
                    kingr = kingr - 1;
                    stoner = stoner - 1;
                }
            }
            if (kingr > 8)
                kingr = kingr - 1;
        }
        else if (input.compare("RT") == 0)
        {
            kingc = kingc + 1;
            kingr = kingr + 1;

            if (kingc == stonec && kingr == stoner)
            {
                stonec = stonec + 1;
                stoner = stoner + 1;
                if (stonec > 'H' || stoner > 8)
                {
                    kingc = kingc - 1;
                    kingr = kingr - 1;
                    stonec = stonec - 1;
                    stoner = stoner - 1;
                }
            }
            if (kingc > 'H' || kingr > 8)
            {
                kingc = kingc - 1;
                kingr = kingr - 1;
            }
        }
        else if (input.compare("LT") == 0)
        {
            kingc = kingc - 1;
            kingr = kingr + 1;
            if (kingc == stonec && kingr == stoner)
            {
                stonec = stonec - 1;
                stoner = stoner + 1;
                if (stonec < 'A' || stoner > 8)
                {
                    kingc = kingc + 1;
                    kingr = kingr - 1;
                    stonec = stonec + 1;
                    stoner = stoner - 1;
                }
            }
            if (kingc < 'A' || kingr > 8)
            {
                kingc = kingc + 1;
                kingr = kingr - 1;
            }
        }
        else if (input.compare("RB") == 0)
        {
            kingc = kingc + 1;
            kingr = kingr - 1;
            if (kingc == stonec && kingr == stoner)
            {
                stonec = stonec + 1;
                stoner = stoner - 1;
                if (stonec > 'H' || stoner < 1)
                {
                    kingc = kingc - 1;
                    kingr = kingr + 1;
                    stonec = stonec - 1;
                    stoner = stoner + 1;
                }
            }
            if (kingc > 'H' || kingr < 1)
            {
                kingc = kingc - 1;
                kingr = kingr + 1;
            }
        }
        else if (input.compare("LB") == 0)
        {
            kingc = kingc - 1;
            kingr = kingr - 1;
            if (kingc == stonec && kingr == stoner)
            {
                stonec = stonec - 1;
                stoner = stoner - 1;
                if (stonec < 'A' || stoner < 1)
                {
                    kingc = kingc + 1;
                    kingr = kingr + 1;
                    stonec = stonec + 1;
                    stoner = stoner + 1;
                }
            }
            if (kingc < 'A' || kingr < 1)
            {
                kingc = kingc + 1;
                kingr = kingr + 1;
            }
        }
    }
    cout << kingc << kingr << endl
         << stonec << stoner << endl;
    return 0;
}