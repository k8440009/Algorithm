// N과 M (2) - 조합
// https://www.acmicpc.net/problem/15650
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 8 + 1;
int N, M;
bool visited[MAX];

vector<vector<int>> answer;
vector<int> a;

void dfs(int curr, int cnt)
{
	if (cnt == M)
	{
		answer.push_back(a);
		return;
	}

	for (int next = curr + 1; next <= N; next++)
	{
		a.push_back(next);
		visited[curr] = true;
		dfs(next, cnt + 1);
		visited[curr] = false;
		a.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		a.push_back(i);
		visited[i] = true;
		dfs(i, 1);
		visited[i] = false;
		a.pop_back();
	}

	for (int i = 0; i < answer.size(); i++)
	{
		for (int j = 0; j < answer[i].size(); j++)
			cout << answer[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}