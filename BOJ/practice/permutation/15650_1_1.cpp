// N과 M (2) 조합, next_permutaion
// https://www.acmicpc.net/problem/15650
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<int> num, pick;
vector<vector<int>> answer;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	num.resize(N);
	for (int i = 0; i < N; i++)
		num[i] = i + 1;
	for (int i = 0; i < N - M; i++)
		pick.push_back(0);
	for (int i = 0; i < M; i++)
		pick.push_back(1);

	sort(pick.begin(), pick.end());

	do
	{
		vector<int> v;
		for (int i = 0; i < pick.size(); i++)
			if (pick[i] == 1)
				v.push_back(num[i]);
		answer.push_back(v);
	} while (next_permutation(pick.begin(), pick.end()));

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	for (int i = 0; i < answer.size(); i++)
	{
		for (int j = 0; j < answer[i].size(); j++)
			cout << answer[i][j] << ' ';
		cout << '\n';
	}
}