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
	int r, c, corver, perform, used;
};

int M, A, sum;
vector<BECON> becon;

bool dist(int user, int i, pair<int, int> a_cur, pair<int, int> b_cur)
{
	if (user == 0)
		return (abs(becon[i].r - a_cur.first) + abs(becon[i].c - a_cur.second)) <= becon[i].corver;
	else if (user == 1)
		return (abs(becon[i].r - b_cur.first) + abs(becon[i].c - b_cur.second)) <= becon[i].corver;
}
// 사용자 숫자, 현재까지 다운로드한 데이터의 양
void dfs(int user, int data, pair<int, int> a_cur, pair<int, int> b_cur)
{
	if (user == 2)
	{
		sum = max(sum, data);
		return;
	}
	for (int i = 0; i < A; i++)
	{
		// 다른 사용자가 지금 ap를 사용하지 않고 있고, 범위안에 있는 경우
		if (!becon[i].used && dist(user, i, a_cur, b_cur))
		{
			becon[i].used = 1;
			dfs(user + 1, data + becon[i].perform, a_cur, b_cur);
			becon[i].used = 0;
		}
	}
	// 현재 사용자 u는 ap 접속을 하지 않고 다음 사용자로 넘어간다.
	dfs(user + 1, data, a_cur, b_cur);
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
		int time, total;
		vector<int> a, b;
		queue<pair<int, int>> q1, q2;

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
			tmp.used = 0;
			becon[i] = tmp;
		}

		time = 0, total = 0;
		q1.push(make_pair(1, 1)), q2.push(make_pair(10, 10));
		while (time <= M)
		{
			int nr, nc;
			pair<int, int> a_cur = q1.front(), b_cur = q2.front();
			q1.pop(), q2.pop();
			sum = 0;
			dfs(0, 0, a_cur, b_cur);
			for (int i = 0; i < A; i++)
			{
				if (dist(0, i, a_cur, b_cur) && dist(1, i, a_cur, b_cur))
					sum = max(sum, becon[i].perform);
			}
			total += sum;
			if (time == M)
				break;
			nr = a_cur.first + dr[a[time]], nc = a_cur.second + dc[a[time]];
			q1.push(make_pair(nr, nc));
			nr = b_cur.first + dr[b[time]], nc = b_cur.second + dc[b[time]];
			q2.push(make_pair(nr, nc));
			time++;
		}
		cout << "#" << ts << ' ' << total << '\n';
	}
}