// 스타트 택시
// https://www.acmicpc.net/problem/19238
#include <iostream>
#include <queue>
using namespace std;

struct TAXI
{
	int r, c, f;
};

struct CUSTOMER
{
	int sr, sc, er, ec;
};

const int MAX = 20 + 1;
const int dr[] = { -1,1,0,0 };
const int dc[] = { 0,0,-1,1 };

int N, M, answer;
// 0 : 벽, 빈칸 1 : 승객 번호
int board[MAX][MAX][2];
bool visited[MAX][MAX];

TAXI taxi;
CUSTOMER customer[MAX * MAX];

void print_board()
{
	cout << '\n';
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cout << board[r][c][1] << ' ';
		}
		cout << '\n';
	}
}
bool solve()
{
	int visited[MAX][MAX];
	fill_n(visited[0], MAX * MAX, 0);
	int candi_r = N + 1;
	int candi_c = N + 1;
	int candi_num = -1;
	int candi_dist = MAX * MAX;

	// 손님 찾기
	if (board[taxi.r][taxi.c][1] == 0)
	{
		TAXI start;
		start.r = taxi.r;
		start.c = taxi.c;
		start.f = 0;
		queue <TAXI> q;
		q.push(start);
		visited[start.r][start.c] = 1;
		
		while (!q.empty())
		{
			TAXI cur = q.front();
			q.pop();

			if (cur.f > candi_dist)
				break;

			if (candi_r == N + 1)
			{
				if (board[cur.r][cur.c][1] > 0)
				{
					candi_r = cur.r;
					candi_c = cur.c;
					candi_num = board[cur.r][cur.c][1] - 1;
					candi_dist = cur.f;
					//cout << candi_r << ' ' << candi_c << ' ' << candi_num << '\n';
				}
			}
			else
			{
				if (board[cur.r][cur.c][1] > 0)
				{
					if (candi_dist == cur.f)
					{
						if (candi_r > cur.r)
						{
							candi_r = cur.r;
							candi_c = cur.c;
							candi_num = board[cur.r][cur.c][1] - 1;
							candi_dist = cur.f;
						}
						else if(candi_r == cur.r)
						{
							if (candi_c > cur.c)
							{
								candi_c = cur.c;
								candi_num = board[cur.r][cur.c][1] - 1;
								candi_dist = cur.f;
							}
						}
					}

				}
			}

			for (int dir = 0; dir < 4; dir++)
			{
				int nr = cur.r + dr[dir];
				int nc = cur.c + dc[dir];

				if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc][0] == 1 || visited[nr][nc])
					continue;

				TAXI next;
				next.r = nr;
				next.c = nc;
				next.f = cur.f + 1;
				q.push(next);
				visited[nr][nc] = 1;
			}
		}
	}
	else
	{
		candi_r = taxi.r;
		candi_c = taxi.c;
		candi_num = board[taxi.r][taxi.c][1] - 1;
		candi_dist = 0;
	}

	//cout << "before : " << taxi.r + 1 << ' ' << taxi.c + 1 << ' ' << candi_num << '\n';
	if (taxi.f - candi_dist <= 0)
		return false;

	// 손님 배달
	taxi.f -= candi_dist;
	taxi.r = candi_r;
	taxi.c = candi_c;
	board[taxi.r][taxi.c][1] = 0;
	//cout << "after : " << taxi.r + 1 << ' ' << taxi.c + 1 << ' ' << candi_num << '\n';

	fill_n(visited[0], MAX * MAX, 0);
	candi_r = customer[candi_num].er;
	candi_c = customer[candi_num].ec;

	queue <TAXI> q;
	
	TAXI st;
	st.r = taxi.r;
	st.c = taxi.c;
	st.f = 0;

	q.push(st);
	visited[st.r][st.c] = 1;

	while (!q.empty())
	{
		TAXI cur = q.front();
		q.pop();

		if (cur.f > taxi.f)
			break;

		if (cur.r == candi_r && cur.c == candi_c)
		{
			taxi.f += cur.f;
			taxi.r = candi_r;
			taxi.c = candi_c;

			//cout << "after : " << taxi.r + 1 << ' ' << taxi.c + 1 << ' ' << candi_num << '\n';
			// print_board();
			return true;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nr = cur.r + dr[dir];
			int nc = cur.c + dc[dir];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc][0] == 1 || visited[nr][nc])
				continue;

			TAXI next;
			next.r = nr;
			next.c = nc;
			next.f = cur.f + 1;
			q.push(next);
			visited[nr][nc] = 1;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> taxi.f;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c][0];
		}
	}
	cin >> taxi.r >> taxi.c;
	--taxi.r;
	--taxi.c;
	for (int i = 0; i < M; i++) 
	{
		cin >> customer[i].sr >> customer[i].sc >> customer[i].er >> customer[i].ec;
		--customer[i].sr, --customer[i].sc, --customer[i].er, --customer[i].ec;
		board[customer[i].sr][customer[i].sc][1] = i + 1;
	}

	//print_board();
	
	int count = 0;
	while (true)
	{
		if (count != M && solve())
			++count;
		else
			break;
	}
	if (count != M)
		answer = -1;
	else
		answer = taxi.f;
	cout << answer;
	
}