// N과 M (4) - 중복 조합
// https://www.acmicpc.net/problem/15652
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAX = 8 + 1;
int N, M;
set<vector<int>> answer;
bool visited[MAX];
vector<int> a;
void dfs(int curr, int cnt)
{
	if (cnt == M)
	{
		answer.insert(a);
		return;
	}

	for (int next = curr; next <= N; next++)
	{
		a.push_back(next);
		dfs(next, cnt + 1);
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
		dfs(i, 1);
		a.pop_back();
	}

	for (auto &v : answer)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		cout << '\n';
	}
	return 0;
}