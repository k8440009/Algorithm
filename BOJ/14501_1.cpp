// 퇴사 1회차 : 90분
// https://www.acmicpc.net/problem/14501
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer;
vector <pair<int,int>> work;

void dfs(int curr, int prev, int total)
{
    total += work[prev].second;
    if(curr > N)
    {
        answer = max(answer, total);
        return ;
    }
    for(int next = curr + work[curr].first; next <= N + 1; next++)
        dfs(next, curr, total);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    answer = 0;
    cin >> N;
    work.resize(N + 1);
    for(int i = 1; i <= N; i++)
        cin >> work[i].first >> work[i].second;
    for(int i = 1; i <= N; i++)
        dfs(i, 0, 0);
    cout << answer << '\n';
}