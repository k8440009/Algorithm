// 5644. [모의 SW 역량테스트] 무선 충전 2회차 : 54분
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dr[] = {0,-1,0,1,0};
const int dc[] = {0,0,1,0,-1};

struct BECON
{
	int r, c, coverage, perform;
};
int M, A, answer;
vector <int> a, b;
vector <BECON> becon;

bool dist(int b_r, int b_c, int coverage, int r, int c)
{
	if (abs(b_r - r) + abs(b_c - c) <= coverage)
		return true;
	else
		return false;
}

void solve()
{
	int a_r = 1, a_c = 1, b_r = 10, b_c = 10, time = 0;

	while (time <= M)
	{
		// 충전 확인
		vector<int> selected_a, selected_b;
		for (int i = 0; i < A; i++)
		{
			if (dist(becon[i].r, becon[i].c, becon[i].coverage, a_r, a_c))
				selected_a.push_back(i);
			if (dist(becon[i].r, becon[i].c, becon[i].coverage, b_r, b_c))
				selected_b.push_back(i);
		}
		if (selected_a.size() > 0 && selected_b.size() > 0)
		{
			int total = 0;
			for (int i = 0; i < selected_a.size(); i++)
			{
				for (int j = 0; j < selected_b.size(); j++)
				{
					if (selected_a[i] == selected_b[j])
						total = max(total, becon[selected_a[i]].perform);
					else
						total = max(total, becon[selected_a[i]].perform + becon[selected_b[j]].perform);
				}
			}
			answer += total;
		}
		else if (selected_a.size() > 0 && selected_b.size() == 0)
		{
			int total = 0;
			for (int i = 0; i < selected_a.size(); i++)
				total = max(total, becon[selected_a[i]].perform);
			answer += total;
		}
		else if (selected_a.size() == 0 && selected_b.size() > 0)
		{
			int total = 0;
			for (int i = 0; i < selected_b.size(); i++)
				total = max(total, becon[selected_b[i]].perform);
			answer += total;
		}
		if (time == M)
			break;
		a_r += dr[a[time]], a_c += dc[a[time]], b_r += dr[b[time]], b_c += dc[b[time]];
		time++;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("sample_1.txt", "r", stdin);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		cin >> M >> A;
		answer = 0;
		a.clear(), b.clear(), becon.clear();
		a.resize(M), b.resize(M), becon.resize(A);
		for (int i = 0; i < M; i++)
			cin >> a[i];
		for (int i = 0; i < M; i++)
			cin >> b[i];

		for (int i = 0; i < A; i++)
		{
			BECON tmp;
			cin >> tmp.c >> tmp.r >> tmp.coverage >> tmp.perform;
			becon[i] = tmp;
		}
		solve();
		cout << "#" << ts << ' ' << answer << '\n';
	}
}