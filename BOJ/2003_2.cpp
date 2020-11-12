// 수들의 합2
// https://www.acmicpc.net/problem/2003
#include <iostream>
#include <vector>
using namespace std;

int N,M, answer;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin >> N >> M;
	vector <int> v;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	int start = -1, end = -1;
	long long sum = 0;
	while (end < N && start <= end)
	{
		if (sum > M)
		{
			start++;
			sum -= v[start];
		}
		else if (sum == M)
		{
			answer++;
			start++;
			sum -= v[start];
		}
		else
		{
			end++;
			sum += v[end];
		}
	}
	cout << answer;
}