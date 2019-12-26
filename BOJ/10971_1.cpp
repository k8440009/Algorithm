// 외판원 순회 2
// https://www.acmicpc.net/problem/10971
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10 + 1, INF = 987654321;
int N, dist[MAX][MAX], answer = INF;
int shortestPath(vector<int> &path, vector<bool> &visited, int currentLength)
{
    // 기저 : 모든 도시를 방문하고, 되돌아 온다.
    if (currentLength >= answer)
        return INF;
    if (path.size() == N)
        return currentLength + dist[path.back()][path[0]];
    int ret = INF;
    int here = path.back(); // 현재 위치
    // 모든 경우 실행
    for (int next = 0; next < N; next++)
    {
        if (visited[next]) // 이전에 방문했거나,  경로가 없는 경우
            continue;
        path.push_back(next);
        visited[next] = true;
        int cand = min(ret, shortestPath(path, visited, currentLength + dist[here][next]));
        ret = min(ret, cand);
        path.pop_back();
        visited[next] = false;
    }
    return ret;
}
void init()
{
    cin >> N;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
        {
            cin >> dist[y][x];
            if (dist[y][x] == 0) // 0 인 경우 길이 존재하지 않기 때문에 INF로 바꿔준다.
                dist[y][x] = INF;
        }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    vector<int> path;        // 경로
    vector<bool> visited(N); // 방문 여부

    for (int i = 0; i < N; i++)
    {
        path.push_back(i);
        visited[i] = true;
        answer = min(answer, shortestPath(path, visited, 0));
        path.pop_back();
        visited[i] = false;
    }
    cout << answer;
    return 0;
}