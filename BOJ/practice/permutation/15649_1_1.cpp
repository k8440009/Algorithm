// N과 M (1) (next_permutaion)
// https://www.acmicpc.net/problem/15649
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	vector<int> num;
	num.resize(N);
	for (int i = 1; i <= N; i++)
		num[i - 1] = i;
	do
	{
		vector<int> v;
		v.resize(M);
		for (int i = 0; i < M; i++)
			v[i] = num[i];
		answer.push_back(v);
	} while (next_permutation(num.begin(), num.end()));

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	for (int i = 0; i < answer.size(); i++)
	{
		for (int j = 0; j < answer[i].size(); j++)
		{
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
}