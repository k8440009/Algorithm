// 물통
// https://www.acmicpc.net/problem/2251
#include <bits/stdc++.h>
using namespace std;

int bucketSize[3];      // 버킷 크기
int bucket[3];          // 물의 양
bool checked[201][201]; // a,b 물이 있는 경우 true
bool answer[201];
int main()
{
    for (int i = 0; i < 3; i++)
        cin >> bucketSize[i];

    int sum = bucketSize[2];
    queue<pair<int, int>> q;
    q.push({0, 0});
    checked[0][0] = true;
    answer[sum] = true;
    while (!q.empty())
    {
        int now[3];
        now[0] = q.front().first;
        now[1] = q.front().second;
        now[2] = sum - now[0] - now[1];
        q.pop();
    }

    return 0;
}