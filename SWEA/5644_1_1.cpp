// 5644. [모의 SW 역량테스트] 무선 충전
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dr[5] = {0, -1, 0, 1, 0};
const int dc[5] = {0, 0, 1, 0, -1};

struct BECON
{
	int r, c;
	int corver;
	int perform;
};

int board[12][12];
int selected[10];
int M, A;

bool dist(int s_r, int s_c, int b_r, int b_c, int range)
{
	return (abs(s_r - b_r) + abs(s_c - b_c)) <= range;
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
		fill_n(board[0], 12 * 12, 0);
		vector<int> a, b;
		vector<BECON> becon;
		cin >> M >> A;
		a.resize(M), b.resize(M), becon.resize(A);
		for (int i = 0; i < M; i++)
			cin >> a[i];
		for (int i = 0; i < M; i++)
			cin >> b[i];
		for (int i = 0; i < A; i++)
		{
			BECON tmp;
			cin >> tmp.c >> tmp.r >> tmp.corver >> tmp.perform;
			becon[i] = tmp;
		}
		// 0. 시작
		int time = 0, total = 0;
		queue<pair<int, int>> q1, q2;
		q1.push(make_pair(1, 1));
		q2.push(make_pair(10, 10));

		// while (time < 20)
		while (time <= M)
		{
			int a_charge = 0, b_charge = 0, sum = 0;
			pair<int, int> a_cur = q1.front();
			pair<int, int> b_cur = q2.front();
			q1.pop(), q2.pop();

			for (int i = 0; i < A; i++)
			{
				if (dist(a_cur.first, a_cur.second, becon[i].r, becon[i].c, becon[i].corver))
				{
					for (int j = 0; j < A; j++)
					{
						if (dist(b_cur.first, b_cur.second, becon[j].r, becon[j].c, becon[j].corver))
						{
							if (i == j)
								sum = max(sum, becon[i].perform);
							else
								sum = max(sum, becon[i].perform + becon[j].perform);
						}
						else
							sum = max(sum, becon[i].perform);
					}
				}
				else
				{
					for (int j = 0; j < A; j++)
					{
						if (dist(b_cur.first, b_cur.second, becon[j].r, becon[j].c, becon[j].corver))
							sum = max(sum, becon[j].perform);
					}
				}
			}
			total += (sum);
			if (time == M)
				break;
			int nr, nc;
			nr = a_cur.first + dr[a[time]], nc = a_cur.second + dc[a[time]];
			q1.push(make_pair(nr, nc));
			nr = b_cur.first + dr[b[time]], nc = b_cur.second + dc[b[time]];
			q2.push(make_pair(nr, nc));
			time++;
		}
		cout << "#" << ts << ' ' << total << '\n';
	}
}