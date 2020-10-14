// 스타트 택시
// https://www.acmicpc.net/problem/19238
#include <iostream>
#include <queue>
using namespace std;

struct CUSTOMER
{
	int start, end;
};

struct TAXI
{
	int pos, dist;
};

const int MAX = 20 + 2;
const int WALL = -1;
const int EMPTY = -2;
const int dr[4] = { -1, 0, +1, 0 };
const int dc[4] = { 0, -1, 0, +1 };

int N, M, fuel;
int taxi_r, taxi_c;
int board[MAX][MAX];
CUSTOMER customer[MAX * MAX];

bool move_customer(int target)
{

	queue <TAXI> q;
	bool visited[MAX][MAX];

	fill_n(visited[0], MAX * MAX, 0);

	TAXI cur;
	cur.pos = taxi_r * 100 + taxi_c, cur.dist = 0;
	q.push(cur);
	visited[taxi_r][taxi_c] = true;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		if (cur.dist > fuel)
			return false;

		if (cur.pos == customer[target].end)
		{
			taxi_r = customer[target].end / 100;
			taxi_c = customer[target].end % 100;
			fuel += cur.dist;
			return true;
		}

		int r = cur.pos / 100;
		int c = cur.pos % 100;
		for (int d = 0; d < 4; d++)
		{
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == WALL || visited[nr][nc] == true)
				continue;
			TAXI next;
			next.pos = nr * 100 + nc;
			next.dist = cur.dist + 1;
			q.push(next);
			visited[nr][nc] = 1;
		}
	}
	return false;
}

int find_customer()
{
	queue <TAXI> q;
	bool visited[MAX][MAX];
	int candi[MAX * MAX];

	fill_n(visited[0], MAX * MAX, 0);
	fill_n(candi, MAX * MAX, 0);

	TAXI cur;
	cur.pos = taxi_r * 100 + taxi_c, cur.dist = 0;
	q.push(cur);
	visited[taxi_r][taxi_c] = true;

	int candi_size = 0;
	int candi_dist = -1;

	while (!q.empty())
	{
		cur = q.front();
		q.pop();

		if (candi_dist != -1 && cur.dist > candi_dist)
			break;

		int r = cur.pos / 100;
		int c = cur.pos % 100;
		if (board[r][c] >= 0)
		{
			candi[candi_size++] = board[r][c];
			candi_dist = cur.dist;
		}

		for (int d = 0; d < 4; d++)
		{
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == WALL || visited[nr][nc] == true)
				continue;
			TAXI next;
			next.pos = nr * 100 + nc, next.dist = cur.dist + 1;
			q.push(next);
			visited[nr][nc] = true;
		}
	}
	if (candi_dist > fuel)
		return -1;

	int ret = -1;
	int candi_val = 987654321;

	for (int i = 0; i < candi_size; i++)
	{
		if (candi_val > customer[candi[i]].start)
		{
			candi_val = customer[candi[i]].start;
			ret = candi[i];
		}
	}
	taxi_r = customer[ret].start / 100;
	taxi_c = customer[ret].start % 100;
	board[taxi_r][taxi_c] = EMPTY;
	fuel -= candi_dist;
	return ret;
}

int solve()
{
	int ret = -1;
	for (int i = 0; i < M; i++)
	{
		int target = find_customer();
		//cout << "i : " << i << ' ' << "fuel : " << fuel << '\n';
		if (target == -1)
			return ret;
		bool success = move_customer(target);
		//cout << "i : " << i << ' ' << "fuel : " << fuel << '\n';
		if (success == false)
			return ret;
	}
	ret = fuel;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> fuel;
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cin >> board[r][c];
			board[r][c] -= 2;
		}
	}
	cin >> taxi_r >> taxi_c;
	--taxi_r, --taxi_c;
	for (int i = 0; i < M; i++)
	{
		int sr, sc, er, ec;
		cin >> sr >> sc >> er >> ec;
		--sr, --sc, --er, --ec;
		customer[i].start = (sr * 100 + sc);
		customer[i].end = (er * 100 + ec);
		board[sr][sc] = i;
	}

	int answer = solve();
	cout << answer;
	return 0;
}
/*
**	참고자료
**	https://na982.tistory.com/129
*/