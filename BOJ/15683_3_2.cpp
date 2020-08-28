// 감시
// https://www.acmicpc.net/problem/15683
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 8 + 1;
const int INF = 987654321;

struct CCTV
{
	int r, c, type;
};

int N,M, answer = INF;
int	board[MAX][MAX];
int visited[MAX][MAX];
vector <CCTV> cctv;

vector <int> cctv_rot = {4,2,4,4,1};

void map_copy(int desc[MAX][MAX], int src[MAX][MAX])
{
	for (int r = 0; r < N; r++)
		for(int c = 0; c < M; c++)
			desc[r][c] = src[r][c];
}

void update(int dir, CCTV cctv)
{
	dir = (dir % 4);
	if (dir == 0)
	{	
		for (int c = cctv.c + 1; c < M; c++)
		{
			if (board[cctv.r][c] == 6)
				break;
			board[cctv.r][c] = -1;
		}
	}
	if (dir == 1)
	{
		for (int r = cctv.r - 1; r >= 0; r--)
		{
			if (board[r][cctv.c] == 6)
				break;
			board[r][cctv.c] = -1;
		}
	}
	if (dir == 2)
	{
		for (int c = cctv.c - 1; c >= 0; c--)
		{
			if (board[cctv.r][c] == 6)
				break;
			board[cctv.r][c] = -1;
		}
	}
	if (dir == 3)
	{
		for (int r = cctv.r + 1; r < N; r++)
		{
			if (board[r][cctv.c] == 6)
				break;
			board[r][cctv.c] = -1;
		}
	}
}

void dfs(int cctv_idx)
{
	if (cctv_idx == cctv.size())
	{
		int candi = 0;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < M; c++)
				if (board[r][c] == 0)
					candi++;
		answer = min(answer, candi);
		return ;
	}

	int back_up[MAX][MAX];
	int type = cctv[cctv_idx].type;
	for (int dir = 0; dir < cctv_rot[type]; dir++)
	{
		map_copy(back_up, board);
		if (type == 0)
		{
			update(dir, cctv[cctv_idx]);
		}
		else if (type == 1)
		{
			update(dir, cctv[cctv_idx]);
			update(dir + 2, cctv[cctv_idx]);
		}
		else if (type == 2)
		{
			update(dir, cctv[cctv_idx]);
			update(dir + 1, cctv[cctv_idx]);
		}
		else if (type == 3)
		{
			update(dir, cctv[cctv_idx]);
			update(dir + 1, cctv[cctv_idx]);
			update(dir + 2, cctv[cctv_idx]);
		}
		else if (type == 4)
		{
			update(dir, cctv[cctv_idx]);
			update(dir + 1, cctv[cctv_idx]);
			update(dir + 2, cctv[cctv_idx]);
			update(dir + 3, cctv[cctv_idx]);
		}
		dfs(cctv_idx + 1);
		map_copy(board, back_up);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int r = 0; r < N; r++)
	{
		for(int c = 0; c < M; c++)
		{
			cin >> board[r][c];
			if (board[r][c] >= 1 && board[r][c] <= 5)
			{
				CCTV tmp;
				tmp.r = r, tmp.c = c, tmp.type = board[r][c] - 1;
				cctv.push_back(tmp);
			}
		}
	}
	dfs(0);
	cout << answer << '\n';
}