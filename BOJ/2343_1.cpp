// 기타 레슨
// https://www.acmicpc.net/problem/2343
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, answer;
vector <int> vec;

bool blue_size(int mid)
{
	int sum = 0;
	int limit = M;

	for (int i = 0; i < N; i++)
	{
		if (vec[i] > mid)
			return false;

		sum += vec[i];
		if (sum > mid)
		{
			if (limit == 1)
				return false;
			limit--;
			sum = vec[i];
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int lo = 0, hi = 0;
	long long mid = 0, sum = 0;
	cin >> N >> M;
	vec.resize(N);
	for (int i = 0 ; i < N; i++)
	{
		cin >> vec[i];
		sum += vec[i];
	}
	hi = sum;
	while (lo + 1 < hi)
	{
		mid = (lo + hi) / 2;
		if (blue_size(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi;
}