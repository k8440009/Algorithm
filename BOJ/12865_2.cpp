// 평범한 배낭
// https://www.acmicpc.net/problem/12865
#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector <pair<int,int> > backPack;
int cache[101][100000 + 1];
int answer;

int main()
{
	cin >> N >> K;
	backPack.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int a,b;
		cin >> a >> b;
		backPack[i].first = a;
		backPack[i].second = b;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			int weight = backPack[i].first;
			int value = backPack[i].second;

			cache[i][j] = cache[i - 1][j];
			if (j < weight)
				continue;
			cache[i][j] = max(cache[i][j], cache[i - 1][j - weight] + value);
			answer = max(answer, cache[i][j]);
		}
	}
	cout << answer;
}
