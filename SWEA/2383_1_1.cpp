// 2383. [모의 SW 역량테스트] 점심 식사시간
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int board[12][12];
int N, answer;
bool selected[12];

vector<pair<int, int>> people;
vector<pair<int, int>> st_location;

int dist(int p_r, int p_c, int s_r, int s_c)
{
	return abs(p_r - s_r) + abs(p_c - s_c);
}

void solve()
{
	queue<int> st_one_gate, st_two_gate;
	vector<int> st_one_time, st_two_time;
	for (int i = 0; i < people.size(); i++)
	{
		int t;
		if (selected[i])
		{
			t = dist(people[i].first, people[i].second, st_location[0].first, st_location[0].second);
			st_one_time.push_back(t);
		}
		else
		{
			t = dist(people[i].first, people[i].second, st_location[1].first, st_location[1].second);
			st_two_time.push_back(t);
		}
	}
	sort(st_one_time.begin(), st_one_time.end()), sort(st_two_time.begin(), st_two_time.end());
	for (int i = 0; i < st_one_time.size(); i++)
		st_one_gate.push(st_one_time[i]);
	for (int i = 0; i < st_two_time.size(); i++)
		st_two_gate.push(st_two_time[i]);
	st_one_time.clear(), st_two_time.clear();

	int time = 0, used_1 = 0, used_2 = 0;
	int stair1_long = board[st_location[0].first][st_location[0].second], stair2_long = board[st_location[1].first][st_location[1].second];
	st_one_time.resize(3), st_two_time.resize(3);

	while (true)
	{
		if (st_one_gate.empty() && st_two_gate.empty() && used_1 == 0 && used_2 == 0)
			break;

		for (int i = 0; i < 3; i++)
		{
			if (st_one_time[i] > 0)
			{
				st_one_time[i] -= 1;
				if (st_one_time[i] == 0)
					used_1--;
			}
			if (st_two_time[i] > 0)
			{
				st_two_time[i] -= 1;
				if (st_two_time[i] == 0)
					used_2--;
			}
		}

		while (!st_one_gate.empty() && st_one_gate.front() < time && used_1 < 3)
		{
			for (int i = 0; i < 3; i++)
			{
				if (st_one_time[i] == 0)
				{
					st_one_time[i] = stair1_long;
					st_one_gate.pop();
					used_1++;
					break;
				}
			}
		}

		while (!st_two_gate.empty() && st_two_gate.front() < time && used_2 < 3)
		{
			for (int i = 0; i < 3; i++)
			{
				if (st_two_time[i] == 0)
				{
					st_two_time[i] = stair2_long;
					st_two_gate.pop();
					used_2++;
					break;
				}
			}
		}

		time++;
	}
	answer = min(answer, time - 1);
}

void dfs(int curr, int prev, int cnt)
{
	if (curr == cnt)
	{
		solve();
		return;
	}
	for (int i = 0; i < people.size(); i++)
	{
		if (selected[i] || prev > i)
			continue;
		selected[i] = true;
		dfs(curr + 1, i, cnt);
		selected[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		answer = 987654321;
		cin >> N;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				cin >> board[r][c];
				if (board[r][c] == 1)
					people.push_back(make_pair(r, c));
				else if (board[r][c] > 1)
					st_location.push_back(make_pair(r, c));
			}
		}
		for (int i = 0; i <= people.size(); i++)
			dfs(0, 0, i);
		cout << "#" << ts << ' ' << answer << '\n';
		people.clear(), st_location.clear();
	}
}