// 어른 상어
// https://www.acmicpc.net/problem/19237
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 20 + 2;
const int dr[] = { 0,-1,1,0,0 };
const int dc[] = { 0,0,0,-1,1 };

struct SMELL
{
	int num, time;
};

struct SHARK
{
	int r, c, d;
};

int N, M, K;

vector <SMELL> sm[MAX][MAX]; // 냄새 정보
vector <SHARK> shk;	// 상어 정보
int board[MAX][MAX]; // 상어 위치 정보
int priority[MAX * MAX][5][5];	// 우선 순위

void print_sm()
{
	cout << '\n';
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (!sm[r][c].empty())
			{
				cout << sm[r][c][0].time << ' ';
			}
			else
				cout << 0 << ' ';
		}
		cout << '\n';
	}
}

void print_board(int desc[MAX][MAX])
{
	cout << '\n';
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			cout << desc[r][c] << ' ';
		}
		cout << '\n';
	}
}
void move()
{
	int next[MAX][MAX];
	fill_n(next[0], MAX * MAX, 0);

	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (board[r][c] != 0)
			{
				int flag = false;
				int idx = board[r][c];

				for (int cnt = 1; cnt <= 4; cnt++)
				{
					int dir = priority[idx][shk[idx].d][cnt];
					int nr = r + dr[dir], nc = c + dc[dir];

					if (nr < 1 || nr > N || nc < 1 || nc > N)
						continue;
					if (sm[nr][nc].empty())
					{
						shk[idx].r = nr, shk[idx].c = nc, shk[idx].d = dir;
						if (next[nr][nc] == 0)
							next[nr][nc] = idx;
						else if (next[nr][nc] > idx)
							next[nr][nc] = idx;
						board[r][c] = 0;
						flag = true;
						break;
					}
				}
				// 빈칸이 없는 경우
				if (!flag)
				{
					for (int cnt = 1; cnt <= 4; cnt++)
					{
						int dir = priority[idx][shk[idx].d][cnt];
						int nr = r + dr[dir], nc = c + dc[dir];

						if (nr < 1 || nr > N || nc < 1 || nc > N)
							continue;
						if (!sm[nr][nc].empty() && sm[nr][nc][0].num == idx)
						{
							shk[idx].r = nr, shk[idx].c = nc, shk[idx].d = dir;
							next[nr][nc] = idx;
							board[r][c] = 0;
							break;
						}
					}
				}
			}
		}
	}

	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			board[r][c] = next[r][c];
}

void delete_smell()
{
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (!sm[r][c].empty())
			{
				sm[r][c][0].time -= 1;
				if (sm[r][c][0].time ==0)
					sm[r][c].pop_back();
			}
		}
	}
}

void spread_smell()
{
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (board[r][c] != 0)
			{
				if (sm[r][c].empty())
				{
					SMELL tmp;
					tmp.num = board[r][c], tmp.time = K;
					sm[r][c].push_back(tmp);
				}
				else
				{
					sm[r][c].pop_back();
					SMELL tmp;
					tmp.num = board[r][c], tmp.time = K;
					sm[r][c].push_back(tmp);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	shk.resize(M + 1);
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			cin >> board[r][c];
			if (board[r][c] > 0)
				shk[board[r][c]].r = r, shk[board[r][c]].c = c;
		}
	}

	for (int i = 1; i <= M; i++)
		cin >> shk[i].d;
	for (int i = 1; i <= M; i++)
		for (int r = 1; r <= 4; r++)
			for (int c = 1; c <= 4; c++)
				cin >> priority[i][r][c];
	
	int time = 1;
	while (time <= 1000)
	{
		spread_smell();
		move();
		delete_smell();

		//cout << time;
		//print_board(board);
		//print_sm();
		int cnt = 0;
		for (int r = 1; r <= N; r++)
			for (int c = 1; c <= N; c++)
				if (board[r][c] > 0)
					cnt++;
		if (cnt == 1)
			break;
		time++;
	}
	if (time == 1001)
		time = -1;
	cout << time;
}