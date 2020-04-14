// 수들의 합 2
// https://www.acmicpc.net/problem/2003
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	vector<int> num;
	num.resize(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int start = 0, end = 0;
	int total = 0, answer = 0;
	while (start <= end)
	{
		if (total < M)
		{
			total += num[end];
			end++;
		}
		else if (total > M)
		{
			total -= num[start];
			start++;
		}
		else
		{
			answer++;
			total -= num[start];
			start++;
		}

		if (start > N || end > N)
			break;
	}

	cout << answer << '\n';
}

/*
	참고
	https://m.blog.naver.com/kks227/220795165570
*/