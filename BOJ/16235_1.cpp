// 나무 재테크
// https://www.acmicpc.net/problem/16235
#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;
int N, M, K;

int board[MAX][MAX];
int add[MAX][MAX];
int dead[MAX][MAX];

vector<int> tree[MAX][MAX];

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void springSummer()
{
    // 나이만큼 양분을 먹는다 -> 나이가 증가
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!tree[i][j].empty())
            {
                sort(tree[i][j].begin(), tree[i][j].end());

                vector<int> temp;

                for (int index = 0; index < tree[i][j].size(); index++)
                {
                    if (tree[i][j][index] <= board[i][j])
                    {
                        board[i][j] -= tree[i][j][index];
                        temp.push_back(tree[i][j][index] + 1);
                    }
                    else
                    {
                        dead[i][j] += tree[i][j][index] / 2;
                    }
                }

                tree[i][j].clear();
                for (int k = 0; k < temp.size(); k++)
                {
                    tree[i][j].push_back(temp[k]);
                }
                // 여름
                board[i][j] += dead[i][j];
                dead[i][j] = 0;
            }
        }
    }
}
void fall()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!tree[i][j].empty())
            {
                for (int index = 0; index < tree[i][j].size(); index++)
                {
                    if (tree[i][j][index] % 5 == 0)
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
        int y, x, age;
        cin >> y >> x >> age;
        y -= 1;
        x -= 1;
        tree[y][x].push_back(age);
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
        {
            answer += tree[i][j].size();
        }
    }

    cout << answer << '\n';
}