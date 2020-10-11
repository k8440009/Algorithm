// 새로운 게임 2 - 90분
// https://www.acmicpc.net/problem/17837
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 12 + 2;
const int dr[] = { 0,0,0,-1,1 };
const int dc[] = { 0,1,-1,0,0 };

int N, K;
int state[MAX][MAX];
vector <int> board[MAX][MAX]; // 말 번호 저장
vector <int> horse;

pair <int, int> find_loc(int num)
{
	pair <int, int> loc;
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (!board[r][c].empty())
			{
				for (int i = 0; i < board[r][c].size(); i++)
				{
					if (board[r][c][i] == num)
					{
						loc.first = r, loc.second = c;
						return loc;
					}
				}
			}
		}
	}
}

int change_dir(int dir)
{
	if (dir == 1)
		return 2;
	else if (dir == 2)
		return 1;
	else if (dir == 3)
		return 4;
	else if (dir == 4)
		return 3;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			cin >> state[r][c];
	horse.resize(K + 1);
	for (int i = 1; i <= K; i++)
	{
		int r, c, dir;
		cin >> r >> c >> dir;
		board[r][c].push_back(i);
		horse[i] = dir;
	}
	
	int time = 1;
	while (time <= 1000)
	{
		for (int n = 1; n <= K; n++)
		{
			pair <int, int> loc = find_loc(n);
			vector <int> party;
			bool flag = false;

			for (int i = 0; i < board[loc.first][loc.second].size(); i++)
			{
				if (!flag && board[loc.first][loc.second][i] == n)
				{
					party.push_back(board[loc.first][loc.second][i]);
					flag = true;
				}
				else if (flag)
					party.push_back(board[loc.first][loc.second][i]);
			}
			for (int i = 0; i < party.size(); i++)
				board[loc.first][loc.second].pop_back();

			int nr = loc.first + dr[horse[n]], nc = loc.second + dc[horse[n]];
			// 파랑
			if (state[nr][nc] == 2 || nr < 1 || nr > N || nc < 1 || nc > N)
			{
				horse[n] = change_dir(horse[n]);
				nr = loc.first + dr[horse[n]], nc = loc.second + dc[horse[n]];
				if (state[nr][nc] == 2 || nr < 1 || nr > N || nc < 1 || nc > N)
				{
					for (int i = 0; i < party.size(); i++)
						board[loc.first][loc.second].push_back(party[i]);
				}
				else if (state[nr][nc] == 0)
				{
					for (int i = 0; i < party.size(); i++)
						board[nr][nc].push_back(party[i]);
				}
				else if (state[nr][nc] == 1)
				{
					for (int i = party.size() - 1; i >= 0; i--)
						board[nr][nc].push_back(party[i]);
				}
			}
			else
			{
				if (state[nr][nc] == 0)
				{
					for (int i = 0; i < party.size(); i++)
						board[nr][nc].push_back(party[i]);
				}
				else if (state[nr][nc] == 1)
				{
					for (int i = party.size() - 1; i >= 0; i--)
						board[nr][nc].push_back(party[i]);
				}
			}

			if (board[nr][nc].size() >= 4 || board[loc.first][loc.second].size() >= 4)
			{
				cout << time;
				return 0;
			}
		}
		time++;
	}
	cout << -1;
	return 0;
}