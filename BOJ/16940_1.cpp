// BFS 스페셜 저지
// https://www.acmicpc.net/problem/16940
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 100000 + 2;
int N, index = 1;
bool visted[MAX];
vector<int> graph[MAX];
vector<int> location;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    // 그래프
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // BFS 노드 삽입
    for (int i = 0; i < N; i++)
    {
        int node;
        cin >> node;
        location.push_back(node);
    }
    // 시작 노드가 1이 아니면 종료
    if (location[0] != 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    // BFS
    queue<int> q;
    q.push(1);
    visted[1] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        set<int> s;
        // 노드를 돌면서 방문하지 않았다면 체크, SET에 넣는다
        for (int next : graph[now])
        {
            if (!visted[next])
            {
                s.insert(next);
                visted[next] = true;
            }
        }
        // index에서 set크기만큼 탐색
        for (int i = index; i < index + s.size(); i++)
        {
            // set에 bfs 연결 과정이 없는 경우
            if (s.count(location[i]) == 0)
            {
                cout << 0 << '\n';
                return 0;
            }
            // 있으면 bfs 실행
            else
            {
                q.push(location[i]);
            }
        }

        index += s.size();
    }

    cout << 1 << '\n';
    return 0;
}

/*
    참고
    https://developmoments.tistory.com/17
    https://bcp0109.tistory.com/85
*/
