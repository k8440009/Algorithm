// 원판 돌리기 - 3회 120분
// https://www.acmicpc.net/problem/17822
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 50 + 2;
const int dr[] = { 1,-1,0,0 };
const int dc[] = { 0,0,1,-1 };
struct INFO
{
	int x, d, k;
};

int N, M, T;
int board[MAX][MAX];

vector <INFO> rot;

void print_board(int desc[MAX][MAX])
{
	cout << '\n';
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= M; c++)
		{
			cout << desc[r][c] << ' ';
		}
		cout << '\n';
	}
}

void move(int index, int dir, int cnt)
{
	// 시계
	if (dir == 0)
	{
		while (cnt--)
		{
			int tmp = board[index][M];
			for (int c = M; c >= 2; c--)
				board[index][c] = board[index][c - 1];
			board[index][1] = tmp;
		}
	}
	// 반시계
	else
	{
		while (cnt--)
		{
			int tmp = board[index][1];
			for (int c = 1; c < M; c++)
				board[index][c] = board[index][c + 1];
			board[index][M] = tmp;
		}
	}
}

bool bfs(int s_r, int s_c)
{
	int visited[MAX][MAX];
	int basis = board[s_r][s_c];
	queue <pair <int, int>> q;
	vector <pair <int, int>> vec;

	fill_n(visited[0], MAX * MAX, 0);
	q.push(make_pair(s_r, s_c));
	vec.push_back(make_pair(s_r, s_c));
	visited[s_r][s_c] = 1;

	while (!q.empty())
	{
		pair <int, int> cur = q.front();
		q.pop();

		int nr, nc;
		for (int dir = 0; dir < 4; dir++)
		{
			nr = cur.first + dr[dir], nc = cur.second + dc[dir];
			// 방문 한 곳 처리
			if (nr < 1 || nr > N || visited[nr][nc])
				continue;
			if (nc < 1)
			{
				if (!visited[nr][M] && board[nr][M] == basis)
				{
					q.push(make_pair(nr, M));
					vec.push_back(make_pair(nr, M));
					visited[nr][M] = 1;
				}
			}
			else if (nc > M)
			{
				if (!visited[nr][1] && board[nr][1] == basis)
				{
					q.push(make_pair(nr, 1));
					vec.push_back(make_pair(nr, 1));
					visited[nr][1] = 1;
				}
			}
			else if (board[nr][nc] == basis)
			{
				q.push(make_pair(nr, nc));
				vec.push_back(make_pair(nr, nc));
				visited[nr][nc] = 1;
			}
		}
	}

	if (vec.size() != 1)
	{
		for (int i = 0; i < vec.size(); i++)
			board[vec[i].first][vec[i].second] = 0;
		return true;
	}
	return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= M; c++)
			cin >> board[r][c];

	for (int i = 0; i < T; i++)
	{
		INFO tmp;
		cin >> tmp.x >> tmp.d >> tmp.k;
		rot.push_back(tmp);
	}
	bool check = false;
	for (int i = 0; i < rot.size(); i++)
	{
		INFO info = rot[i];
		for (int st = info.x; st <= N; st += info.x)
			move(st, info.d, info.k);
		// 시뮬
		for (int r = 1; r <= N; r++)
		{
			for (int c = 1; c <= M; c++)
			{
				if (board[r][c] > 0)
				{
					bool flag = bfs(r, c);
					if (check == false && flag == true)
						check = true;
				}
			}
		}
		if (!check)
		{
			int total = 0, cnt = 0;
			for (int r = 1; r <= N; r++)
				for (int c = 1; c <= M; c++)
				{
					if (board[r][c] > 0)
					{
						total += board[r][c];
						cnt++;
					}
				}

			if (cnt > 0)
			{
				double avg = (double)total / cnt;
				for (int r = 1; r <= N; r++)
				{
					for (int c = 1; c <= M; c++)
					{
						if (board[r][c] == 0)
							continue;

						if (board[r][c] > avg)
							board[r][c] -= 1;
						else if (board[r][c] < avg)
							board[r][c] += 1;
					}
				}
			}
		}
		check = false;
		// print_board(board);
	}
	int answer = 0;
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= M; c++)
		{
			if (board[r][c] > 0)
				answer += board[r][c];
		}
	}
	cout << answer;
}