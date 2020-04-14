// 수들의 합 2
// https://www.acmicpc.net/problem/2003
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<long long> a;
void init()
{
	cin >> N >> M;
	a.resize(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();

	int start = 0, end = 0, result = 0;
	long long sum = 0;
	while (1)
	{
		// sum이 M보다 커지면 뺴주고 start 증가
		if (sum >= M)
			sum -= a[start++];
		else if (end == N)
			break;
		// sum이 M보다 작아지면 더해주고, end증가
		else
			sum += a[end++];

		if (sum == M)
			result++;
	}
	cout << result;
	return 0;
}
/*
	참고
	https://m.blog.naver.com/kks227/220795165570
*/