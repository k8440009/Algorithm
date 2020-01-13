// 게임 개발
// https://www.acmicpc.net/problem/1516
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 500 + 1;
int N, indegree[MAX], result[MAX], time[MAX];
vector<int> adj[MAX];
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> time[i];
        while (1)
        {
            int prev;
            cin >> prev;
            if (prev == -1)
                break;
            indegree[i]++;
            adj[prev].push_back(i);
        }
    }
    queue<int> q;
    // 위상 정렬 시작하기전에 indegree가 0인것 삽입
    for (int i = 1; i <= N; i++)
        if (indegree[i] == 0)
        {
            result[i] = time[i];
            q.push(i);
        }
    // 위상정렬
    for (int i = 1; i <= N; i++)
    {
        // 큐에 값이 없으면 종료
        if (q.empty())
        {
            exit(0);
        }

        int curr = q.front();
        q.pop();
        for (int next : adj[curr])
        {
            result[next] = max(result[next], result[curr] + time[next]);
            if (--indegree[next] == 0)
                q.push(next);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}

/*
	참고
	http://blog.naver.com/kks227/220800013823
*/