// 게리맨더링
// https://www.acmicpc.net/problem/17471
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10 + 1;
const int INF = 987654321;
int N, answer = INF;
vector<int> graph[MAX];
vector<int> people;
vector<int> region1, region2;
bool visited[MAX];
// 방문 할 수 있는지 체크
bool check2()
{
    bool checkNode[MAX];
    fill_n(checkNode, MAX, 0);

    queue<int> q;
    q.push(region2[0]);
    checkNode[region2[0]] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < graph[curr].size(); i++)
        {
            bool flag = true;
            // 다음 목적지
            int next = graph[curr][i];
            for (int j = 0; j < region1.size(); j++)
            {
                if (region1[j] == next)
                {
                    flag = false;
                    break;
                }
            }
            // 체크 되어있으면
            if (checkNode[next] || !flag)
                continue;
            else
            {
                q.push(next);
                checkNode[next] = true;
            }
        }
    }

    for (int i = 0; i < region2.size(); i++)
    {
        int curr = region2[i];
        if (!checkNode[curr])
            return false;
    }
    return true;
}

// 방문 할 수 있는지 체크
bool check1()
{
    bool checkNode[MAX];
    fill_n(checkNode, MAX, 0);

    queue<int> q;
    q.push(region1[0]);
    checkNode[region1[0]] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < graph[curr].size(); i++)
        {
            bool flag = true;
            // 다음 목적지
            int next = graph[curr][i];
            for (int j = 0; j < region2.size(); j++)
            {
                if (region2[j] == next)
                {
                    flag = false;
                    break;
                }
            }
            // 체크 되어있으면
            if (checkNode[next] || !flag)
                continue;
            else
            {
                q.push(next);
                checkNode[next] = true;
            }
        }
    }

    for (int i = 0; i < region1.size(); i++)
    {
        int curr = region1[i];
        if (!checkNode[curr])
            return false;
    }
    return true;
}
// 방문 할 수 있는지 체크
void dfs(int cur, int cnt)
{
    // 종료
    if (cur == N + 1)
    {
        int a = 0, b = 0;

        for (int i = 1; i <= N; i++)
        {
            if (visited[i])
            {
                region1.push_back(i);
                a += people[i];
            }
            else
            {
                region2.push_back(i);
                b += people[i];
            }
        }

        if (region1.empty() || region2.empty())
            return;
        // 방문 할 수 있는지 체크
        if (check1() && check2())
            answer = min(answer, abs(a - b));

        region1.clear();
        region2.clear();
        return;
    }

    visited[cur] = true;
    dfs(cur + 1, cnt + 1);
    visited[cur] = false;
    dfs(cur + 1, cnt);
}
void init()
{
    cin >> N;
    people.resize(N + 1);
    // 인구 저장
    for (int i = 1; i <= N; i++)
        cin >> people[i];
    // 노드 저장
    for (int i = 1; i <= N; i++)
    {
        int cnt;
        cin >> cnt;
        while (cnt--)
        {
            int node;
            cin >> node;
            graph[i].push_back(node);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    // 선거구 나누기
    dfs(1, 0); // index, 갯수
    if (answer == INF)
        cout << -1;
    else
        cout << answer;
    return 0;
}