// 예산
// https://www.acmicpc.net/problem/2512
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, limit, sum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vector <int> data;
	data.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> data[i];
		sum += data[i];
	}
	cin >> limit;
	sort(data.begin(), data.end());
	
	if (sum <= limit)
		cout << data[N - 1];
	else
	{
		int low, high;
		long long mid;
		low = 0, high = limit;
		if (sum)
		while (low + 1 < high)
		{
			mid = (low + high) / 2;
			sum = 0;

			for (int i = 0; i < N; i++)
				sum += data[i] > mid ? mid : data[i];
			
			if (sum <= limit)
				low = mid;
			else
				high = mid;
		}
		cout << low;
	}
}