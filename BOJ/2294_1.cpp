// 동전 2
// https://www.acmicpc.net/problem/2294
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000 + 1;
int used[MAX];
int cache[MAX];
vector <int> coin;
int N,K;

int getCoinCnt(int n)
{
	if (n == 0)
		return (0);
	else if (n < 0)
		return (MAX);
	
	if (cache[n] != -1)
		return (cache[n]);
	
	int result = getCoinCnt(n - coin[0]) + 1;
	for (int i = 1; i < coin.size(); i++)
	{
		if (n - coin[i] < 0)
			break;
		result = min(result, getCoinCnt(n - coin[i]) + 1);
	}
	cache[n] = result;
	return (result);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp <= K && !used[tmp])
		{
			used[tmp] = 1;
			coin.push_back(tmp);
		}
	}
	fill_n(cache, MAX, -1);
	sort(coin.begin(), coin.end());
	getCoinCnt(K);
	if (cache[K] >= MAX)
		cout << -1;
	else
		cout << cache[K];
}