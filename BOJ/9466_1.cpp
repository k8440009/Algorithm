// 텀 프로젝트 DFS, 사이클찾기
// https://www.acmicpc.net/problem/9466
#include <iostream>
using namespace std;
const int MAX = 100000 + 1;
int TC, N;
int people[MAX];
bool visited[MAX], finished[MAX];
// dfs 검색을 통해 사이클 발견 후, 팀 프로젝트 인원 반환
int dfs(int current)
{
    int cnt = 0;
    visited[current] = true;
    int next = people[current]; // 다음 노드
    // 이전에 방문 한 경우
    if (visited[next])
    {
        // 사이클이 가능한 경우 (사이클이 없었던 경우)
        if (!finished[next])
        {
            // 팀 프로젝트 인원을 찾는다.
            for (int node = next; node != current; node = people[node])
                cnt++;
            cnt++; // 자기자신도 사이클
        }
    }
    // 처음 방문하는 경우는 dfs 실행
    else
        cnt += dfs(next);
    finished[current] = true;
    return cnt;
}
void init()
{
    // 배열 초기화
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        people[i] = 0, visited[i] = 0, finished[i] = 0;
        cin >> people[i];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> TC;
    for (int i = 0; i < TC; i++)
    {
        init();
        int answer = 0;
        for (int i = 1; i <= N; i++)
            if (!visited[i])
                answer += dfs(i);
        cout << N - answer << '\n';
    }
    return 0;
}
/*
    참고
    https://kks227.blog.me/
*/