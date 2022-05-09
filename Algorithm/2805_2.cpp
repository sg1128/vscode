#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> treeH;

int main()
{

    int tH;

    cin >> N >> M;
    for (int k = 0; k < N; k++)
    {
        cin >> tH;
        treeH.push_back(tH);
    }
    int start =0;
    //최댓값 구하기
    int end = *max_element(treeH.begin(), treeH.end());
    int res=0;


    while (start<=end)
    {
        long int total =0;
        int mid = (start + end) /2;
        for(int i=0; i<N; i++)
        {
            //만약 나무의 길이가 mid보다 크면 total에 mid를 뺀값을 더함
            if(treeH[i]>mid)
                total += treeH[i] -mid;
        }
        // 만약 토탈이 M보다 작으면 최댓값을 줄인다.
        if(total < M){
            end = mid-1;
        }else //그게 아니면 최솟값을 올린다.
        {
            res=mid;
            start = mid+1;
        }
    }
    cout << res << endl;
}