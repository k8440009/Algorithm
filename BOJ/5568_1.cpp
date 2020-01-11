// 카드 놓기
// https://www.acmicpc.net/problem/5568
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int N, K;
vector<string> arr, a;
vector<bool> visited;
set<string> answer; // set을 사용하여 중복 제거
void dfs(int index)
{
	// 길이가 K가 되면 set에 넣는다.
	if (a.size() == K)
	{
		string str = "";
		for (int i = 0; i < a.size(); i++)
			str += a[i];
		answer.insert(str);
		return;
	}
	// 조합
	for (int i = 0; i < N; i++)
	{
		if (visited[i])
			continue;
		a.push_back(arr[i]);
		visited[i] = true;
		dfs(index + 1);
		a.pop_back();
		visited[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	arr.resize(N), visited.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end()); // 정렬
	dfs(0);
	cout << answer.size();
	return 0;
}
/*
	조합은
	순서가 상관없으므로
	방문 -> 체크 -> 재귀 -> 체크 해제 -> 방문 해제 순으로 코딩하자
*/