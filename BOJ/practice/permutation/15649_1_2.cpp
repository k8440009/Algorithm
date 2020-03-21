// N과 M (1) 순열, (next_permutation + set)
// https://www.acmicpc.net/problem/15649
#include <iostream>
#include <vector>
#include <set>
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
	set<vector<int>> answer;
	do
	{
		vector<int> v;
		v.resize(M);
		for (int i = 0; i < M; i++)
			v[i] = num[i];
		answer.insert(v);
	} while (next_permutation(num.begin(), num.end()));

	set<vector<int>>::iterator iter;

	for (iter = answer.begin(); iter != answer.end(); iter++)
	{
		for (int i = 0; i < M; i++)
			cout << (*iter)[i] << ' ';
		cout << '\n';
	}
}