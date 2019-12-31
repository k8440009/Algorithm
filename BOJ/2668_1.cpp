// 숫자고르기
// https://www.acmicpc.net/problem/2668
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100 + 1;
int N, numbers[MAX];
bool visited[MAX], finished[MAX];
vector<int> picked;
int dfs(int current)
{
    int cnt = 0;
    visited[current] = true;
    int next = numbers[current];
    if (visited[next])
    {
        if (!finished[next])
        {
            for (int node = next; node != current; node = numbers[node])
            {
                picked.push_back(node);
                cnt++;
            }
            cnt++;
            picked.push_back(current);
        }
    }
    else
        cnt += dfs(next);
    finished[current] = true;
    return cnt;
}
void init()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> numbers[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int answer = 0;
    for (int i = 1; i <= N; i++)
        if (!visited[i])
            answer += dfs(i);
    cout << answer << '\n';
    sort(picked.begin(), picked.end());
    vector<int>::iterator iter;
    for (iter = picked.begin(); iter != picked.end(); iter++)
        cout << *iter << '\n';
    return 0;
}
/*
    참고
    9466 텀 프로젝트 (DFS, 사이클 찾기)
*/