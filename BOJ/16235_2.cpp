#include <bits/stdc++.h>
using namespace std;
struct TREE
{
    int y, x, age;
};
const int MAX = 10;
int N, M, K;
vector<int> tree[MAX][MAX];
int board[MAX][MAX];
int add[MAX][MAX];
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
// 봄 여름
void springSummer()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!tree[i][j].empty())
            {
                int dead = 0;
                // 1. 어린 아이부터
                vector<int> temp;
                sort(tree[i][j].begin(), tree[i][j].end());
                for (int k = 0; k < tree[i][j].size(); k++)
                {
                    if (board[i][j] >= tree[i][j][k])
                    {
                        board[i][j] -= tree[i][j][k];
                        temp.push_back(tree[i][j][k] + 1);
                    }
                    else
                    {
                        dead += tree[i][j][k] / 2;
                    }
                }
                // 나무 배열 비워주고
                tree[i][j].clear();
                // 살아남은 나무로 채워준다.
                for (int k = 0; k < temp.size(); k++)
                {
                    tree[i][j].push_back(temp[k]);
                }

                board[i][j] += dead;
            }
        }
    }
}
// 번식
void fall()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!tree[i][j].empty())
            {
                for (int k = 0; k < tree[i][j].size(); k++)
                {
                    if (tree[i][j][k] % 5 == 0)
                    {
                        for (int dir = 0; dir < 8; dir++)
                        {
                            int ny = i + dy[dir];
                            int nx = j + dx[dir];

                            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                                continue;

                            tree[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
    }
}
// 양분 넣어줌
void winter()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] += add[i][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // N, 나무갯수, 시간
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> add[i][j];
            board[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++)
    {
        TREE t;
        cin >> t.y >> t.x >> t.age;
        t.y -= 1;
        t.x -= 1;
        tree[t.y][t.x].push_back(t.age);
    }

    for (int i = 0; i < K; i++)
    {
        springSummer();
        fall();
        winter();
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            answer += tree[i][j].size();
    }

    cout << answer << '\n';

    return 0;
}