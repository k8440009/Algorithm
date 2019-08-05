// 풍선 터뜨리기
// https://www.acmicpc.net/problem/2346
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    list<int> lt;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        lt.push_back(temp);
    }

    // 1번
    int start = lt.front();
    vector<int> answer;
    answer.push_back(start + 1);

    return 0;
}