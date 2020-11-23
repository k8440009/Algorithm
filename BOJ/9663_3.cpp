// N-Queen
// https://www.acmicpc.net/problem/9663
#include <iostream>
using namespace std;

const int MAX = 14 + 1;

int row[100];
int N, answer;

bool promising(int q)
{
	for (int i = 1; i < q; i++)
	{
		if (row[q] == row[i]
			|| abs(row[q] - row[i]) == abs(q - i))
		return false;
	}
	return true;
}
void dfs(int q)
{
	if (!promising(q))
		return;
	if (q == N)
	{
		answer++;
		return ;
	}
	for (int i = 1; i <= N; i++)
	{
		//row[q + i] : 행, i : 열
		row[q + 1] = i;
		dfs(q + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	dfs(0);
	cout << answer;
}