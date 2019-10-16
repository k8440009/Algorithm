// 아기 상어
// https://www.acmicpc.net/problem/16236
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 20;

struct fish
{
    int r, c; // 행 렬
    int size;
    int eat;
    int time;
};

int n;
int board[MAX][MAX];
int visited[MAX][MAX];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

queue<fish> q;
vector<fish> v;

bool cmp(fish a, fish b)
{
    // 가장 짧은 시간
    if (a.time <= b.time)
    {
        // 시간이 같은 경우
        if (a.time == b.time)
        {
            // 행값이 더 작은 순서
            if (a.r <= b.r)
            {
                // 행값이 같은 경우
                if (a.r == b.r)
                {
                    // x값이 작은 순서로 정렬
                    if (a.c < b.c)
                    {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    fish shark;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                board[i][j] = 0;
                // 행,렬,크기,먹은 갯수, 시간
                shark = {i, j, 2, 0, 0};
            }
        }
    }

    int answer = 0;
    while (true)
    {
        v.clear();
        fill_n(visited[0], MAX * MAX, 0);
        visited[shark.r][shark.c] = 1;
        q.push(shark);

        while (!q.empty())
        {
            int r = q.front().r;
            int c = q.front().c;
            int size = q.front().size;
            int eat = q.front().eat;
            int time = q.front().time;
            q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                // 범위 초과
                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;
                // 방문 한 경우
                if (visited[nr][nc])
                    continue;
                // 사이즈 같은 상어이거나, 길인 경우
                if (board[nr][nc] == 0 || board[nr][nc] == size)
                {
                    visited[nr][nc] = 1;
                    // 시간 추가, 작은 물고기를 찾는다.
                    q.push({nr, nc, size, eat, time + 1});
                }
                // 아기 상어보다 작은 경우
                else if (board[nr][nc] < size)
                {
                    visited[nr][nc] = 1;
                    // 잡아 먹고 벡터에 따로 저장
                    v.push_back({nr, nc, size, eat + 1, time + 1});
                }
            }
        }
        // 벡터가 비어 있다면 잡아 먹을 수 있는 상어 없음
        if (v.size() == 0)
            break;
        // cmp 조건에 맞추어 정렬
        sort(v.begin(), v.end(), cmp);
        // 먹은 상어의 숫자가 현재 사이즈와 같은 경우
        if (v[0].size == v[0].eat)
        {
            v[0].size += 1;
            v[0].eat = 0;
        }
        // 잡아 먹은 물고기 삭제
        board[v[0].r][v[0].c] = 0;
        // 움직인 시간 저장
        answer += v[0].time;
        // 시간을 초기화 하고, 다시 큐에 이전 과정을 반복
        shark = {v[0].r, v[0].c, v[0].size, v[0].eat, 0};
    }
    cout << answer;
    cout << '\n';
}