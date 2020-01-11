// 다리 놓기
// https://www.acmicpc.net/problem/1010
#include <iostream>
using namespace std;
const int MAX = 30 + 1;
int visited[MAX][MAX];
int N, M;
int combination(int n, int k)
{
	if (k == 0 || n == k)
		return 1;
	int &cache = visited[n][k];
	if (cache != -1)
		return cache;
	return cache = combination(n - 1, k - 1) + combination(n - 1, k);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill_n(visited[0], MAX * MAX, -1);

	int tc;
	cin >> tc;
	while (tc--)
	{
		// M개 다리 중에 N개를 선택한다.
		cin >> N >> M;
		cout << combination(M, N) << '\n';
	}
	return 0;
}
