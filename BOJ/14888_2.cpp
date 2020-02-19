// 연산자 끼워넣기
// https://www.acmicpc.net/problem/14888
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000005;
int N;
int answer_MIN = INF;
int answer_MAX = -INF;
int opr[4];
vector<int> num;

void dfs(int curr, int plus, int minus, int mul, int div, int sum)
{
	if (curr == N)
	{
		if (sum > answer_MAX)
			answer_MAX = sum;
		if (sum < answer_MIN)
			answer_MIN = sum;
		return;
	}

	if (plus > 0)
		dfs(curr + 1, plus - 1, minus, mul, div, sum + num[curr]);
	if (minus > 0)
		dfs(curr + 1, plus, minus - 1, mul, div, sum - num[curr]);
	if (mul > 0)
		dfs(curr + 1, plus, minus, mul - 1, div, sum * num[curr]);
	if (div > 0)
		dfs(curr + 1, plus, minus, mul, div - 1, sum / num[curr]);
}

void print()
{
	cout << answer_MAX << '\n';
	cout << answer_MIN << '\n';
}

void solve()
{
	dfs(1, opr[0], opr[1], opr[2], opr[3], num[0]);
}

void init()
{
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> opr[i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	solve();
	print();
}