#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<vector<int>> score;
int n;
int cnt;

int sticker_delete(int x, int y)
{
    score[x][y] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int a = dx[i] + x;
        int b = dy[i] + y;
        if (a >= 0 && b >= 0 && a < 2 && b < n)
        {
            score[a][b] = 1;
        }
    }
    return cnt;
}

int main()
{
    int T;
    int check;
    cin >> T;

    for (int i = 0; i<T; i++)
    {
        vector<vector<int>> sticker;
        cin >> n;

        for (int i = 0; i < 2; i++)
        {
            int point;
            sticker.push_back(vector<int>());
            for (int j = 0; j < n; j++)
            {
                cin >> point;
                sticker.at(i).push_back(point);
            }
        }
        // 연산부분
       // for (int k = 0; k < 2 * n; k++){
            check = 0;
            for (int i = 0; i < 2; i++)
            {
                score.push_back(vector<int>());
                for (int j = 0; j < n; j++)
                    score.at(i).push_back(0);
            }

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(score[i][j] == 0)
                    {
                        sticker_delete(i, j);
                        cnt += sticker[i][j];
                         for (int i = 0; i < 2; i++){
                            for (int j = 0; j < n; j++)
                                cout << score[i][j] << " ";
                        cout << endl;
                        }
                    }
                }
            }
            check = max(check, cnt);
            cnt = 0;
        }
        cout << check << endl;
    //}
}