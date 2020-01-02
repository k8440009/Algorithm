// 보물섬
// https://www.acmicpc.net/problem/2589
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 50;
const int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
char board[MAX][MAX];
bool visited[MAX][MAX];
int N, M; // 가로, 세로
struct Node
{
    int length, row, col;
};

int BFS(int row, int col)
{
    Node node;
    node.row = row, node.col = col, node.length = 0;
    queue<Node> q;
    q.push(node);
    visited[row][col] = true;

    int answer = 0;

    while (!q.empty())
    {
        Node cur = q.front();
        answer = max(answer, cur.length);
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nr = cur.row + dr[dir], nc = cur.col + dc[dir];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc])
                continue;
            if (board[nr][nc] == 'L')
            {
                Node next;
                next.row = nr, next.col = nc, next.length = cur.length + 1;
                q.push(next);
                visited[nr][nc] = true;
            }
        }
    }

    return answer;
}
void init()
{
    cin >> N >> M;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            cin >> board[r][c];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    int answer = 0;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            if (board[r][c] == 'L')
            {
                fill_n(visited[0], MAX * MAX, 0);
                answer = max(answer, BFS(r, c));
            }
        }
    }
    cout << answer;
    return 0;
}