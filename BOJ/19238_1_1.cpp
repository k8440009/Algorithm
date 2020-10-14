// 스타트 택시 1회차 : 1시간
// https://www.acmicpc.net/problem/19238
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 20 + 2;
const int dr[] = { 1,-1,0,0 };
const int dc[] = { 0,0,1,-1 };

struct CAR
{
	int r, c, f;
};

struct POS
{
	int r, c;
};

int N, M, fuel, answer;


int board[MAX][MAX];
int cus_board[MAX][MAX];
POS custom[MAX * MAX];
CAR taxi;

bool solve()
{
	bool visited[MAX][MAX];
	fill_n(visited[0], MAX * MAX, 0);

	CAR start;
	start.r = taxi.r, start.c = taxi.c, start.f = 0;

	int target_num = 0;
	CAR target;
	queue <CAR> q;
	target.r = N + 1, target.c = N + 1, target.f = N * N;

	// 손님 == 택시
	if (cus_board[start.r][start.c] > 0)
	{
		target_num = cus_board[start.r][start.c];
		cus_board[start.r][start.c] = 0;
		target.r = start.r, target.c = start.c, target.f = 0;
	}
	else
	{
		target.r = N + 1, target.c = N + 1, target.f = N * N;
		q.push(start);
		visited[start.r][start.c] = 1;
	}

	// 사람 찾기
	while (!q.empty())
	{
		CAR cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.r + dr[dir];
			int nc = cur.c + dc[dir];
			int nf = cur.f + 1;

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 1 || visited[nr][nc])
				continue;
			// 손님
			if (cus_board[nr][nc] > 0)
			{
				if (target.r == N + 1)
				{
					target_num = cus_board[nr][nc];
					target.r = nr;
					target.c = nc;
					target.f = nf;
				}
				else
				{
					if (target.f == nf)
					{
						if (target.r > nr)
						{
							target_num = cus_board[nr][nc];
							target.r = nr;
							target.c = nc;
							target.f = nf;
						}
						else if (target.r == nr)
						{
							if (target.c > nc)
							{
								target_num = cus_board[nr][nc];
								target.c = nc;
							}
						}
					}
				}
			}
			else
			{
				//cout << nr << ' ' << nc << '\n';
				CAR next;
				next.r = nr;
				next.c = nc;
				next.f = nf;
				q.push(next);
				visited[nr][nc] = 1;
			}
		}
	}

	//cout << "before taxi : " << taxi.f + 1 << ' ' << target.f + 1 << '\n';
	//cout << "target. r : " << target.r + 1 << ' ' << "target. c : " << target.c + 1 << '\n';
	if (target.r == N + 1 || taxi.f - target.f <= 0)
		return false;

	cus_board[target.r][target.c] = 0;
	taxi.r = target.r;
	taxi.c = target.c;
	taxi.f -= target.f;
	// 목적지 이동
	fill_n(visited[0], MAX * MAX, 0);

	start.r = taxi.r, start.c = taxi.c, start.f = 0;

	int end_r = custom[target_num].r;
	int end_c = custom[target_num].c;
	int end_f = 0;

	q.push(start);
	visited[start.r][start.c] = 1;
	while (!q.empty())
	{
		CAR cur = q.front();
		q.pop();

		if (cur.r == end_r && cur.c == end_c)
		{
			end_f = cur.f;
			break;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.r + dr[dir];
			int nc = cur.c + dc[dir];
			int nf = cur.f + 1;

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 1 || visited[nr][nc])
				continue;

			CAR next;
			next.r = nr;
			next.c = nc;
			next.f = nf;
			q.push(next);
			visited[nr][nc] = 1;
		}
	}

	if (end_f == 0 || taxi.f - end_f < 0)
		return false;

	taxi.r = end_r;
	taxi.c = end_c;
	taxi.f += end_f;

	//cout << "after taxi : " << taxi.f + 1 << ' ' << target.f + 1 << '\n';
	//cout << "target. r : " << target.r + 1 << ' ' << "target. c : " << target.c + 1 << '\n';
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> taxi.f;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			cin >> board[r][c];
	cin >> taxi.r >> taxi.c;
	taxi.r -= 1, taxi.c -= 1;
	for (int i = 1; i <= M; i++)
	{
		int s_r, s_c;
		cin >> s_r >> s_c >> custom[i].r >> custom[i].c;
		cus_board[s_r - 1][s_c - 1] = i;
		custom[i].r -= 1, custom[i].c -= 1;
	}

	int drive_customer = 0;
	
	while (true)
	{
		if (!solve())
			break;
		++drive_customer;

		if (drive_customer == M)
			break;
	}
	if (drive_customer != M)
		taxi.f = -1;
	cout << taxi.f;
}