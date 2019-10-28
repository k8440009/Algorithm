// 효율적인 해킹
// https://www.acmicpc.net/problem/1325
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10000 + 1;
int N, M, cnt; // 컴퓨터 번호, 연결 고리 갯수
vector<int> connect[MAX];
bool visited[MAX];
void dfs(int node)
{
    visited[node] = true;
    for (int i = 0; i < connect[node].size(); i++)
    {
        int next = connect[node][i];

        if (!visited[next])
        {
            cnt++;
            dfs(next);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        connect[b].push_back(a);
    }

    // node, start, cnt
    int nodeCnt = 0;
    vector<int> answer;
    for (int node = 1; node <= N; node++)
    {
        fill_n(visited, MAX, 0);
        cnt = 0;

        dfs(node);

        if (nodeCnt == cnt)
            answer.push_back(node);
        if (nodeCnt < cnt)
        {
            nodeCnt = cnt;
            answer.clear();
            answer.push_back(node);
        }
    }

    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    cout << '\n';
    return 0;
}
/*
    참고
    https://mygumi.tistory.com/337
    https://jaimemin.tistory.com/656
*/